#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "749A"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n; cin >> n;
    if (n % 2 == 0) {
        cout << n / 2 << el;
        for (int i = 1; i <= n / 2; i++) cout << 2 << ' ';
    } else {
        if (n == 3) {cout << 1 << el << 3; return;}
        cout << (n - 3) / 2 + 1 << el;
        for (int i = 1; i <= (n - 3) / 2; i++) cout << 2 << ' ';
        cout << 3;
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}