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

void testcase() {
	int n; cin >> n;
	string res = ""; int tot = 0;
	while (n - tot > 9) {
		res.push_back('9');
		tot += 9;
	}
	if (n - tot > 0) {
		char x = (char)(n - tot + '0');
		res.push_back(x);
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
