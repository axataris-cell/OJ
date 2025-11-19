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
int Z[MAXN];
int F[MAXN];

void testcase() {
	string s; cin >> s;
	F[0] = 0;
	Z[0] = 0;
	
	// Tien To
	for (int i = 1; i < s.length(); i++) {
		int j = F[i - 1];
		
		while (j > 0 && s[j] != s[i]) j = F[j - 1];
		if (s[j] == s[i]) ++j;
		
		F[i] = j;
	}
	
	// Ham Z
	int L = R = 0;
	for (int i = 1; i < s.length(); i++) {
		if (i <= R) 
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
