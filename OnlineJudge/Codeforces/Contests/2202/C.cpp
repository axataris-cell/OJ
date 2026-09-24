#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 1e9
#define LINF 1e18

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	if (FILE *f = fopen(FILENAME".INP", "r")) {
		fclose(f);
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
}

void testcase() {
	int n;cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> nxt(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int p = i - 1;
        while (p > 0 && a[p] != a[i] - 1) {
            if (a[p] < a[i] - 1 || nxt[p] == 0) {
                p = 0;
                break;
            }
            p = nxt[p];
        }
        
        if (p > 0 && a[p] == a[i] - 1) {
            nxt[i] = p;
        } else {
            nxt[i] = 0;
        }
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) {
        ll g = i - nxt[i];
        res += g * (n - i + 1);
    }
    cout << res << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
