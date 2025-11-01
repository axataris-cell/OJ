#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
    freopen("", "r", stdin);
    freopen("", "w", stdout);
}

int F['z' + 5] = {};
void testcase() {
    string s; cin >> s;
    int odd = 0;
    for (char c : s) ++F[(int)c]; 
    for (int i = 'a'; i <= 'z'; i++) {
        if (F[i] & 1) ++odd;
    }
    if (odd == 0) cout << 0;
    else cout << odd - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //file();

    ll t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}
