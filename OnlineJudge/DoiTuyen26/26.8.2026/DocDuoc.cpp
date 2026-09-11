#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define int long long
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "DocDuoc"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];

    pqueue<int,vector<int>,greater<int>> pq;
    int res = 0;
    int curHealth = 0;
    for(int i = 1; i <= n; i++) {
        if (a[i] >= 0) {
            curHealth += a[i];
            ++res;
            continue;
        }
        if (curHealth + a[i] < 0) {
            if (pq.size() && a[i] > pq.top() && curHealth - pq.top() + a[i] >= 0) {
                curHealth += a[i] - pq.top();
                pq.pop();
                pq.push(a[i]);
            }
        } else {
            curHealth += a[i];
            ++res;
            pq.push(a[i]);
        }
    }
    cout << res;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}