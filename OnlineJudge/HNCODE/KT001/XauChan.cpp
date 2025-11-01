#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int F['z' + 5] = {};

void testcase() {
	string s; cin >> s;
	for (char c : s) ++F[(int)c];
	bool check = true;
	for (int i = 'a'; i <= 'z'; i++) {
		if (F[i]) {
			if (F[i] & 1) check = false;
		}
	}
	cout << ((check) ? "Yes" : "No");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
