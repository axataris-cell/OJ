#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int A[105] = {};

void testcase() {
	int n; cin >> n;
	
	// Index, Value
	pair<int, int> mx = {0, 0};
	pair<int, int> mn = {0, n + 1};
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		if (mx.second < A[i]) mx = {i, A[i]};
		if (mn.second > A[i]) mn = {i, A[i]};
	}
	cout << "OUTPUT" << el;
	cout << mx.second << ' ' << mx.first << el;
	cout << mn.second << ' ' << mn.first << el;
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
