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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	
	int cnt0 = 0, cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < k; i++) {
		if (s[i] == '0') ++cnt0;
		if (s[i] == '1') ++cnt1;
		if (s[i] == '2') ++cnt2;
	}
	
	int an = n - cnt0 - cnt1;
	
	if (2 * cnt2 <= an) {
		for (int i = 1; i <= cnt0; i++) cout << '-';
		for (int i = 1; i <= cnt2; i++) cout << '?';
		for (int i = 1; i <= an - cnt2 * 2; i++) cout << '+';
		for (int i = 1; i <= cnt2; i++) cout << '?';
		for (int i = 1; i <= cnt1; i++) cout << '-';
	} else {
		if (cnt2 == an) {
			for (int i = 1; i <= cnt0; i++) cout << '-';
			for (int i = 1; i <= cnt2; i++) cout << '-';
			for (int i = 1; i <= cnt1; i++) cout << '-';
		} else {
			for (int i = 1; i <= cnt0; i++) cout << '-';
			for (int i = 1; i <= an; i++) cout << '?';
			for (int i = 1; i <= cnt1; i++) cout << '-';
		}
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
