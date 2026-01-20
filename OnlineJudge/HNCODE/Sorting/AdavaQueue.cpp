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
	int q; cin >> q;
	deque<int> a;
	while (q--) {
		string s; cin >> s;
		if (s == "back") {
			if (!a.empty()) {
				cout << a.back() << el;
				a.pop_back();
			} else cout << "No job for Ada?" << el;
		} else if (s == "front") {
			if (!a.empty()) {
				cout << a.front() << el;
				a.pop_front();
			} else cout << "No job for Ada?" << el;
		} else if (s == "reverse") {
			reverse(a.begin(), a.end());
		} else if (s == "push_back") {
			int n; cin >> n;
			a.push_back(n);
		} else if (s == "toFront") {
			int n; cin >> n;
			a.push_front(n);
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
