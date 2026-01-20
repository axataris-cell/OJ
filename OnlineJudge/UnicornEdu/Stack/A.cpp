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
	stack<int> st;
	
	int q; cin >> q;
	while (q--) {
		int a; cin >> a;
		if (a == 1) {
			int b; cin >> b;
			st.push(b);
		} else if (a == 2) {
			if (!st.empty()) st.pop();
		} else {
			if (st.empty()) cout << -1 << el;
			else cout << st.top() << el;
		}
	}
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
