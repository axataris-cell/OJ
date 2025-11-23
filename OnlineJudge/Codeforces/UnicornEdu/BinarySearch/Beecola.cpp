#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}


int A[100005];

void testcase() {
    int n; 
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];

    sort(A, A + n);

    int q;
    cin >> q;

    while (q--) {
        long long m;
        cin >> m;

        int ans = upper_bound(A, A + n, m) - A;
        cout << ans << "\n";
    }
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
