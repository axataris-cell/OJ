#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}
// ???? sao ko ac
int A[100005] = {}, B[100005] = {};

void testcase() {
	int m, n; cin >> m >> n;
	for (int i = 1; i <= m; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) cin >> B[i];
	vector<int> ind;
	
	int i = 1, j = 1;
	while (i <= m && j <= n) {
		if (A[i] == B[j]) {
			ind.push_back(j);
			++i;
			++j;
		} else {
			++j;
		}
//		cout << i << ' ' << j << el;
	}
	if (i == m + 1 && ind.size() == m) {
		cout << "YES" << el;
		for (int x : ind) cout << x << ' ';
	} else {
		cout << "NO";
	}
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
