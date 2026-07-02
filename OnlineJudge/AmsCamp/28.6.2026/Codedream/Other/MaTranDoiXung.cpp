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
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
		}
	}
	
	bool check = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (A[i][j] == 0) {
				if (A[j][i] != 0) A[i][j] = A[j][i];
//				else {
//					cout << "-1";
//					return;
//				}
			} else {
				if (A[i][j] != A[j][i] && A[j][i] != 0) {
					check = false;
				}
			}
		}
	}
	
	if (check) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) cout << A[i][j] << ' ';
			cout << el;
		}
	} else {
		cout << "-1";
		return;
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
