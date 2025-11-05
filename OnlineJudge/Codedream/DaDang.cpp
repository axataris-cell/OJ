#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int A[105][105] = {};

void testcase() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= n; k++) {
				for (int l = 1; l <= m; l++) {
					if (k == i || l == j) continue;
					if (A[k][l] == A[i][j]) {
						cout << i << ' ' << j << ' ' << k << ' ' << l;
						return;
					}
				}
			}
		}
	}
	
	cout << "-1";
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
