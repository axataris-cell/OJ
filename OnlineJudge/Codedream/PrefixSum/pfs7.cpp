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

const int MOD = 4444;

void testcase() {
	int n; cin >> n;
	string s; cin >> s;
	
    vector<ll> dp(MOD, 0), cudp(MOD, 0);
	ll res = 0;

    for (char c : s) {
        int d = c - '0';
        fill(cudp.begin(), cudp.end(), 0);

        for (int r = 0; r < MOD; r++) {
            if (dp[r] > 0) {
                int nr = (r * 10 + d) % MOD;
                cudp[nr] += dp[r];
            }
        }

        cudp[d % MOD]++;

        swap(dp, cudp);
        res += dp[0];
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
