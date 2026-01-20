#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

void testcase() {
	int n; cin >> n;
	int a, b; cin >> a >> b;
	vector<int> s(n, 0); // aaa....aaaa
	
	int cnt = -1;
	for (int i = 0; i < n; i++) {
		++cnt;
		s[i] = cnt;
		if (cnt == b - 1) {
			cnt = -1;
		}
	}
	
	for (auto x : s) cout << (char)(x + 'a');
	cout << el;
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
