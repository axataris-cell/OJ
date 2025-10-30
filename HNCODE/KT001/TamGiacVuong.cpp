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
    ll n; cin >> n;
    if (floor(sqrt(2*n))*ceil(sqrt(2*n)) == 2*n) cout << "YES";
    else cout << "NO";
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
