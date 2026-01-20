#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

void testcase() {
	string s, t, v; cin >> s >> t >> v;
	
	int F[105][105];
	int n = s.length();
	int m = t.length();
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i - 1] == t[j - 1]) F[i][j] = F[i - 1][j - 1] + 1;
			else {
				F[i][j] = max(F[i - 1][j], F[i][j - 1]);
			}
		}
	}
	
	string res = "";
	int i = n, j = m;
	
	while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            res.push_back(s[i - 1]);
            i--, j--;
        } 
        else if (F[i - 1][j] > F[i][j - 1]) {
            i--;
        } else {
            j--;
        }
	}
	reverse(res.begin(), res.end());
	
	cout << res << el;
	
	string c = s + '#' + t;
	vector<int> z(c.length(), 0);
	
	// Z
	int L = 0, R = 0;
	for (int i = 0; i < c.length(); i++) {
		if (i <= R) z[i] = min(z[i - L], R - i + 1);
		
		while (c[z[i]] == c[z[i] + i] && z[i] + i < c.length()) ++z[i];
		
		if (i + z[i] - 1 > R) {
			L = i;
			R = i + z[i] - 1;
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
