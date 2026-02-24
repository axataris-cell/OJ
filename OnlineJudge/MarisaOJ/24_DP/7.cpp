#include <bits/stdc++.h>
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

const int MAXN = 2 * 1e5 + 7;
const int MOD = 1e9 + 7;
int f[MAXN];
int pf[MAXN];

void testcase() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= k; i++){
        pf[i] = pf[i-1] + 1;
        f[i] = 1;
    }

    for (int i = k+1; i <= n; i++){
        f[i]= (1 + pf[i - k] % MOD) % MOD;
        pf[i] = (pf[i-1] % MOD + f[i] % MOD) % MOD;
    }
    cout << pf[n] + 1;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
