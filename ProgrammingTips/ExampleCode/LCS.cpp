#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

// Longest Common String / Segment
int f[3001][3001] = {};

void testcase() {
	string a, b; cin >> a >> b;
	string c = "";
	
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i - 1] == b[j - 1]) {
				f[i][j] = f[i - 1][j - 1] + 1;
			} else {
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			}
		}
	}
	
	// Truy ngược lại tìm xâu con chung
    string res = "";
    int i = a.length(), j = b.length();

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            res.push_back(a[i - 1]);
            i--, j--;
        } 
        else if (f[i - 1][j] > f[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(res.begin(), res.end());
    
    cout << res;
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
