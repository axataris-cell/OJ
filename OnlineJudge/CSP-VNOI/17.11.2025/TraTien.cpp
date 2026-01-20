#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

ll k[100005] = {}; //So cach
ll f[100005] = {}; //So dong xu can doi
ll a[105] = {};

void testcase() {
	ll n; cin >> n;
	for (int i = 1; i <= 100; i++) {
		a[i] = i*i;
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
