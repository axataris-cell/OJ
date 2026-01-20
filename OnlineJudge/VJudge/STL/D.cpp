#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;
using pii = pair<int,int>;
using pll = pair<long long,long long>;

void testcase() {
    int n, q; cin >> n >> q;
    vector<vector<int>> a(n);

    while (q--) {
        int t; cin >> t;

        if (t == 0) {
            int x, y; cin >> x >> y;
            a[x].push_back(y);
        } 
        else if (t == 1) {
            int x; cin >> x;
            bool first = true;
            for (int k : a[x]) {
                if (!first) cout << ' ';
                cout << k;
                first = false;
            }
            cout << el;
        } 
        else {
            int x; cin >> x;
            a[x].clear();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    testcase();
    return 0;
}
