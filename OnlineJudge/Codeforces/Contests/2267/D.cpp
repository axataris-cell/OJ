#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME ""
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
	int n; cin >> n;
    
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = (i + 1) % 2;
    }

    sort(a.begin(), a.end());

    vector<int> P(n);
    for (int i = 0; i < n; i++) {
        P[i] = a[i].second;
    }

    bool res = true;
    for (int j = 1; j <= n; j++) {
        if ((n - j) % 2 == 0) {
            if (j == 1) {
                if (P[0] != 1) {
                    res = false;
                    break;
                }
            } else {
                if (P[j - 1] == P[j - 2]) {
                    res = false;
                    break;
                }
            }
        }
    }
    
    cout << (res ? "YES" : "NO") << el;
	
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}


