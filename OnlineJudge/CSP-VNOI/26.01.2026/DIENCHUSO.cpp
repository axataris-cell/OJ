#include <bits/stdc++.h>
#include <chrono>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

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

const int MAXN = 1e7 + 5;

int n, m;
ll k;

struct query {
    int l, r, c;
};

vector<query> q;
int par[MAXN];
int digit[MAXN];

int find(int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}

void testcase() {
	cin >> n >> m >> k;
    q.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r >> q[i].c;
    }
    
    for (int i = 1; i <= n + 1; i++) par[i] = i;

    for (int i = m - 1; i >= 0; i--) {
        int l = q[i].l;
        int r = q[i].r;
        int c = q[i].c;

        int x = find(l);
        while (x <= r) {
            digit[x] = c;
            par[x] = x + 1;
            x = find(x);
        }
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res = (res * 10 + digit[i]) % k;
    }
    
    cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
