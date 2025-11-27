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
	string s; cin >> s; int n = s.length();
	stack<int> st;
	ll res = 0;
	
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			st.push(i);
			res = max(res, (int)st.size());
		} else if (s[i] == ')') {
			if (st.empty()) {
				cout << -1;
				return;
			}
			st.pop();
		}
	}
	if (!st.empty()) {
		cout << -1; return;
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
