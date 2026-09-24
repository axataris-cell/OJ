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
	int n;
	cin >> n;
    string x;
    cin >> x;

    bool possible = true;
    if (n % 2 == 1) {
        if (x[0] == 'b') {
            possible = false;
        }
        
        for (int i = 1; i + 1 < n; i += 2) {
            if (x[i] != '?' && x[i+1] != '?' && x[i] == x[i+1]) {
                possible = false;
            }
        }
    } else {
        for (int i = 0; i + 1 < n; i += 2) {
            if (x[i] != '?' && x[i+1] != '?' && x[i] == x[i+1]) {
                possible = false;
            }
        }
    }

    if (possible) {
        cout << "YES" << el;
    } else {
        cout << "NO" << el;
    }
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
