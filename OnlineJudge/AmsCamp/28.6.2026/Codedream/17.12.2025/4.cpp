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

const int MAXN = 1e7 + 5;
bool p[MAXN + 5];

void sieve() {
	for (int i = 2; i <= MAXN; i++) p[i] = true;
	for (int i = 2; i * i <= MAXN; i++) {
		if (p[i]) {
			for (int j = i * i; j <= MAXN; j += i) {
				p[j] = false;
			}
		}
	}
}

bool check(int x) {
	int t = x;
	while (t != 0) {
		if (!p[t]) return false;
		t /= 10;
	}
	bool c = false;
	for (int i = 0; i <= 9; i++) {
		if (p[x * 10 + i]) c = true;
	}
	if (c) return true;
	else return false;
}

void testcase() {
	int n; cin >> n;
	vector<int> a(n + 1), f(n + 1);
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = f[i - 1];
		if (check(a[i])) ++f[i];
	}
	
	int m; cin >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		cout << f[v] - f[u - 1] << el;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();
	sieve();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
