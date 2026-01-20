#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

const int MAXN = 1000005;

bool prime[MAXN];

void sieve() {
	for (int i = 2; i < MAXN; i++) prime[i] = true;
	for (int i = 2; i < MAXN; i++) {
		if (prime[i]) {
			for (int j = i*i; j < MAXN; j += i) prime[j] = false;
		}
	}
}

void testcase() {
	int n; cin >> n;
	vector<int> a(n, 0);
	
	vector<int> pos;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (prime[a[i]]) pos.push_back(i);
	}
	
	if (pos.size() < 2 || a.size() < 2) {
		cout << -1; return;
	}
	sort(pos.begin(), pos.end());
	
	int min = MAXN;
	for (int x = 1; x < pos.size(); x++) {
		if (pos[x] - pos[x-1] < min) {
			min = pos[x] - pos[x-1];
		}
	}
	
	cout << min + 1;
//	for (auto x : pos) cout << x << ' ';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();
	
	sieve();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
