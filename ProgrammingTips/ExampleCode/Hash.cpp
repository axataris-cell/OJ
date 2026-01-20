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

const ll BASE = 911382;
const ll MOD = 1e9 + 7;

vector<ll> H, P;

void buildHash(string s) {
	int n = s.length();
	H.assign(n + 1, 0);
	P.assign(n + 1, 1);

	for (int i = 1; i <= n; i++) {
		H[i] = (H[i - 1]  * BASE + s[i - 1]) % MOD; // HASH 0.....i - 1.
		P[i] = (P[i - 1] * BASE) % MOD;
	}
}

ll getHash(int l, int r) {
	return ((H[r + 1] - H[l] * P[r - l + 1]) % MOD + MOD) % MOD;
}

void testcase() {
	string s; cin >> s;
	buildHash(s);
	cout << getHash(0, 2) << ' ' << getHash(2, 4); 
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
