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
	
	ll t = 1LL * (n - 1) * (n - 2) * (n - 3) / 6;
	
	ll b = 0;
	for (int i = (n + 1) / 2; i <= n - 3; i++) {
		int s = n - i;
		b += 1LL * (s - 1) * (s - 2) / 2;
	}
	
	cout << t - 4 * b;
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
