#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	if (FILE *f = fopen(FILENAME".INP", "r")) {
		fclose(f);
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
}

ll powf(ll n, int i) {
	if (i == 0) return 1;
	ll res = 1;
	for (int j = 1; j <= i; j++) {
		res *= n;
	}
	return res;
}

void testcase() {
	ll k; cin >> k;
	ll cur = 9;
	ll res = 0;
	ll stat = 0;
	ll brih = 45; // 1 -> 9
	for (int i = 1; i <= 15; i++) { // số chữ số.
		if (k >= i * cur) {
			res += stat * 9 + powf(10, i - 1) * brih;
			stat = stat * 9 + powf(10, i - 1) * brih;
			k -= i * cur;
		} else {
			// còn lại k chữ số cần lấy và bắt đầu từ số 1ei
			ll num = k / i;
			ll start = powf(10, i - 1);
			ll end = start + num;
			
			
			
			break;
		}
	}
	
	cout << res << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
