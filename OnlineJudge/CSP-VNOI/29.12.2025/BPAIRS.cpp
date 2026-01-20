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
	string s; cin >> s;
	int n = s.size();
	vector<int> a(n, -1);
	stack<int> st;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			st.push(i);
		} else {
			a[i] = st.top();
			st.pop();
		}
	}
	
	for (auto x : a) {
		if (x != -1) {
			cout << x << ' ';
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
