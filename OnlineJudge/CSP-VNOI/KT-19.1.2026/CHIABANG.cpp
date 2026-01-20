#include <bits/stdc++.h>
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

const int MAXN = 1e3 + 5;
vector<vector<ll>> ps(MAXN + 1, vector<ll>(MAXN + 1, 0));

ll tong(int x1, int y1, int x2, int y2) {
	return ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1];
}

void testcase() {
    int m, n;
    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            ll x; cin >> x;
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + x;
        }
    }

    ll ans = LLONG_MAX;

    for (int i = 1; i < m; i++) {
        vector<ll> top(n + 1), bot(n + 1);

        for (int j = 1; j <= n; j++) {
            top[j] = tong(1, 1, i, j);
            bot[j] = tong(i + 1, 1, m, j);
        }

        ll topSum = top[n];
        ll botSum = bot[n];

        int k = 1;

        for (int j = 1; j < n; j++) {
            ll topL = top[j];
            ll topR = topSum - top[j];

            while (k + 1 < n) {
                ll cur = abs(bot[k] - (botSum - bot[k]));
                ll nxt = abs(bot[k + 1] - (botSum - bot[k + 1]));
                if (nxt <= cur) k++;
                else break;
            }

            for (int kk : {k, k + 1}) {
                if (kk >= 1 && kk < n) {
                    ll botL = bot[kk];
                    ll botR = botSum - bot[kk];
                    ll mx = max({topL, topR, botL, botR});
                    ll mn = min({topL, topR, botL, botR});
                    ans = min(ans, mx - mn);
                }
            }
        }
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
