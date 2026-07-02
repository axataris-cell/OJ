#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

char A[1005][1005] = {};

void testcase() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> A[i][j];
		}
	}
	
	for (int j = 1; j <= m; j++) {
		int cnt = 0;
		for (int i = n; i >= 1; i--) {
			if (A[i][j] == '1') ++cnt;
			else {
				break;
			}
		}
		cout << cnt << ' ';
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
