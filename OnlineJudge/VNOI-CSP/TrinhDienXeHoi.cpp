#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int x[100005] = {};
int v[100005] = {};
int r[100005] = {}; // Vị trí sau t thời gian

void testcase() {
	int n, t; cin >> n >> t;
	int cnt = 0;
	r[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> v[i];
		r[i] = x[i] + v[i]*t; //s = s0 + v*t
		if (r[i] > r[i - 1]) ++cnt;
	}
	cout << cnt;
	
	
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
