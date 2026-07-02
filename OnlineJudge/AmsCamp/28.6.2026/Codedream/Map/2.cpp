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
	int m, n = 0; vector<int> a;
	cin >> m;
	while (m--) {
		int h, w; cin >> h >> w;
		for (int i = 1; i <= w; i++) {
			a.push_back(h);
			++n;
		}
	}
	
	vector<int> prev(n, -1), next(n, n);
	
	stack<int> st;
	
	for (int i = 0; i < n; i++) {
		while (!st.empty() && a[i] <= a[st.top()]) {
			next[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	
	stack<int> st2;
	
	for (int i = 0; i < n; i++) {
		while (!st2.empty() && a[i] <= a[st2.top()]) st2.pop();
		if (!st2.empty()) prev[i] = st2.top();
		st2.push(i);
	}
	
	int res = 0;
	
	for (int i = 0; i < n; i++) {
		res = max(res, a[i] * (next[i] - prev[i] - 1));
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
