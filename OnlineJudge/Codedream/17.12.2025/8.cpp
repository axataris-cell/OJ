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
	string a, b; cin >> a >> b;
	
	string r1 = "";
	int l = 0, r = 0;
	while (l < a.size() && r < b.size()) {
		if (a.substr(l, a.size() - l) < b.substr(r, b.size() - r)) {
			r1 += a[l]; ++l;
		} else {
			r1 += b[r]; ++r;
		}
	}
	r1 += a.substr(l, a.size() - l);
	r1 += b.substr(r, b.size() - r);
	
	string r2 = "";
	l = 0, r = 0;
	while (l < a.size() && r < b.size()) {
		if (a.substr(l, a.size() - l) > b.substr(r, b.size() - r)) {
			r2 += a[l]; ++l;
		} else {
			r2 += b[r]; ++r;
		}
	}
	r2 += a.substr(l, a.size() - l);
	r2 += b.substr(r, b.size() - r);
	
	cout << r1 << el << r2;
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
