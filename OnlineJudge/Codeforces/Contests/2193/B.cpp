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
	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	b = a;
	sort(b.begin() + 1, b.begin() + n + 1, greater<int>());
	int pos1 = 0, pos2 = 0;
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i]) {
			pos1 = i;
			cur = b[i];
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == cur) {
			pos2 = i;
			break;
		}
	}
	cerr << pos1 << ' ' << pos2 << el;
	if (pos1 == 0) {
		for (int i = 1; i <= n; i++) cout << a[i] << ' ';
		cout << el;
		return;
	}
	for (int i = 1; i < pos1; i++) {
		cout << a[i] << ' ';
	}
	for (int i = pos2; i >= pos1; i--) {
		cout << a[i] << ' ';
	}
	for (int i = pos2 + 1; i <= n; i++) cout << a[i] << ' ';
	cout << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
