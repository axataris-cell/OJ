#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

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

#define int long long

struct Casino {
    int l, r, real;
};

void testcase() {
    int n, k;
    cin >> n >> k;

    vector<Casino> a(n);

    for (auto &x : a) {
        cin >> x.l >> x.r >> x.real;
    }

    sort(a.begin(), a.end(), [](const Casino &x, const Casino &y) {
        return x.l < y.l;
    });

    int cur = k;

    for (auto &x : a) {
        if (x.l <= cur && cur <= x.r) {
            cur = x.real;
        }
    }

    cout << cur << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
