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
	int n, k, m; cin >> n >> k >> m;
	vector<int> a(n + 1), b(m + 1), f(m + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		++b[a[i]];
	}
	f[0] = 0;
	for (int i = 1; i <= m; i++) {
		f[i] = f[i - 1] + b[i];
	}
	int res = INT_MAX;
	for (int i = k; i <= m; i++) {
		res = min(res, f[i] - f[i - k]);
	}
	cout << res;
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
