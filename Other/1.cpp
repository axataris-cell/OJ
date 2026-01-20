#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

void testcase() {
	string s; getline(cin, s);
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		if (!(s[i] == 'A' || s[i] == 'B' || s[i] == 'C' || s[i] == 'D' || s[i] == 'E' || s[i] == '&')) {
			if (s[i] == ' ') st.push('&');
			else st.push(s[i]);
			s.erase(i, i);
		}
	}
	
	while (!st.empty()) {
		s += st.top();
		st.pop();
	}
	
	cout << s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
