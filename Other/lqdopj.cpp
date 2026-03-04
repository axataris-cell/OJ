#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 2e9
#define LINF 4e18

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

#define int long long

void testcase() {
	ll n, k; cin >> n >> k;
	vector<ll> a(n + 1);
	map<int, bool> mp;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]] = true;
	}
	
	vector<int> AC;
	for (int i = 1; i <= n; i++) {
		if (a[i] % k == 0) {
			AC.push_back(i);
		}
	}
	
//	for (auto x : AC) cout << x << ' ';
//	cout << el;
	if (mp[k]) {
		cout << "YES" << el;
		return;
	}
	
	int s = AC.size();
	for (int i = 1; i < s; i++) {
		for (int j = 0; j < i; j++) {
//			cout << AC[i] << ' ' << AC[i] << ' ' << __gcd(a[AC[i]], a[AC[j]]) << el;
			if (1 == __gcd(a[AC[i]] / k, a[AC[j]] / k)) {
				cout << "YES" << el;
				return;
			}
		}
	}
	
	cout << "NO" << el;
}
/*
1
5 4
24 2 60 6 40
*/

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
