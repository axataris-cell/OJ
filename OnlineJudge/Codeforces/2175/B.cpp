#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

const int BASE = 1 << 17;
const int BASE2 = 1 << 18;

void testcase() {
    int n, l, r; cin >> n >> l >> r;
    vector<int> P(n+1, 0);
    for (int i = 1; i <= l-1; ++i) P[i] = i;
    for (int i = l; i <= r-1; ++i) P[i] = BASE + i;
    P[r] = P[l-1];
    for (int i = r+1; i <= n; ++i) P[i] = BASE2 + i;
    vector<int> a(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        a[i] = P[i] ^ P[i-1];
        if (a[i] == 0) {
            a[i] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << ' ';
        cout << a[i];
    }
    cout << el;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
