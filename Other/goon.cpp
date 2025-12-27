#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

string dict;
bool comp(string x, string y) {
	int l = 0, r = 0;
	while (l < x.length() && r < y.length()) {
		if (x[l] == y[r]) {
			++r; ++l;
		} else {
			for (auto c : dict) {
				if (x[l] == c) return true;
				if (y[r] == c) return false;
			}
		}
	}
	if (l != x.length()) return false;
	else return true;
}

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

void testcase() {
	cin >> dict;
	int n; cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end(), comp);
	for (auto x : a) cout << x << el;
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
