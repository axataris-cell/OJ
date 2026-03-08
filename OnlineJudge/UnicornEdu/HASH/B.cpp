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

#define int long long

const int MAXN = 1e6 + 6;
const int BASE = 311;
const int BASE2 = 7319;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;

string s;
int n;

vector<int> P(MAXN, 1), H(MAXN, 0);
vector<int> P2(MAXN, 1), H2(MAXN, 0);

void build() {
	for (int i = 1; i <= n; i++) {
		P[i] = (P[i - 1] * BASE) % MOD;
		H[i] = (H[i - 1] * BASE % MOD + s[i - 1] % MOD) % MOD;
	}
}

int getHash(int l, int r) {
	return ((H[r] - (H[l - 1] * P[r - l + 1] % MOD)) % MOD + MOD) % MOD;
}

void build2() {
	for (int i = 1; i <= n; i++) {
		P2[i] = (P2[i - 1] * BASE2) % MOD2;
		H2[i] = (H2[i - 1] * BASE2 % MOD2 + s[i - 1] % MOD2) % MOD2;
	}
}

int getHash2(int l, int r) {
	return ((H2[r] - (H2[l - 1] * P2[r - l + 1] % MOD2)) % MOD2 + MOD2) % MOD2;
}

void testcase() {
	cin >> s;
	string t; cin >> t;
	int m = t.length();
	int k; cin >> k;
	
	n = s.length();
	build();
	build2();
	
	int hasht = 0;
	for (int i = 0; i < m; i++) {
		hasht = ((hasht * BASE) % MOD + t[i] % MOD) % MOD;
	}
	
	int hasht2 = 0;
	for (int i = 0; i < m; i++) {
		hasht2 = ((hasht2 * BASE2) % MOD2 + t[i] % MOD2) % MOD2;
	}
	
    vector<int> diff(n + 5, 0);

    for (int i = 1; i + m - 1 <= n; i++){
        if (getHash(i, i + m - 1) == hasht && getHash2(i, i + m - 1) == hasht2){

            int l = max(1LL, i + m - k);
            int r = min(i, n - k + 1);

            if (l <= r){
                diff[l]++;
                diff[r + 1]--;
            }
        }
    }

	int cur = 0, res = 0;

    for(int i = 1; i <= n - k + 1; i++){
        cur += diff[i];
        if (cur > 0) res++;
    }

    cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
