#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define int long long
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "F"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    string s; cin >> s;
    deque<pii> dq;
    int inv = 0, ones = 0;
    int i = 0;
    while (i < n && a[i] == 0) i++;
    while (i < n) {
        int c = 0, d = 0;
        while (i < n && a[i] == 1) {c++; ones++; i++;}
        while (i < n && a[i] == 0) {d++; inv += ones; i++;}
        if (c > 0 && d > 0) {
            dq.push_back({c, d});
        }
    }
    int cnt1 = 0, cnt0 = 0;
    for (auto [o, z] : dq) {
        cnt1 += o;
        cnt0 += z;
    }

    cout << inv;

    for (char ch : s) {
        if (inv == 0 || dq.empty()) {
            cout << ' ' << 0;
            continue;
        }

        if (ch == '1') {
            inv -= cnt0;
            cnt1--;
            dq.front().first--;
            if (dq.front().first == 0) {
                cnt0 -= dq.front().second;
                dq.pop_front();
            }
        } else {
            inv -= cnt1;
            cnt0--;
            dq.back().second--;
            if (dq.back().second == 0) {
                cnt1 -= dq.back().first;
                dq.pop_back();
            }
        }
        cout << ' ' << inv;
    }
    cout << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}