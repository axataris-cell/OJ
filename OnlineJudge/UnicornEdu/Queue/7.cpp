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
	priority_queue<int> a;
	int q; cin >> q;
	while (q--) {
		string s; cin >> s;
		if (s == "ADD") {
			int x; cin >> x;
			a.push(x);
		}
		if (s == "MAX") {
			if (!a.empty()) cout << a.top() << el;
			else cout << "NO" << el;
		}
		if (s == "DEL") {
			if (!a.empty()) {
				int m = a.top();
				while (!a.empty() && a.top() == m) a.pop();
			}
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
