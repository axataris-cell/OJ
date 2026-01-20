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
	vector<pii> pos;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] <= 10) {
			pos.push_back({i, a[i]});
		}
	}
	
	for (auto x : pos) {
		cout << "A[" << x.first << "] = " << x.second << el;
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
