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
	int A[3];
	for (int i = 0; i < 3; i++) cin >> A[i];
	sort(A, A + 3, greater<int>());
	for (int i = 0; i < 3; i++) cout << A[i] << ' ';
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
