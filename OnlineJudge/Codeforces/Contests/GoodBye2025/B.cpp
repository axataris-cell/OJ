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
	string t; cin >> t;
	int res = 0;
	
	if (t[0] != 's') {
		t[0] = 's';
		++res;
	}
	
	for (int i = 1; i < t.length() - 1; i++) {
		if (t[i] == 'u') {
			if (t[i - 1] != 's') {
				t[i - 1] = 's';
				++res;
			}
			if (t[i + 1] != 's') {
				t[i + 1] = 's';
				++res;
			}
		}
	}
	if (t[t.length() - 1] == 'u') ++res;
	
	cout << res << el;
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
