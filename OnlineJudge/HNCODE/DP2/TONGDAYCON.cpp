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
    int n, S;
    cin >> n >> S;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<bool> dp(S + 1, false);
    dp[0] = true;

    for (int x : a) {
        for (int v = S; v >= x; v--) {
            if (dp[v - x]) dp[v] = true;
        }
    }

    cout << (dp[S] ? "YES" : "NO");
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
