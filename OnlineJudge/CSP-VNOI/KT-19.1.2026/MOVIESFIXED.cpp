#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

#define FILENAME "MOVIES"

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

struct film {
	int s, e;
};

void testcase() {
    int n;
    cin >> n;

    vector<film> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].s >> a[i].e;

    sort(a.begin(), a.end(), [](film x, film y) {
        return x.e < y.e;
    });

    int res = 0;
    int last_end = -1;

    for (auto f : a) {
        if (f.s >= last_end) {
            ++res;
            last_end = f.e;
        }
    }

    cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
