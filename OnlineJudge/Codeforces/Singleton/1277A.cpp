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

vector<int> num;

void testcase() {
    int n; cin >> n;
    cout << upper_bound(num.begin(), num.end(), n) - num.begin() << el;
}

int32_t main() {
    fastio file();

    for (int d = 1; d <= 9; d++) {
        string r = "";
        for (int i = 1; i <= 9; i++) {
            r += char(d + '0');
            num.push_back(stoll(r));
        }
    }
    sort(num.begin(), num.end());

    // for (auto d : num) cout << d << ' ';
    // return 0;

    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}