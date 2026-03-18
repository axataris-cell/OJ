#include <bits/stdc++.h>
#define ll long long
#define el '\n'

using namespace std;

void testcase() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int m; cin >> m;
    while (m--) {
        string s; cin >> s;

        if ((int)s.size() != n) {
            cout << "NO" << el;
            continue;
        }

        unordered_map<int, char> mp_num;
        int mp_char[26];
        memset(mp_char, -1, sizeof(mp_char));

        bool ok = true;

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            int val = a[i];

            // char -> number
            if (mp_char[c] == -1) {
                mp_char[c] = val;
            } else if (mp_char[c] != val) {
                ok = false;
                break;
            }

            // number -> char
            if (!mp_num.count(val)) {
                mp_num[val] = c;
            } else if (mp_num[val] != c) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << el;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) testcase();

    return 0;
}