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
	stack<int> st;
	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		if (x == 1) {
			int n; cin >> n;
			st.push(n);
		} else if (x == 2) {
			if (!st.empty()) st.pop();
		} else {
			if (!st.empty()) cout << st.top();
			else cout << "Empty!";
			
			cout << el;
		}
	}
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
