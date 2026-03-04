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
ll n;
unordered_map<ll,ll> m;
void testcase() {
	cin >> n;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i) continue;
		ll maxm = n - 2;
		maxm -= (maxm % i);
		m[maxm + i] = max(m[maxm + i], maxm);
		ll g = n / i;
		maxm = n - 2;
		maxm -= (maxm % g);
		m[maxm + g] = max(m[maxm + g], maxm);
	}
	while (!m[n]) n--;
	cout << m[n];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
