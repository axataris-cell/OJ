#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

const int MAXN = 1e5 + 5;
int A[MAXN] = {};
int S[MAXN] = {};
int X[MAXN] = {}; //MAX
int N[MAXN] = {}; //MIN

void testcase() {
	int n; cin >> n;
	S[0] = 0;
	
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		S[i] = A[i] + S[i - 1];
		X[i] = max(X[i - 1], S[i]);
		N[i] = min(N[i - 1], S[i]);
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
