#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "B"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<string> r(k, "");
    for(int i = 0; i < n; i++) {
        int rotation = i % k;
        r[rotation] += s[i];
    }
    for(auto &str : r) {
        int m = str.size();
        for(int i = 0; i < m - 1; i++) {
            if (str[i] == '1') {
                str[i] = '0';
                str[i + 1] = char(1 - (str[i + 1] - '0') + '0');
            }
        }
        if (str[m - 1] != '0') {
            cout << "NO" << el;
            return;
        }
    }

    cout << "YES" << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}