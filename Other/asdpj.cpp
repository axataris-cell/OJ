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
#define int long long

void pro(vector<vector<int>> &pre, vector<pii> &s, int k, int MOD) {
	pre[k][1] = s[k].first % MOD;
	for (int i = 2; i <= 35; i++) {
		pre[k][i] = ((pre[k][i - 1] % MOD) * s[k].first % MOD) % MOD;
	}
}

struct dat{
	int x1, x2, x3, x4; // so lan dung
};

void testcase() {
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	
	vector<pii> s(5, {1, 0}); // xi - yi
	map<int, vector<dat>> mpa;
	
	for (int i = 1; i <= n; i++) {
		cin >> s[i].first >> s[i].second;
	}
	
	vector<vector<int>> pre(5, vector<int>(36, 1));
	
	for (int i = 1; i <= n; i++) {
		pro(pre, s, i, c);
	}
	
	for (int i1 = 0; i1 <= s[1].second; i1++) {
		for (int i2 = 0; i2 <= s[2].second; i2++) {
			for (int i3 = 0; i3 <= s[3].second; i3++) {
				for (int i4 = 0; i4 <= s[4].second; i4++) {
					int na = ((((pre[1][i1] % c) * pre[2][i2] % c) * pre[3][i3] % c) * pre[4][i4] % c) * a % c;
					mpa[na].push_back({i1, i2, i3, i4});
				}
			}
		}
	}
	for (int i1 = 0; i1 <= s[1].second; i1++) {
		for (int i2 = 0; i2 <= s[2].second; i2++) {
			for (int i3 = 0; i3 <= s[3].second; i3++) {
				for (int i4 = 0; i4 <= s[4].second; i4++) {
					int nb = ((((pre[1][i1] % c) * pre[2][i2] % c) * pre[3][i3] % c) * pre[4][i4] % c) * b % c;
					if (mpa.count((c - nb) % c)) {
						for (auto &k : mpa[(c - nb) % c]) {
							if (k.x1 + i1 <= s[1].second && 
								k.x2 + i2 <= s[2].second &&
								k.x3 + i3 <= s[3].second &&
								k.x4 + i4 <= s[4].second) {
									cout << "YES" << el;
									return;
							}
						}
					}
				}
			}
		}
	}
	cout << "NO" << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
