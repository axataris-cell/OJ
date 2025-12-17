#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
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
vector<pll> a;

int bsAdd(pll x) {
	ll res = -1;
	ll l = 0, r = a.size();
	while (l <= r) {
		ll m = (r + l) / 2;
		if (a[m].second > x.first) {
			if (a[m].first > x.second - 1) res = m;
			r = m - 1;
		} else if (a[m].second <= x.first) {
			l = m + 1;
		}
	}
	return res;
}

void testcase() {
	int m; cin >> m;
	while (m--) {
		string s; cin >> s;
		if (s == "ADD") {
			pair<ll, ll> x;
			cin >> x.first >> x.second;
			if (a.empty()) {
				cout << "YES" << el;
				a.push_back({x.first, x.second - 1});
			} else {
				if (bsAdd(x) != -1) {
					a.insert(a.begin() + bsAdd(x), x);
					cout << "YES" << el;
				} else {
					cout << "NO" << el;
				}
			}
		} else if (s == "DEL") {
			
		} else if (s == "NEXT") {
			
		} else if (s == "GAP") {
			
		}
	}
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
