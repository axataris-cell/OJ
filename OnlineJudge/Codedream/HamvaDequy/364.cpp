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

const int MAXN = 1e6 + 5;
bool p[MAXN];

void sieve() {
	for (int i = 2; i <= MAXN; i++) p[i] = false;
	for (int i = 2; i * i <= MAXN; i++) {
		if (p[i]) {
			for (int j = i*i; j <= MAXN; j += i) {
				p[j] = false;
			}
		}
	}
}

bool check(int n) {
	if (n > 0)
}

void testcase() {
	int n; cin >> n;
	if (n > MAXN) {
		
	} else {
		cout << ((p[n]) ? "YES" : "NO");
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
