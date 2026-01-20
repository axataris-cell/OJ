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
	int n, m; cin >> n >> m;
	unordered_map<string, int> mp;
	while (n--) {
		string s; int x;
		cin >> s >> x;
		mp[s] = x;
	}
	vector<ll> price;
	while (m--) {
		string s; ll p = 0;
		while (cin >> s) {
			p += mp[s];
			if (s == ".") break;
		}
		price.push_back(p);
	}
	for (auto x : price) cout << x << el;
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
