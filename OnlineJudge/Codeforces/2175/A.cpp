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
	int n; cin >> n;
	unordered_map<ll, ll> mp;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		++mp[a[i]];
	}
	ll cnt = 0;
	for (auto x : mp) ++cnt;
	
	if (mp[cnt] == 0) {
		ll cur = cnt; ++cnt;
		while (cur != cnt) {
			cur = cnt;
			if (mp[cnt] == 0) ++cnt;
		}
		cout << max(cur, cnt) << el;
	} else {
		cout << cnt << el;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
