#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "1833E"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n; cin >> n;
    vector<set<int>> g(n + 1);
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        g[i].insert(x);
        g[x].insert(i);
    }
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && g[i].size() == 1) {
            ++cnt1;
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while (q.size()) {
                int u = q.front(); q.pop();
                for(int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ++cnt2;
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while (q.size()) {
                int u = q.front(); q.pop();
                for(int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    cout << cnt2 + (cnt1 > 0) << ' ' << cnt1 + cnt2 << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}