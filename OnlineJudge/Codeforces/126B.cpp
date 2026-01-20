#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}
const int MAXN = 1e6 + 5;
int F[MAXN];

void testcase() {
	string s; cin >> s;
	int n = s.length();
	F[0] = 0;
	
	// Tien To
	for (int i = 1; i < n; i++) {
		int j = F[i - 1];
		
		while (j > 0 && s[j] != s[i]) j = F[j - 1];
		if (s[j] == s[i]) ++j;
		
		F[i] = j;
	}
	
	// Check
	int j = F[n - 1];
	bool check = false;
	if (j != 0) {
		for (int i = 1; i < n - 1; i++) {
			if (F[i] == j) {
				check = true;
				break;
			}
		}
		if (!check && F[j - 1] != 0) {
		    check = true;
		    j = F[j - 1];
		}
	}
	
	cout << ((check) ? s.substr(0, j) : "Just a legend");
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
