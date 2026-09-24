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

bool a[51][51];

void pre() {
	a[1][1] = 1;
	for (int j = 2; j <= 50; j++) {
		if (j & 1) a[1][j] = a[1][j - 1];
		else a[1][j] = a[1][j - 1] ^ 1;
	}
	for (int j = 1; j <= 50; j++) {
		for (int i = 2; i <= 50; i++) {
			if (i & 1) a[i][j] = a[i - 1][j];
			else a[i][j] = a[i - 1][j] ^ 1;
		}
	}
}

void testcase() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << el;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();
	
	pre();
	
	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
