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

ll powf(ll n, ll k) {
	if (k < 0) return 0; 
	if (k == 0) return 1;
	ll res = 1;
	for (int i = 1; i <= k; i++) {
		res *= n;
	}
	return res;
}

void testcase() {
	ll n; cin >> n;
	ll k; cin >> k;
	ll t = n;
	ll res = 0;
	ll cur = 18;
	ll cnt = 0;
	vector<int> bit(19, 0);
	while (cur >= 0) {
//		cerr << cur << ' ';
		ll power = powf(3, cur);
		if (t >= power) {
			ll d = t / power;
			res += d * (powf(3, cur + 1) + cur * powf(3, cur - 1));
			cnt += d;
			bit[cur] = d;
			t = t % (ll)powf(3, cur);
		}
		--cur;
	}
	
//	for (int i = 0; i <= 18; i++) cerr << bit[i] << ' ';
//	cerr << el;
	
	if (cnt > k) {
		cout << -1 << el;
		return;
	}
	if (cnt == k) {
		cout << res << el;
		return;
	}
	
	k -= cnt;
	for (int i = 18; i >= 1; i--) {
		if (!bit[i]) continue;
		ll maxi = k / 2;
//		cerr << i << ':' << ' ';
//		cerr << "DB1: " << maxi << ' ' << k << ' ' << bit[i] << ' ';
		if (maxi >= bit[i]) {
			k = k - 2 * bit[i];
			bit[i - 1] += 3 * bit[i];
			bit[i] = 0;
		} else {
			bit[i] -= maxi;
			bit[i - 1] += maxi * 3;
//			cerr << el;
			break;
		}
//		cerr << "DB2: " << k << ' ' << bit[i] << ' ' << el;
	}
	
//	for (int i = 0; i <= 18; i++) cerr << bit[i] << ' ';
//	cerr << el;
	
	res = 0;
	for (ll i = 0; i <= 18; i++) {
		if (bit[i]) {
			res += bit[i] * (powf(3, i + 1) + i * powf(3, i - 1));
		}
	}
	
	cout << res << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
