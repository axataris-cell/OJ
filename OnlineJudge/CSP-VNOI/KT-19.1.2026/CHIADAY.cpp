#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

#define FILENAME "DARR"

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
   int n, k;
    cin >> n >> k;

    vector<ll> a(n + 1), f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    if (k == 1) {
        cout << f[n];
        return;
    }

    vector<ll> cuts;
    for (int i = 1; i < n; i++) {
        cuts.push_back(f[i]);
    }

    sort(cuts.begin(), cuts.end());

    ll res = f[n];
    for (int i = 0; i < k - 1; i++) {
        res += f[n] - cuts[i];
    }

    cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
