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
    int n, k;
    cin >> n >> k;

    vector<ll> a(n), b(n);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    priority_queue<pair<ll, pair<int,int>>> pq;

    int init = min(n, k);
    for (int i = 0; i < init; i++) {
        pq.push({a[i] + b[0], {i, 0}});
    }

    while (k--) {
        auto [sum, ij] = pq.top(); 
        pq.pop();
        auto [i, j] = ij;

        cout << sum << (k ? ' ' : el);

        if (j + 1 < n) {
            pq.push({a[i] + b[j + 1], {i, j + 1}});
        }
    }
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
