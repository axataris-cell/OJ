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

const int MAXN = 1e7 + 5;
bool p[MAXN];

void sieve() {
	for (int i = 2; i < MAXN; i++) p[i] = true;
	for (int i = 2; i * i < MAXN; i++) {
		if (p[i]) {
			for (int j = i * i; j < MAXN; j += i) {
				p[j] = false;
			}
		}
	}
}

bool check(int n) {
	int odd = 0, even = 0;
	while (n != 0) {
		if (n % 10 & 1) ++odd;
		else ++even;
		n /= 10;
	}
	if (odd == even) return false;
	else return true;
}

void testcase() {
	int n; cin >> n; int res = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (check(a[i])) {
			if (a[i] >= MAXN) {
				bool ck = true;
				for (int j = 2; j * j <= a[i]; j++) {
					if (a[i] % j == 0) {
						ck = false;
						break;
					}
				}
				if (ck) ++res;
			} else {
				if (p[a[i]]) ++res;
			}
		}
	}
	cout << res;
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
