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
	string n; cin >> n;
	for (char c : n) ++F[(int)c - '0'];
	
	int tot = 0;
	for (int i = 0; i <= 9; i++) {
		tot += F[i]*i;
	}
	string res = "";
	if (tot % 9 == 0) {
		res = n;
	}
	
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			int cnt = 0;
			cnt += F[i]*j;
			for (int k = 0; k <= 9; k++) {
				if (k == i) continue;
				cnt += F[k]*j;
			}
			if (cnt % 9 == 0) {
				
			}
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
