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
void testcase() {
    string meow = "meow";
    int n; cin >> n;
    string s; cin >> s;
    for (auto &c : s) c = tolower(c);
    string r = "";
    for (int i = 0; i < n;) {
        int j = i + 1;
        while (j < n && s[j] == s[i]) ++j;
        r += s[i];
        i = j;
    }
    cout << (r == meow ? "YES" : "NO") << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}