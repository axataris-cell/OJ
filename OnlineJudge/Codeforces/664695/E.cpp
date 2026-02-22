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

const int MAXA = 100000;

void testcase() {
	int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> pos(MAXA + 1);

    for (int i = 1; i <= n; i++) {
        pos[a[i]].push_back(i);
    }

    vector<vector<int>> divPos(MAXA + 1);

    for (int val = 1; val <= MAXA; val++) {
        if (pos[val].empty()) continue;
        for (int d = 1; d * d <= val; d++) {
            if (val % d == 0) {
                divPos[d].insert(divPos[d].end(), pos[val].begin(), pos[val].end());
                if (d * d != val) {
                    divPos[val / d].insert(divPos[val / d].end(), pos[val].begin(), pos[val].end());
                }
            }
        }
    }

    for (int d = 1; d <= MAXA; d++) {
        if (!divPos[d].empty()) sort(divPos[d].begin(), divPos[d].end());
    }

    vector<int> pref(n + 1, 0), suf(n + 2, 0);

    {
        vector<int> bestAt(n + 1, 0);

        for (int d = MAXA; d >= 1; d--) {
            auto &v = divPos[d];
            if ((int)v.size() < 2) continue;

            for (int idx = 1; idx < (int)v.size(); idx++) {
                bestAt[v[idx]] = max(bestAt[v[idx]], d);
            }
        }

        for (int i = 1; i <= n; i++) {
            pref[i] = max(pref[i - 1], bestAt[i]);
        }
    }

    {
        vector<int> bestAt(n + 2, 0);

        for (int d = MAXA; d >= 1; d--) {
            auto &v = divPos[d];
            if ((int)v.size() < 2) continue;

            for (int idx = (int)v.size() - 2; idx >= 0; idx--) {
                bestAt[v[idx]] = max(bestAt[v[idx]], d);
            }
        }

        for (int i = n; i >= 1; i--) {
            suf[i] = max(suf[i + 1], bestAt[i]);
        }
    }

    int ans = 0;
    for (int j = 2; j <= n - 2; j++) {
        ans = max(ans, pref[j] + suf[j + 1]);
    }

    cout << ans << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
