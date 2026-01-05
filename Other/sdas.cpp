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
	vector<int> a(n);
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		++mp[a[i]];
	}
	
	int q; cin >> q;
	while (q--) {
		char input; cin >> input;
		int bruh; cin >> bruh;
		if (input == '+') ++mp[bruh];
		else {
			--mp[bruh];
		}
		
		// Search
		int cnt4 = 0;
		int cnt2 = 0;
		for (auto x : mp) {
			if (x.second >= 2) {
				cnt4 += x.second / 4;
				cnt2 += (x.second % 4) / 2;
			}
		}
		
		if (cnt4 == 0) {
			cout << "NO" << el;
		} else {
			if (cnt2 < 2) {
				if (cnt4 == 1) cout << "NO" << el;
				else cout << "YES" << el;
			} else {
				cout << "YES" << el;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
