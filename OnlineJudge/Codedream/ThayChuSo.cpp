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
	vector<string> res;
	for (char c : n) ++F[(int)c - '0'];
	
	// OG
	int cnt = 0;
	for (int i = 0; i <= 9; i++) {
		cnt += i*F[i];
	}
	if (cnt % 9 == 0) res.push_back(n);
	
	// Replace
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			if (i == j || F[i] == 0) continue;
			cnt = F[i]*j; // Biến tất cả các số i thành j
			for (int k = 0; k <= 9; k++) {
				if (k == i) continue;
				cnt += F[k]*k; // Ngoại trừ số đó ra thì tổng các chữ số khác như thường
			}
			if (cnt % 9 == 0) {
				string t = n;
				for (char &c : t) {
					if (c - '0' == i) c = j + '0';
				}
				if (t[0] != 0) res.push_back(t);
			}
		}
	}
	
	sort(res.begin(), res.end(), greater<string>());
	
	cout << res[0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
