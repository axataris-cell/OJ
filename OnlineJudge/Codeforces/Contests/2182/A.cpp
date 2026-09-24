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
	int n; cin >> n;
	string s; cin >> s;
	
	if (n <= 3) {
		cout << 0 << el;
		return;
	}

	bool check = false;
	
	for (int i = 0; i <= n - 4; i++) {
		if (s.substr(i, 4) == "2026") {
			check = true;
			break;
		}
	}
	
	if (check) {
		cout << 0 << el;
		return;
	}
	
	check = true;
	for (int i = 0; i <= n - 4; i++) {
		if (s.substr(i, 4) == "2025") {
			check = false;
			break;
		}
	}
	
	if (check) cout << 0 << el;
	else {
		cout << 1 << el;
	}
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
