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

const int MAXN = 1e6 + 5;

int p[MAXN];
map<int, int> cntprime;

void sieve() {
	for (int i = 1; i < MAXN; i++) p[i] = i;
	for (int i = 2; i * i < MAXN; i++) {
		if (p[i] == i) {
			for (int j = i * i; j < MAXN; j += i) {
				p[j] = i;
			}
		}
	}
}

void cnt(int n) {
	while (n > 1) {
		++cntprime[p[n]];
		n /= p[n];
	}
}

void testcase() {
	cntprime.clear();
	
	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt(a[i]);
	}
	
	for (auto &[p, cnt] : cntprime) {
		if (cnt % n) {
			cout << "NO" << el;
			return;
		}
	}
	
	cout << "YES" << el;
	return;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();
	
	sieve();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
