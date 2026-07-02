#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}
int A[10000005] = {};
int F[177013];
void testcase() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		++F[A[i] % 177013];
	}
	for (int i = 0; i < 177013; i++) {
		if (F[i] > 0) {
			for (int j = 1; j <= F[i]; j++) cout << i << ' ';
		}
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
