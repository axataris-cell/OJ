#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<string> dict;
    string line, word;

    while (getline(cin, line)) {
        string cur = "";
        for (char c : line) {
            if (isalpha(c))
                cur += tolower(c);
            else {
                if (!cur.empty()) {
                    dict.insert(cur);
                    cur.clear();
                }
            }
        }
        if (!cur.empty()) dict.insert(cur);
    }

    for (auto &w : dict) {
        cout << w << "\n";
    }

    return 0;
}
