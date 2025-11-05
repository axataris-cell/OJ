#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int A[1005][1005] = {};

void testcase() {
	int n, m; cin >> n >> m;
	
	ll to = 0;
	ll te = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> A[i][j];
			if ((i + j) % 2 == 0) te += A[i][j];
			else to += A[i][j];
		}
	}
	
	cout << te << ' ' << to;
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
