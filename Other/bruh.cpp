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

void testcase() {
	int n; cin >> n;
	cin.ignore();
	string s; getline(cin, s);
	cout << n << ' ' << s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();
	
	int t = 1;
	while (t--) testcase();

	return 0;
}
