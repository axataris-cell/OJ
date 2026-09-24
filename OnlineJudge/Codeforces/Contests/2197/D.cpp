#include <bits/stdc++.h>
#include <chrono>

#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 1e9
#define LINF 1e18

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
	int n;
	cin >> n;

	vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	ll ans = 0;
	int B = sqrt(n);

	for (int i = 1; i <= n; i++) {
		ll ai = a[i];
		if (ai > n) continue;
		for (ll k = 1; k <= B; k++) {
			ll j = i + ai * k;
			if (j > n) break;
			if (a[j] == k) {
				ans++;
			}
		}
	}

	for (int j = 1; j <= n; j++) {
		ll aj = a[j];
		if (aj > n) continue;
		for (ll k = 1; k <= B; k++) {
			ll i = j - aj * k;
			if (i < 1) break;
			if (a[i] == k && a[j] > B) {
				ans++;
			}
		}
	}

	cout << ans << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t;
	cin >> t;
	while (t--) testcase();

	return 0;
}
