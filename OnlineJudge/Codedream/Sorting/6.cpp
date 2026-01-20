#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int F[10] = {};
void testcase() {
	string s; cin >> s;
	string res = "";
	for (char c : s) ++F[(int)c - '0'];
	int first = 0;
	for (int i = 1; i <= 9; i++) {
		if (F[i] != 0) {
			first = i;
			break;
		}
	}
	res += (char)(first + '0');
	if (F[0] != 0) {
		for (int i = 1; i <= F[0]; i++) res += '0';
	}
	for (int i = 2; i <= F[first]; i++) res += (char)(first + '0');
	if (first != 9) {
		for (int i = first + 1; i <= 9; i++) {
			if (F[i] != 0) {
				for (int j = 1; j <= F[i]; j++) res += (char)(i + '0');
			}
		}
	}
	cout << res;
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
