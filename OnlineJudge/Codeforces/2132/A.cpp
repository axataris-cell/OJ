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
	string a; cin >> a;
	int m; cin >> m;
	string b, c;
	cin >> b >> c;
	
	deque<char> s;
	for (int i = 0; i < n; i++) {
		s.push_back(a[i]);
	}
	
	for (int i = 0; i < m; i++) {
		if (c[i] == 'D') {
			s.push_back(b[i]);
		} else s.push_front(b[i]);
	}
	
	while (s.size()) {
		cout << s.front();
		s.pop_front();
	}
	cout << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
