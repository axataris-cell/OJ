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
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int first = -1, last = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			first = i;
			break;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] > 0) {
			last = i;
			break;
		}
	}
	if (first == -1 || last == -1) {
		cout << "-1 -1";
	}
	else cout << first + 1 << ' ' << last + 1;
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
