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

const int MAXN = 1e5 + 5;

vector<int> ST(4 * MAXN, 0);
vector<int> lazy(4 * MAXN, 0);

void push(int id, int l, int r) {
    if (!lazy[id]) return; // bit = 0

    int mid = (l + r) / 2;

    // flip left child
    ST[id << 1] = (mid - l + 1) - ST[id << 1];
    lazy[id << 1] ^= 1;

    // flip right child
    ST[id << 1 | 1] = (r - mid) - ST[id << 1 | 1];
    lazy[id << 1 | 1] ^= 1;

    lazy[id] = 0;
}

void update(int id, int l, int r, int a, int b) {
    if (l > b || r < a) return;

    if (l >= a && r <= b) {
        ST[id] = (r - l + 1) - ST[id];
        lazy[id] ^= 1;
        return;
    }

    push(id, l, r);

    int mid = (l + r) / 2;
    update(id << 1, l, mid, a, b);
    update(id << 1 | 1, mid + 1, r, a, b);

    ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

int query(int id, int l, int r, int a, int b) {
    if (l > b || r < a) return 0;

    if (l >= a && r <= b) return ST[id];

    push(id, l, r);

    int mid = (l + r) / 2;
    return query(id << 1, l, mid, a, b) + query(id << 1 | 1, mid + 1, r, a, b);
}

void testcase() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int t, a, b; cin >> t >> a >> b;
		if (t == 0) {
			update(1, 1, n, a, b);
		} else if (t == 1) {
			cout << query(1, 1, n, a, b) << el;
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
