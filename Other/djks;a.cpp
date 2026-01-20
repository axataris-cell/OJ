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
	vector<int> a(4 * n);
	map<int, int> mp;
	for (int i = 0; i < 4 * n; i++) {
		cin >> a[i];
		++mp[a[i]];
	}
	for (auto x : mp) {
		if (x.second % 2 != 0) {
			cout << "NO" << el;
			return;
		}
	}
	sort(a.begin(), a.end());
	int l = 0, r = 4 * n - 1;
	int area = a[l] * a[r];
	
	bool check = true;
	while (l <= r) {
		++l; --r;
		if (a[l] * a[r] != area) {
			check = false;
			break;
		}
	}
	
	if (check) cout << "YES" << el;
	else cout << "NO" << el;
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
