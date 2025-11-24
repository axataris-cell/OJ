#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
    freopen("", "r", stdin);
    freopen("", "w", stdout);
}

void testcase() {
    ll a, b; cin >> a >> b;
    cout << gcd(a, b) << ' ' << (a * b) / gcd(a, b);
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
