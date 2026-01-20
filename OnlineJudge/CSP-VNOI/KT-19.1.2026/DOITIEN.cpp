#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

#define FILENAME "CHANGE"

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
	const int INF = INT_MAX;
    int s, n; cin >> s >> n;

    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int smx = s + mx;

    vector<int> dp1(smx + 1, INF);
    dp1[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int x = a[i]; x <= smx; x++) {
            dp1[x] = min(dp1[x], dp1[x - a[i]] + 1);
        }
    }

    vector<int> dp2(mx + 1, INF);
    dp2[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int y = a[i]; y <= mx; y++) {
            dp2[y] = min(dp2[y], dp2[y - a[i]] + 1);
        }
    }

    int ans = INF;
    for (int x = s; x <= smx; x++) {
        if (dp1[x] == INF) continue;
        int change = x - s;
        if (dp2[change] == INF) continue;
        ans = min(ans, dp1[x] + dp2[change]);
    }

    cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
