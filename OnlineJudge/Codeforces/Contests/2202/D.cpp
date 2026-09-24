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
	int n, k;
	cin >> n >> k;

    if (k < n || k > 2 * n - 1) {
        cout << "NO" << endl;
        return;
    }

    int m = k - n;
    vector<int> res;

    if (m == 0) {
        for (int i = 1; i <= n; i++) {
            res.push_back(i);
            res.push_back(i);
        }
    } else {
        res.push_back(1);
        res.push_back(2);

        for (int i = 1; i <= m - 1; i++) {
            res.push_back(i + 2);
            res.push_back(i);
        }

        res.push_back(m);
        res.push_back(m + 1);
        
        for (int i = m + 2; i <= n; i++) {
            res.push_back(i);
            res.push_back(i);
        }
    }
	
	cout << "YES" << el;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    cout << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
