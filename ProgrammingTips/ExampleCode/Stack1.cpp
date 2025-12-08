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
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	stack<pii> st; // Chiều cao - Số lượng người có chiều cao giống nhau liên tiếp.
	ll res = 0;
	for (auto h : a) {
		ll cnt = 1;
		
		while (!st.empty() && st.top().first < h) {
			res += st.top().second;
			st.pop();
		}
		
		if (!st.empty() && st.top().first == h) {
			ll same = st.top().second;
			res += same;
			st.pop();
			cnt = same + 1;
			
			if (!st.empty()) ++res;
		} else {
			if (!st.empty()) ++res;
		}
		
		st.push({h, cnt});
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
