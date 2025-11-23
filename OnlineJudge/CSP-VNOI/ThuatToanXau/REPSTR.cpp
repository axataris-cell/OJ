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
	for (int i = 1; i < n; i++) {
		int j = F[i - 1];
		
		while (j > 0 && s[j] != s[i]) j = F[j - 1];
		if (s[j] == s[i]) ++j;
		
		F[i] = j;
	}
	
	int l = 1;
	for (int i = n - 1; i >= 0; i--) {
		if (F[i] != F[i - 1] + 1 || F[i - 1] == 0) {
			l = max(l, i);
			break;
		}
	}
	
	for (int i = 0; i < n; i++) cout << F[i] << ' ';
	cout << el << l << el;
	
	cout << s.substr(0, l);
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
