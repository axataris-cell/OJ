#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "MIMO"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n, m, k; cin >> n >> m >> k;

    vector<int> cols;
    cols.reserve(k);

    int cntcol2 = 0;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        if (y == 2) {
            cntcol2++;
        }
        if (y >= 2) {
            cols.push_back(y);
        }
    }

    if (n == 1) {
        if (cntcol2 % 2 != 0) {
            cout << "Mimo" << el;
        } else {
            cout << "Yuyu" << el;
        }
    } else {
        sort(cols.begin(), cols.end());
        bool mimo = false;
        
        int i = 0;
        while (i < cols.size()) {
            int j = i;
            while (j < cols.size() && cols[j] == cols[i]) {
                j++;
            }
            int count = j - i;
            if (count % 2 != 0) {
                mimo = true;
                break;
            }
            i = j;
        }

        if (mimo) {
            cout << "Mimo" << el;
        } else {
            cout << "Yuyu" << el;
        }
    }
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}