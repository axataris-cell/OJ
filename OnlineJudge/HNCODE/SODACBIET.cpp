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

int total(int n) {
	int res = 0;
	while (n != 0) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

const int MAXN = 1e7 + 5;
vector<vector<int>> F(65);

void testcase() {
	int l, r; cin >> l >> r;
	
	int res = 0;
	for (auto v : F) {
		if (v.size() < 2) continue;
		 
		int x = 0, y = v.size() - 1;
		while (v[x] < l) ++x;
		while (v[y] > r) --y;
		
		while (x <= y) {
			res = max(res, v[y] - v[x]);
			++x; --y;
		}
	}
	
	cout << res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();
	
	for (int i = 1; i <= MAXN; i++) {
		F[total(i)].push_back(i);
	}

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
