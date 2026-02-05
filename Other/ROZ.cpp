#include <bits/stdc++.h>
using namespace std;

string rand_name(int len = 6) {
    static const string chars =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    string s;
    for (int i = 0; i < len; i++)
        s += chars[rng() % chars.size()];
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Các keyword muốn làm rối
    vector<string> keywords = {
        "int", "long", "long long", "vector",
        "if", "for", "while", "return",
        "cin", "cout"
    };

    // Đọc toàn bộ code gốc
    string code, line;
    while (getline(cin, line)) {
        code += line + "\n";
    }

    // Sinh macro
    unordered_map<string, string> mp;
    for (auto &k : keywords) {
        mp[k] = rand_name();
    }

    // In macro ra trước
    cout << "#include <bits/stdc++.h>\nusing namespace std;\n\n";
    for (auto &[k, v] : mp) {
        cout << "#define " << v << " " << k << "\n";
    }
    cout << "\n";

    // Thay keyword trong code
    for (int i = 0; i < (int)code.size(); ) {
        bool replaced = false;
        for (auto &[k, v] : mp) {
            if (code.substr(i, k.size()) == k &&
                (i == 0 || !isalnum(code[i - 1])) &&
                (i + k.size() >= code.size() || !isalnum(code[i + k.size()]))) {
                cout << v;
                i += k.size();
                replaced = true;
                break;
            }
        }
        if (!replaced) {
            cout << code[i++];
        }
    }
}
