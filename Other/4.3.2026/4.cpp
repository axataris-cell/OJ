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

    vector<ll> h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    
    ll pref = 0;
    umap<ll, ll> cnt;

    cnt[0] = 1;

    ll res = 0;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) pref += h[i];
        else pref -= h[i];

        if (cnt.count(pref)) {
            res += cnt[pref];
        }

        cnt[pref]++;
    }

    cout << res << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
