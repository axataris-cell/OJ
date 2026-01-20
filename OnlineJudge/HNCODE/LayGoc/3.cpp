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
	for (int i = 0; i < n; i++) cin >> a[i];
	int maxres = 0;
	for (int i = 1; i < n; i++) maxres = max(abs(a[i] - a[i - 1]), maxres);
	
	cout << maxres;
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
