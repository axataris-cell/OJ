import os
import shutil
import re
import time
from curl_cffi import requests
from bs4 import BeautifulSoup

# Directory paths configuration
PENDING_DIR = "Pending"
OUT_DIR = "."  # Outer folder (same level as the running script)

# Map file extensions to Codeforces language IDs
LANG_MAP = {
    ".cpp": "54",  # GNU G++17 7.3.0
    ".cc": "54",
    ".c": "43",    # GCC C11
    ".py": "31",   # Python 3
    ".java": "36"  # Java 11
}

def get_cookie_jar_path():
    return r"C:\Users\Admin\AppData\Local\online-judge-tools\online-judge-tools\cookie.jar"

def load_cookies_into_session(session, cookie_path):
    if not os.path.exists(cookie_path):
        print(f"[Warning] cookie.jar not found at {cookie_path}")
        return

    with open(cookie_path, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()

    for line in content.splitlines():
        if line.startswith('#') or not line.strip():
            continue
        parts = line.strip().split('\t')
        if len(parts) >= 7:
            domain, _, path, _, _, name, value = parts[:7]
            session.cookies.set(name, value, domain=domain, path=path)
    print("[Info] Cookies loaded successfully into session.")

def parse_problem_info(filename):
    match = re.match(r"^(\d+)([A-Z]\d*)\.(cpp|cc|c|py|java)$", filename, re.IGNORECASE)
    if match:
        return match.group(1), match.group(2).upper(), match.group(3).lower()
    return None, None, None

def main():
    if not os.path.exists(PENDING_DIR):
        print(f"[Error] Directory '{PENDING_DIR}' does not exist!")
        return

    files = sorted([f for f in os.listdir(PENDING_DIR) if os.path.isfile(os.path.join(PENDING_DIR, f))])
    target_files = files[:3]
    
    if not target_files:
        print("The 'Pending' directory is currently empty.")
        return

    print(f"-> Found {len(target_files)} files to submit:")
    for f in target_files:
        print(f"   + {f}")
    print("-" * 40)

    # Use curl_cffi session with chrome impersonation to bypass Cloudflare 403
    session = requests.Session(impersonate="chrome")
    cookie_path = get_cookie_jar_path()
    load_cookies_into_session(session, cookie_path)

    success_count = 0
    for filename in target_files:
        file_path = os.path.join(PENDING_DIR, filename)
        contest_id, problem, ext = parse_problem_info(filename)
        
        if not contest_id or not problem:
            print(f"[Skipped] Filename '{filename}' does not match standard format (Example: 1472A.cpp)")
            continue

        lang_id = LANG_MAP.get("." + ext, "54")
        problem_url = f"https://codeforces.com/contest/{contest_id}/problem/{problem}"
        submit_url = f"https://codeforces.com/contest/{contest_id}/submit"

        print(f"Submitting '{filename}' to contest {contest_id}, problem {problem}...")

        try:
            # Step 1: GET problem page to fetch csrf_token
            resp = session.get(problem_url)
            if resp.status_code != 200:
                print(f"[Failed] Could not access problem page (Status code: {resp.status_code})")
                break

            soup = BeautifulSoup(resp.text, 'html.parser')
            csrf_token_input = soup.find('input', {'name': 'csrf_token'})
            if not csrf_token_input:
                print("[Failed] Could not find CSRF token. Please check if your login cookies are valid.")
                break
            
            csrf_token = csrf_token_input['value']

            # Read source code content
            with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                source_code = f.read()

            # Step 2: POST submission to Codeforces
            payload = {
                'csrf_token': csrf_token,
                'action': 'submitSolutionForm',
                'submittedProblemIndex': problem,
                'programTypeId': lang_id,
                'source': source_code,
                'tabSize': '4'
            }

            sub_resp = session.post(submit_url, data=payload)
            
            if sub_resp.status_code == 200:
                soup_sub = BeautifulSoup(sub_resp.text, 'html.parser')
                error_span = soup_sub.find('span', class_='error')
                if error_span:
                    print(f"[Failed] Submission error: {error_span.text.strip()}")
                    break
                
                print(f"[Success] Successfully submitted {filename}!")
                
                dest_path = os.path.join(OUT_DIR, filename)
                if os.path.exists(dest_path):
                    base, ext_s = os.path.splitext(filename)
                    dest_path = os.path.join(OUT_DIR, f"{base}_submitted{ext_s}")
                
                shutil.move(file_path, dest_path)
                print(f"-> Moved file to: {dest_path}\n")
                success_count += 1
            else:
                print(f"[Failed] Submission failed with status code {sub_resp.status_code}")
                break

        except Exception as e:
            print(f"[Error] Exception occurred while submitting {filename}: {e}")
            break

        time.sleep(3)

    print(f"=== Done! Successfully processed {success_count}/{len(target_files)} files. ===")

if __name__ == "__main__":
    main()