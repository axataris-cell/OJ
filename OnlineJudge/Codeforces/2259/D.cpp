#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "D"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n;cin >> n;
    
    vector<int> a(n);
    vector<int> cnt(n + 2, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= n + 1) {
            cnt[a[i]]++;
        }
    }
    
    if (cnt[0] == 0) {
        cout << "YES" << el;
        cout << string(n, 'A') << el;
        return;
    }

    if (cnt[0] == 1) {
        cout << "NO" << el;
        return;
    }

    int m = 1;
    while (m <= n + 1 && cnt[m] >= 2) {
        m++;
    }
    
    vector<int> seen(n + 2, 0);
    string ans = "";
    
    for (int i = 0; i < n; i++) {
        if (a[i] < m) {
            seen[a[i]]++;
            if (seen[a[i]] == 1) {
                ans += 'A';
            } else {
                ans += 'B';
            }
        } else {
            ans += 'C';
        }
    }
    
    cout << "YES" << el;
    cout << ans << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}