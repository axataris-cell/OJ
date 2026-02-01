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

void debug_time(const string& label = "") {
    static auto start = chrono::steady_clock::now();
    auto now = chrono::steady_clock::now();
    double ms = chrono::duration<double, milli>(now - start).count();
    cerr << "[TIME] " << label << ": " << ms << " ms\n";
}

int n;
char a[15];

void dequy(int q, char prev) {
	if (q == 0) {
		for (int i = 1; i <= n; i++) cout << a[i];
		cout << el;
		return;
	} else if (q == n) {
		for (int i = 'A'; i <= 'C'; i++) {
			a[q] = (char)i;
			dequy(q - 1, i);
		}
	}
	
	for (int i = 'A'; i <= 'C'; i++) {
		if (prev == i) continue;
		a[q] = (char)i;
		dequy(q - 1, i);
	}
}
void testcase() {
	cin >> n;
	
	dequy(n, 'A');
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	debug_time();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
