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
	int n; cin >> n;
	string s; cin >> s;
	
	vector<bool> vis(n + 1, 0);
	
	for (int i = 1; i <= n - 2; i++) {
		int cnt0 = 0, cnt1 = 0;
		for (int j = i; j <= i + 2; j++) {
			if (s[j - 1] == '0') ++cnt0;
			else ++cnt1;
		}
		if (cnt0 >= 2) continue;
		if (cnt0 == 1 && (s[i] == '0' || vis[i])) {
			vis[i] = vis[i + 1] = vis[i + 2] = true;
		}
		if (cnt0 == 0) vis[i] = vis[i + 1] = vis[i + 2] = true;
	}
	vector<int> seg;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			if (cnt != 0) seg.push_back(cnt);
			cnt = 0;
		} else ++cnt;
	}
	if (cnt != 0) seg.push_back(cnt);
	
	for (int i = 1; i <= n; i++) cout << vis[i] << ' ';
	cout << el;
	for (auto x : seg) cout << x << ' ';
	cout << el;

//	int mn = 0, mx = 0;
//	for (auto x : seg) {
//		mx += x;
//		mn += (x + 1) / 2;
//	}
//	
//	cout << mn << ' ' << mx << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
