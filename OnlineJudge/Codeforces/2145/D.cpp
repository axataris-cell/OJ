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
    int n, k;
    cin >> n >> k;

    int maxk = n * (n - 1) / 2;

    vector<vector<bool>> dp(n + 1, vector<bool>(maxk + 1, false));
    vector<vector<int>> p(n + 1, vector<int>(maxk + 1, -1));

    dp[0][0] = true;

    for (int j = 0; j < n; j++) {
        for (int x = 0; x <= maxk; x++) {
            for (int y = 1; y <= n - j; y++) {
                if (!dp[j][x]) continue;

                int add = y * (y - 1) / 2;
                if (x + add > maxk) continue;

                dp[j + y][x + add] = true;
                p[j + y][x + add] = y;
            }
        }
    }

    k = maxk - k;

    if (dp[n][k]) {
        vector<int> ans;
        int cur = n;
        int curk = k;

        while (cur != 0) {
            int y = p[cur][curk];
            ans.push_back(y);
            curk -= y * (y - 1) / 2;
            cur -= y;
        }

        vector<int> res;
        int curv = n + 1;

        for (int y : ans) {
            for (int x = curv - y; x < curv; x++) {
                res.push_back(x);
            }
            curv -= y;
        }

        for (int x : res) cout << x << " ";
        cout << el;
    } else {
        cout << 0 << el;
    }
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
