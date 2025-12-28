#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

void testcase() {
	string s; cin >> s;
	int cnt = 0;
	
	for (auto x : s) {
		if (x == 'Y') ++cnt;
		if (cnt == 2) {
			cout << "NO" << el;
			return;
		}
	}
	cout << "YES" << el;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
