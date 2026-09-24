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

#define int long long

const int LOG = 30;

void testcase() {
	int x, y, z; cin >> x >> y >> z;
	bool ok = true;
	for (int i = 0; i <= LOG; i++) {
		if (!(x >> i & 1) && y >> i & 1 && z >> i & 1 ||
			x >> i & 1 && !(y >> i & 1) && z >> i & 1 ||
			x >> i & 1 && y >> i & 1 && !(z >> i & 1)) {
			ok = false;
			break;
		}
	}
	if (ok) cout << "YES";
	else cout << "NO";
	
	cout << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
