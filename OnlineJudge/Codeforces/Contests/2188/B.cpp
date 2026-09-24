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

void testcase() {
	int n; cin >> n;
	string s; cin >> s;
	
	vector<int> unsur;
	vector<int> sur;
	
	bool bruh = false;
	int ones = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') ++cnt;
		else {
			if (cnt != 0) {
				if (bruh) sur.push_back(cnt);
				else unsur.push_back(cnt);
			}
			bruh = true;
			++ones;
			cnt = 0;
		}
	}
	if (cnt == n) {
		double x = cnt;
		cout << ceil(x / 3) << el; return;
	}
	if (cnt != 0) unsur.push_back(cnt);
	
	int res = 0;
	
	for (int x : unsur) {
		--x;

		double y = (double)x;
		res += ceil(y / 3);
	}
	
	for (int x : sur) {

		double y = (double)x;
		res += floor(y / 3);
	}

	cout << res + ones;
	
	cout << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
