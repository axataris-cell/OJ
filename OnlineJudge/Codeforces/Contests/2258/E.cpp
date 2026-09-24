#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "E"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+50,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;

vector<int> candidate;
int spf[MAXN];
int at[MAXN];
void sieve() {
    for(int i = 2; i < MAXN; i++) spf[i]= i;
    for(int i=1;i*i<MAXN;i++){
        if (spf[i] ==i) {
            for(int j = i * i; j < MAXN; j+=i){
                spf[j] = i;
            }
        }
    }
}

vector<vector<int>> pos;
vector<bool> achievable;

void testcase() {
    int n; cin >> n;
    vector<int> a(n + 1,0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int M = 0;
    while (M < candidate.size() && candidate[M] <= n) {
        M++;
    }

    for (int j = 0; j <= M && j < candidate.size(); j++) {
        pos[j].clear();
        achievable[j] = false;
    }

    for (int i = 1; i <= n; i++) {
        int x = a[i];
        while (x > 1) {
            int p = spf[x];
            int pw = 1;
            while (x % p == 0) {
                pw *= p;
                x /= p;
                if (at[pw] != -1 && at[pw] <= M) {
                    pos[at[pw]].push_back(i);
                }
            }
        }
    }

    for (int r = 1; r <= n; r++) {
        int j = 0;
        while (j <= M && j < candidate.size() && a[r] % candidate[j] == 0) {
            j++;
        }
        if (j > M || j >= candidate.size()) continue;

        achievable[j] = true;

        int l = r;
        while (true) {
            auto it = lower_bound(pos[j].begin(), pos[j].end(), l);
            if (it == pos[j].begin()) {
                break;
            }
            int p = *(--it);

            l = p;
            int x = j + 1;
            while (x <= M && x < candidate.size()) {
                auto it2 = lower_bound(pos[x].begin(), pos[x].end(), p);
                if (it2 != pos[x].end() && *it2 <= r) {
                    x++;
                } else {
                    break;
                }
            }

            j = x;
            if (j <= M && j < candidate.size()) {
                achievable[j] = true;
            } else {
                break;
            }
        }
    }

    vector<int> ans;
    for (int j = 0; j <= M && j < candidate.size(); j++) {
        if (achievable[j]) {
            ans.push_back(candidate[j]);
        }
    }

    cout << ans.size() << el;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;

    sieve();
    for(long long i = 2; i < MAXN; i++) {
        if (spf[i] != i) continue;
        for(long long j= i; j < MAXN; j *= i) candidate.push_back((int)j);
    }
    sort(candidate.begin(),candidate.end());
    for(int i = 0; i < candidate.size();i++) {
        at[candidate[i]]=i;
    }
    pos.resize(candidate.size());
    achievable.resize(candidate.size());

    while(t--)testcase();
    return 0;
}