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
	string t; cin >> t;
	int n = s.length();
	int m = t.length();
	
	F[0] = 0;
	for (int i = 1; i < n; i++) {
		int j = F[i - 1];
		
		while (j > 0 && s[j] != s[i]) j = F[j - 1];
		if (s[j] == s[i]) ++j;
		
		F[i] = j;
	}
	
	vector<int> pos;
	int j = 0;
	for (int i = 0; i < m; i++) {
		while (j > 0 && s[j] != t[i]) j = F[j - 1];
		if (s[j] == t[i]) ++j;
		
		if (j == n) {
			pos.push_back(i - n + 1);
			j = F[j - 1];
		}
	}
	
	cout << pos.size() << el;
	for (auto x : pos) cout << x << ' ';
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
