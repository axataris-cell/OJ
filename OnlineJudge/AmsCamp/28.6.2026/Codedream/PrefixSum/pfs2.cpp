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
    vector<ll> a(n + 1), f(n + 1);
    f[0] = 0;
    vector<ll> curmax(n + 1, -INT_MAX);
    ll res = 0;
    
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	f[i] = f[i - 1] + a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		curmax[i] = max(curmax[i - 1], f[i]);
		res = min(res, f[i] - curmax[i]);
	}
	
	cout << max(f[n] - res, 0LL);
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
