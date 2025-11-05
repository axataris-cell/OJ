#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int A[10][10] = {};

void testcase() {
	pair<int, int> pos = {};
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> A[i][j];
			if (A[i][j] == 0) pos = {i, j};
		}
	}
	
	bool check = true;
	
	// Kiểm tra từng ô
	for (int i = 1; i <= 9; i += 3) {
		for (int j = 1; j <= 9; j += 3) {
			int F[10] = {};
			++F[A[i][j]]; ++F[A[i + 1][j]]; ++F[A[i + 2][j]];
			++F[A[i][j + 1]]; ++F[A[i + 1][j + 1]]; ++F[A[i + 2][j + 1]];
			++F[A[i][j + 2]]; ++F[A[i + 1][j + 2]]; ++F[A[i + 2][j + 2]];
			
			for (int k = 1; k <= 9; k++) {
				if (F[k] > 1) {
					check = false;
				}
			}
		}
	}
	
	// Kiểm tra hàng cột
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			int F[10] = {};
			
			// Cùng cột
			for (int k = 1; k <= 9; k++) {
				++F[A[k][j]];
				if (F[A[k][j]] > 1) {
					check = false;
					break;
				}
			}
			
			int H[10] = {};
			
			// Cùng hàng
			for (int k = 1; k <= 9; k++) {
				++H[A[i][k]];
				if (H[A[i][k]] > 1) {
					check = false;
					break;
				}
			}
		}
	}
	
	ll res = -1;
	
	if (check) {
		int F[10] = {};
		for (int i = 1; i <= 9; i++) {
			++F[A[i][pos.second]];
		}
		for (int x = 1; x <= 9; x++) {
			if (F[x] == 0) {
				res = x;
				break;
			}
		}
		
		cout << res;
	} else {
		cout << res;
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
