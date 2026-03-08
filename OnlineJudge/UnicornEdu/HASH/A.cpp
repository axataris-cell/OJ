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
const int MOD = 1e9 + 7;

string s;
int n;

vector<int> P(MAXN, 1), H(MAXN, 0);

void build() {
	for (int i = 1; i <= n; i++) {
		P[i] = (P[i - 1] * BASE) % MOD;
		H[i] = (H[i - 1] * BASE % MOD + s[i - 1] % MOD) % MOD;
	}
}

int getHash(int l, int r) {
	return ((H[r] - (H[l - 1] * P[r - l + 1] % MOD)) % MOD + MOD) % MOD;
}

void testcase() {
	cin >> s;
	n = s.length();
	
	build();

	for (int len = 1; len <= n; len++) {
		int cur = getHash(1, len);
		bool check = true;
		for (int i = 1; i <= n; i += len) {
			if (n - i + 1 < len) {
				if (getHash(1, n - i + 1) != getHash(i, n)) check = false;
			} else {
				if (cur != getHash(i, i + len - 1)) {
					check = false;
					break;
				}
			}
		}
		if (check) {
			cout << len << ' ';
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
