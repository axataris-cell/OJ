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
	int n = s.length();
	string res = "";
	
	string t = s;
	reverse(t.begin(), t.end());
	if (s == t) {
		cout << s; return;
	}
	
	for (int i = 0; i < n - 1; i++) {
		if (s[i] ==  s[i + 1]) {
			int l = i, r = i + 1;
			while (r < n && l >= 0 && s[l] == s[r]) {
				--l; ++r;
			}
			if (s[l] != s[r]) {
				++l; --r;
			}
			if (r - l + 1 > res.size()) {
				res = s.substr(l, r - l + 1);
			}
		}
	}
	for (int i = 0; i < n - 2; i++) {
		if (s[i] == s[i + 2]) {
			int l = i, r = i + 2;
			while (r < n && l >= 0 && s[l] == s[r]) {
				--l; ++r;
			}
			if (s[l] != s[r]) {
				++l; --r;
			}
			if (r - l + 1 > res.size()) {
				res = s.substr(l, r - l + 1);
			}
		}
	}
	
	cout << res;
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
