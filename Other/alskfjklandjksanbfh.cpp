#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
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
// LCS

int f[1005][1005];
void testcase() {
	string a, b; cin >> a >> b;
	int n = a.length(), m = b.length();
	
	for (int i = 0; i <= n; i++) {
		f[i][0] = 0;
	}
	for (int i = 0; i <= m; i++) {
		f[0][i] = 0;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i - 1] == b[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
			else {
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			}
		} 
	}
	
	string res = "";
	int l = n, r = m;
	
	while (l != 0 && r != 0) {
		if (a[l - 1] == b[r - 1]) {
			res += a[l - 1];
			--l; --r;
		} else {
			if (f[l - 1][r] > f[l][r - 1]) {
				--l;
			} else {
				--r;
			}
		}
	}
	
	reverse(res.begin(), res.end());
	
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
