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

string s;

bool cmp(string x, string y) {
	int i = 0, j = 0;
	while (i < (int)x.length() && j < (int)y.length()) {
		if (x[i] != y[j]) {
			for (char c : s) {
				if (x[i] == c) return true;
				else if (y[j] == c) return false;
			}
		}
		++i;
		++j;
	}
	if (i != (int)x.length()) return false;
	else return true;
}

void testcase() {
	cin >> s;
	int n; cin >> n;
	vector<string> a(n); 
	for (int i = 0; i < n; i++) cin >> a[i];
	
	sort(a.begin(), a.end(), cmp);
	
	for (auto x : a) cout << x << el;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
