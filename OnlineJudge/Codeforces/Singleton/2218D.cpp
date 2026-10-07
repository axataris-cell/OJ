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
const int INF=2e9,MAXN=1e4+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;

vector<int> primes;
vector<int> res;
void testcase() {
	int n; cin >> n;
	
	for (int i = 0; i < n; i++) {
		cout << res[i] << ' ';
	}
	
	cout << el;
}
int32_t main() {
    fastio file();
    
    for (int i = 2; i <= 50; i++) {
    	int cnt = 0;
    	for (int j = 1; j <= i; j++) {
    		if (i % j) continue;
    		++cnt;
		}
    	if (cnt <= 2) primes.push_back(i);
	}
	
	int k = primes.size();
	auto val = [&](int mask) ->int {
		int cur = 1;
		for (int i = 0; i < k; i++) {
			if (mask >> i & 1) {
				cur *= primes[i];
			}
		}
		return cur;
	};
	
	vector<bool> vis(1 << k, false);

	res.push_back(1);
	int lastm = 0;
	
	for (int i = 1; i < MAXN; i++) {
		for (int mask = (1 << k) - 1; mask > 0; --mask) {
			if (vis[mask & lastm]) continue;
			
			int v = val(mask);
			
			res.push_back(v);
			
			vis[mask & lastm] = true;
			lastm = mask;
			
			break;
		}
	}
	
//	cout << res.size() << el;
	
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}


