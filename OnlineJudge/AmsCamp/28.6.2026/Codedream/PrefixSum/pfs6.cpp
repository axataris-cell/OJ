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
	string s; cin >> s;
	
	umap<ll, ll> cnt;
	ll res = 0;
	ll prefix = 0;
	
	cnt[0] = 1;
	
	for (char c : s) {
		if (c == '1') ++prefix;
		else --prefix;
		
		res += cnt[prefix];
		++cnt[prefix];
	}
	
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
