#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int A[2*100005] = {};
map<int, int> mp;

void testcase() {
	int n; cin >> n;
	int mx = 0;
	int b = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		++mp[A[i]];
	}
	for (auto x : mp) {
		++cnt;
		if (mp[x.first] > mx) {
			mx = max(mx, mp[x.first]);
			b = x.first;
		}
	}
	cout << cnt << ' ' << b;
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
