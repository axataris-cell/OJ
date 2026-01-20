#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

const int MAXN = 1e6;
unordered_map<int, bool> p;

void testcase() {
	for (int i = 2; i <= MAXN; i++) p[i] = true;
	for (int i = 2; i * i <= MAXN; i++) {
		if (p[i]) {
			for (int j = i*i; j <= MAXN; j += i) p[j] = false;
		}
	}
	
	// ----------- Print Tests -------------
	
	for (int i = 2; i <= 1e6; i++) cout << i << ' ' << ((p[i]) ? "YES" : "NO") << el;
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
