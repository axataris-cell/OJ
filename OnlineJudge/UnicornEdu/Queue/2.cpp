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
	priority_queue<int, vector<int>> q;
	string n;
	while (cin >> n) {
		if (n[0] == '+' && q.size() < 15000) {
			q.push(stoll(n.substr(1, n.size() - 1)));
		}
		if (n == "-" && !q.empty()) {
			int m = q.top();
			while (q.top() == m && !q.empty()) {
				q.pop();
			}
		}
	}
	
	set<int, greater<int>> k;
	while (!q.empty()) {
		k.insert(q.top());
		q.pop();
	}
	
	cout << k.size() << el;
	for (auto x : k) cout << x << el;
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
