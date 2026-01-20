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
	int n; cin >> n;
	set<pii> st;
	for (int i = 0; i < n; i++) {
		pii a;
		cin >> a.first >> a.second;
		
		if (st.count({a.second, a.first})) st.erase({a.second, a.first});
		else st.insert(a);
	}
	if (st.size() > 0) cout << "NO" << el;
	else cout << "YES" << el;
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
