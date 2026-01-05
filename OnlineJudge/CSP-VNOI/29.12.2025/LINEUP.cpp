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

void testcase() {
	int n; cin >> n;
	vector<int> a(n);
	vector<int> res(n, -1);
	
	stack<int> st; //height - count
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		
		while (!st.empty() && a[st.top()] <= a[i]) st.pop();
		if (!st.empty()) res[i] = st.top();
		st.push(i);
	}
	for (auto x : res) cout << x + 1 << ' ';
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
