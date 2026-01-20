#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

void testcase() {
	int n; cin >> n; vector<int> a(n);
	vector<int> odd, even;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] & 1) odd.push_back(a[i]);
		else even.push_back(a[i]);
	}
	
	sort(odd.begin(), odd.end());
	sort(even.begin(), even.end(), greater<int>());
	
	for (auto x : odd) cout << x << ' ';
	for (auto y : even) cout << y << ' ';
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
