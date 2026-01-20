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
	int n, q; cin >> n >> q;
	vector<ll> a(n + 1), p(n + 1);
	p[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i] = p[i - 1] + a[i];
	}
	
	while (q--) {
		int l, r; cin >> l >> r;
		cout << p[r] - p[l - 1] << el;
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
