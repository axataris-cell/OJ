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
	string s, t; cin >> s >> t;
	unordered_map<char, int> mp, mp1;
	for (auto x : s) ++mp[x];
	for (auto x : t) ++mp1[x];

	for (int i = 'a'; i <= 'z'; i++) {
		if (mp[i] > mp1[i]) {
			cout << "Impossible" << el;
			return;
		} else {
			int cnt = 0;
			for (int j = 0; j < t.length(); j++) {
				while (t[j] == i) {
					t.erase(j, 1);
					++cnt;
					if (cnt == mp[i]) break;
				}
				if (cnt == mp[i]) break;
			}
		}
	}
	sort(t.begin(), t.end());
	
	string res = "";
	
	int l = 0, r = 0;
	while (l < s.length() && r < t.length()) {
		if (t[r] < s[l]) {
			res += t[r];
			++r;
		} else if (t[r] > s[l]) {
			res += s[l];
			++l;
		} else {
			res += t[r];
			res += s[l];
			++l;
			++r;
		}
	}
	while (l < s.length()) {
		res += s[l]; ++l;
	}
	while (r < t.length()) {
		res += t[r]; ++r;
	}
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
