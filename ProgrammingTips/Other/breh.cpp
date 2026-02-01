#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();	

    vector<int> p(n, 0);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }

    int len = n - p[n - 1];
    bool ok = true;

    for (int i = len; i < n; i++) {
        if (s[i] != s[i - len]) {
            ok = false;
            break;
        }
    }

    if (ok)
        cout << s.substr(0, len);
    else
        cout << s;
}
