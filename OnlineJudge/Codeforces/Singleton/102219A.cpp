#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

const int MAXN = 1005;
char A[1005][1005] = {};
int B[1005][1005] = {}; //Rotat
char S[4] = {'^', '>', 'v', '<'};

void testcase() {
	int n; cin >> n;
	string s; cin >> s;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
			if (A[i][j] == '^') B[i][j] = 0;
			else if (A[i][j] == '>') B[i][j] = 1;
			else if (A[i][j] == 'v') B[i][j] = 2;
			else if (A[i][j] == '<') B[i][j] = 3;
			else B[i][j] = -1;
		}
	}
	int turn = 0;
	for (char c : s) {
		if (c == 'R') ++turn;
		else --turn;
	}
	
	turn = ((turn % 4) + 4) % 4;
	
	if (turn == 0) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (B[i][j] != -1) cout << S[(B[i][j] + turn) % 4];
				else cout << A[i][j];
			}
			cout << el;
		}
	} else if (turn == 1) {
		for (int j = 1; j <= n; j++) {
			for (int i = n; i >= 1; i--) {
				if (B[i][j] != -1) cout << S[(B[i][j] + turn) % 4];
				else cout << A[i][j];
			} 
			cout << el;
		}
	} else if (turn == 2) {
		for (int i = n; i >= 1; i--) {
			for (int j = n; j >= 1; j--) {
				if (B[i][j] != -1) cout << S[(B[i][j] + turn) % 4];
				else cout << A[i][j];
			}
			cout << el;
		}
	} else if (turn == 3) {
		for (int j = n; j >= 1; j--) {
			for (int i = 1; i <= n; i++) {
				if (B[i][j] != -1) cout << S[(B[i][j] + turn) % 4];
				else cout << A[i][j];
			}
			cout << el;
		}
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
