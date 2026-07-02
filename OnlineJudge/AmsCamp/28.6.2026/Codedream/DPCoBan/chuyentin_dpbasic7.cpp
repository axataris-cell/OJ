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

void testcase() {
	int n; cin >> n;

    vector<pair<int,int>> lamp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> lamp[i].first >> lamp[i].second;
    }

    sort(lamp.begin() + 1, lamp.end());

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = lamp[i].first;
        b[i] = lamp[i].second;
    }

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int left = a[i] - b[i];
        int j = lower_bound(a.begin() + 1, a.begin() + i, left) - a.begin();

        dp[i] = (i - j) + (j > 1 ? dp[j - 1] : 0);
    }

    int ans = n;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dp[i] + (n - i));
    }

    cout << min(ans, n);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
