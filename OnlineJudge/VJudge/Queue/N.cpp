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
	set<int> st;
	string s;
	while (cin >> s) {
		int x; cin >> x;
		if (s == "insert") {
			st.insert(x);
		} else if (s == "exists") {
			if (st.count(x)) cout << "true" << el;
			else cout << "false" << el;
		} else if (s == "delete") {
			st.erase(x);
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
