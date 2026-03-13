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
	int n; cin >> n;
	vector<int> a(n + 1), b(n + 1), arr(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		arr[i] = a[i];
	}
	for (int j = 1; j <= n; j++) cin >> b[j];
	
	if (a[n] != b[n]) {
		cout << "NO" << el;
		return;
	}
	
	bool valid = true;
	for (int i = n - 1; i >= 1; i--) {
		if (a[i] == b[i]) continue;
		if ((a[i] ^ a[i + 1]) == b[i]) {
			a[i] ^= a[i + 1];
		} else if ((a[i] ^ arr[i + 1]) == b[i]) {
			a[i] ^= arr[i + 1];
		} else {
			valid = false;
			break;
		}
	}
	
//	cout << 10 ^ 10;
//	
//	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
//	cout << el;
	
	cout << ((valid) ? "YES" : "NO") << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
