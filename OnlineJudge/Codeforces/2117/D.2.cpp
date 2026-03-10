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

void testcase() {
	int n; cin >> n;
	vector<int> a(n + 1);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	
	sum *= 2;
	
	if (sum % n || sum % (n + 1)) {
		cout << "NO" << el;
		return;
	}
	
	int d = sum / (n * (n + 1) * 1LL);
	
	int curbeta = LINF;
	for (int i = 1; i <= n; i++) {
		int left = a[i] - d * i;
		
		if (n - 2 * i + 1 == 0) continue;
		
		if (left % (n - 2 * i + 1)) {
			cout << "NO" << el;
			return;
		}
		if (curbeta == LINF) {
			curbeta = left / (n - 2 * i + 1);
		} else {
			if (curbeta != left / (n - 2 * i + 1)) {
				cout << "NO" << el;
				return;
			}
		}
	}
	if (curbeta > d || curbeta < 0) {
		cout << "NO" << el;
		return;
	}
	
	int alpha = d - curbeta;
	
	for (int i = 1; i <= n; i++) {
		if (a[i] - alpha * i - curbeta * (n - i + 1) != 0) {
			cout << "NO" << el;
			return;
		}
	}
	
	cout << "YES" << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
