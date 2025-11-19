#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int A[200005];

void testcase() {
    int n, m; 
    cin >> n >> m;

    vector<int> g;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] > 0) g.push_back(A[i]);
    }

    sort(g.begin(), g.end(), greater<int>());

    ll res = 0;

    int take = min(m, (int)g.size());

    for (int i = 0; i < take; i++) {
        res += g[i];
    }

    cout << res;
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
