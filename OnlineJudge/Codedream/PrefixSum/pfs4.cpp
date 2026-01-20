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

void testcase() {
	int n, k, q; 
	cin >> n >> k >> q;

	vector<ll> a(n + 1), f(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = f[i - 1] + a[i];
	}

	vector<ll> g(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		g[i] = g[i - 1] + a[i] * i;
	}

	while (q--) {
		int w; cin >> w;

		ll res = f[n];

		int l = max(1, w - k + 1);
		int r = min(n, w + k - 1);

		if (l <= w - 1) {
			res += (g[w - 1] - g[l - 1]) + (ll)(k - w - 1) * (f[w - 1] - f[l - 1]);
		}

		if (w + 1 <= r) {
			res += (ll)(k + w - 1) * (f[r] - f[w]) - (g[r] - g[w]);
		}

		res += (ll)(k - 1) * a[w];

		cout << res << el;
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
