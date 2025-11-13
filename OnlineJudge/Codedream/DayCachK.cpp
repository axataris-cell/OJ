#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int A[100005] = {};
int S[100005][100005] = {};

void testcase() {
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];
	
	 
	for (int i = 1; i <= k - 1; i++) {
		int p = 1;
		for (int j = i; j <= n; j += k) {
			
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
