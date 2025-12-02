#include <bits/stdc++.h>
using namespace std;

bool cmpChar(char a, char b) {
    char la = tolower(a);
    char lb = tolower(b);

    if (la != lb) return la < lb;
    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        sort(s.begin(), s.end(), cmpChar);

        do {
            cout << s << "\n";
        } while (next_permutation(s.begin(), s.end(), cmpChar));
    }
}
