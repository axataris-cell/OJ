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

int F[3003][3003] = {};

void testcase() {
	string a, b; cin >> a >> b;
	string c = "";
	
	int n = a.length();
	int m = b.length();
	
	for (int i = 0; i <= n; i++) F[i][0] = i;
	for (int j = 0; j <= m; j++) F[0][j] = j;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i - 1] == b[j - 1]) F[i][j] = F[i - 1][j - 1] + 1;
			else {
				F[i][j] = min(F[i - 1][j], F[i][j - 1]) + 1;
			}
		}
	}
	
    int i = n, j = m;

    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            c.push_back(a[i-1]);
            i--; j--;
        } else if (F[i-1][j] < F[i][j-1]) {
            c.push_back(a[i-1]);
            i--;
        } else {
            c.push_back(b[j-1]);
            j--;
        }
    }
    while (i > 0) {
    	c.push_back(a[i - 1]); --i;
	}
	while (j > 0) {
		c.push_back(b[j - 1]); --j; 
	}
    
    reverse(c.begin(), c.end());
    
    cout << c;
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
