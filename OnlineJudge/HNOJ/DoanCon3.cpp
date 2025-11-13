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
int S[100005] = {};
int M[100005] = {};

void testcase() {
	int n; cin >> n;
	S[0] = 0;
	M[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		S[i] = S[i - 1] + A[i];
		M[i] = min(S[i], M[i - 1]);
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
