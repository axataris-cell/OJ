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
const int INF=4e18,MAXN=2e5+5,LOG=20,MOD=1e9+7,BASE=113,BLOCK=400;

bool spf[MAXN];

void testcase() {
    int x, y; cin >> x >> y;
    for (int i = 1; i <= max(x, y); i++) {
        if (!spf[i]) continue;
        int cnt[2] = {0, 0};
        {
            int cur = x;
            while (cur % i == 0 && cur > 0) {
                ++cnt[0];
                cur /= i;
            }
        }
        {
            int cur = y;
            while (cur % i == 0 && cur > 0) {
                ++cnt[1];
                cur /= i;
            }
        }
        if (cnt[0] < cnt[1]) {
            cout << "NO" << el;
            return;
        }
    }

    cout << "YES" << el;
}
int32_t main() {
    fastio file();

    for (int i = 2; i < MAXN; i++) spf[i] = true;
    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i]) {
            for (int j = i * i; j < MAXN; j += i) spf[j] = false;
        }
    }
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}