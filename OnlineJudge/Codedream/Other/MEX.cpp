#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

unordered_map<ll, ll> mp;
ll A[100005];

void testcase() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		++mp[A[i]];
	}
	for (int i = 0; i <= 1e9; i++) {
		if (mp[i] == 0) {
			cout << i;
			break;
		}
	}
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
