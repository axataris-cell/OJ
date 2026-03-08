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

#define int long long

void testcase() {
	int n, k; cin >> n >> k;
	vector<int> a(n + 1, 0);
	map<int, int> mp;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		++mp[a[i]];
	}
	int mex = 0;
	int mx2 = -1;
	for (int i = 0; i <= n; i++) {
		if (mp[i] == 0) {
			mex = i;
			break;
		}
	}
	
	int cnt = 0;
	int res = 0;
	for (int i = 0; i < mex; i++) {
		if (mp[i] > 1) {
			mx2 = i;
			break;
		} else {
			res += i;
			++cnt;
		}
	}
	
	int remain = 0;
	--k;
	for (int i = 1; i <= n; i++) {
		if (a[i] < mex) {
			if (mp[a[i]] > 1) {
				a[i] = mex;
			}
		} else {
			a[i] = mex;
			++remain;
		}
	}
	
//	cerr << cnt << ' ' << res << ' ' << mx2 << el;
	
	if (k == 0) {
		int r = 0;
		for (int i = 1; i <= n; i++) r += a[i];
		cout << r << el;
		return;
	}
	
	// khong ton tai mx2: tat ca deu ve mex sau thao tac 1.
	if (mx2 == -1) {
		if (remain <= 1) {
			if (remain == 0) --mex;
			int r = 0;
			for (int i = 1; i <= mex; i++) {
				r += i;
			}
			cout << r << el;
		} else {
			if (k % 2) cout << res + (n - cnt) * (mex + 1) << el;
			else cout << res + (n - cnt) * mex << el;
		}
		
		return;
	}
	
//	cerr << mx2 << ' ' << k << el;
	// ton tai mx2: ve mx2 sau 2 thao tac dau
	if (k % 2) {
		cout << res + (n - cnt) * mx2 << el;
	} else {
		cout << res + (n - cnt) * (mx2 + 1) << el;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
