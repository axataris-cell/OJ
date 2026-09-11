#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "PALIN"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n; cin >> n;
    string start; cin >> start;
    queue<string> q;
    map<string, bool> vis;
    map<string, int> dist;
    auto check=[&](int l, int r, string &s) -> bool {
        while (l <= r) {
            if (s[l] != s[r]) return false;
            ++l;
            --r;
        }
        return true;
    };
    vis[start] = true;
    dist[start] = 0;
    q.push(start);
    while (q.size()) {
        string s = q.front(); q.pop();
        for(int i = 0;i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                if (!check(i, j, s)) continue;
                string nxt = "";
                for(int k = 0 ;k < s.size(); k++) {
                    if (k >= i && k <= j) continue;
                    nxt += s[k];
                }

                if (vis[nxt]) continue;

                dist[nxt] = dist[s] + 1;
                vis[nxt] = true;

                q.push(nxt);
            }
        }
    }

    cout << dist[""];
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}