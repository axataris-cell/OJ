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
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
struct Fenwick {
	vector<int> bit;
	int n;
	
	Fenwick(int sz) : n(sz), bit(sz + 1, 0) {}
	
	void update(int pos, int val) {
		for (; pos <= n; pos += pos & (-pos)) bit[pos] += val;
	}
	
	int k_pos(int k) {
		int pos = 0;
		int sum = 0;
		
		for (int pw = 1 << __lg(n); pw; pw >>= 1) {
			int nxt = pos + pw;
			if (nxt <= n && sum + bit[nxt] < k) {
				pos = nxt;
				sum += bit[nxt];
			}
		}
		
		return pos + 1;
	}
};

void testcase() {
    int n, k; cin >> n >> k;
    
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int res = 0;

    if (n >= 2 * k - 1) {
        for (int i = k; i <= n - k + 1; i++) {
            res += a[i];
        }
    }

    int s = min(n, 2 * k - 2);
    for (int m = s; m >= k; m--) {
        int l = a[n - m + k];
        int r = a[m - k + 1];
        res += max(l, r);
    }

    cout << res << el;
}

int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}


