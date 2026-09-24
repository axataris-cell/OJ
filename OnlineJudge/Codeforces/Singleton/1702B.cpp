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
	int res = 0;
	
	unordered_set<char> st;
	for (int i = 0; i < n; i++) {
		st.insert(s[i]);
		if (st.size() == 4) {
			++res; st.clear();
			st.insert(s[i]);
		}
	}
	if (st.size()) ++res;
	
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
