#include <bits/stdc++.h>
#include <chrono>

#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

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

bool check(ll d, ll n, vector<pll> &seg) {
	ll last = -(ll)4e18;
	ll cnt = 0;

	for (auto [a, b] : seg) {
		ll pos = max(a, last + d);
		if (pos > b) continue;

		ll add = (b - pos) / d + 1;
		cnt += add;
		last = pos + (add - 1) * d;

		if (cnt >= n) return true;
	}
	return cnt >= n;
}

void testcase() {
	ll n, m;
	cin >> n >> m;

	vector<pll> seg(m);
	for (int i = 0; i < m; i++) cin >> seg[i].first >> seg[i].second;

	sort(seg.begin(), seg.end());

	vector<pll> merged;
	for (auto [a, b] : seg) {
		if (merged.empty() || merged.back().second + 1 < a) merged.push_back({a, b});
		else merged.back().second = max(merged.back().second, b);
	}
	seg = merged;

	ll lo = 1, hi = (ll)1e18, ans = 1;

	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (check(mid, n, seg)) {
			ans = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}

	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1;
	while (t--) testcase();

	return 0;
}
