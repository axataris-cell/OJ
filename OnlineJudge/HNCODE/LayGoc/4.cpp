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
	int n; cin >> n;
	vector<ld> a(n);
	vector<ld> mi;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0) mi.push_back(a[i]);
	}
	ld al = 0;
	for (int i = 0; i < mi.size(); i++) {
		al += mi[i];
	}
	if (mi.size() == 0) cout << -1;
	else cout << setprecision(2) << fixed << al / mi.size();
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
