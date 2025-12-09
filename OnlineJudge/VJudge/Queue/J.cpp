#include <bits/stdc++.h>
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
	unordered_map<string, int> mp;
	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		++mp[s];
	}
	pair<string, int> res = {"", -1};
	for (auto x : mp) {
		if (x.second > res.second) {
			res = {x.first, x.second};
		} else if (x.second == res.second) {
			if (x.first > res.first) res = {x.first, x.second};
		}
	}
	cout << res.first << ' ' << res.second;
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
