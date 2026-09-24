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

void testcase() {
	ll n; cin >> n;
	ll cur = 10;
	vector<ll> res;
	bool exist = false;
	while (cur <= n && cur <= 1e18) {
		if (n % (cur + 1) == 0) {
			exist = true;
			res.push_back(n / (cur + 1));
		}
		cur *= 10;
	}
	
	if (!exist) {
		cout << 0 << el;
		return;
	}
	
	sort(res.begin(), res.end());
	
	cout << res.size() << el;
	for (auto x : res) {
		cout << x << ' ';
	}
	cout << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
