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
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<ll> p(n, -1), f(n, n); // previous smaller and next smaller
	
	stack<int> st1, st2;
	
	for (int i = 0; i < n; i++) {
		while (!st1.empty() && a[i] < a[st1.top()]) {
			f[st1.top()] = i;
			st1.pop();
		}
		st1.push(i);
	}
	
	for (int i = 0; i < n; i++) {
		while (!st2.empty() && a[i] < a[st2.top()]) {
			st2.pop();
		}
		if (!st2.empty()) {
			p[i] = st2.top();
		}
		st2.push(i);
	}
	
	ll res = 0;
	
	for (int i = 0; i < n; i++) {
		res = max((f[i] - p[i] - 1) * a[i], res);
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
