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

ll maxArea(vector<ll> &a) {
	stack<int> st;
	int n = a.size();
	ll res = 0;
	
	ll tp;
	
	for (int i = 0; i < n; i++) {
		while (!st.empty() && a[st.top()] >= a[i]) {
			tp = st.top();
			st.pop();
			
			ll w;
			if (st.empty()) {
				w = i;
			} else {
				w = i - st.top() - 1;
			}
			
			res = max(res, 1LL * a[tp] * w);
		}
		st.push(i);
	}
	ll cur;
	while (!st.empty()) {
		tp = st.top();
		st.pop();
		if (st.empty()) {
			cur = a[tp] * n;
		} else cur = a[tp] * (n - st.top() - 1);
		res = max(res, 1LL * cur);
	}
	
	return res;
}

void testcase() {
	ll m, n; cin >> m >> n;
	vector<ll> a(n), b(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = m - a[i];
	}
	
	ll m1 = maxArea(a);
	ll m2 = maxArea(b);
	
	cout << max(m1, m2);
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
