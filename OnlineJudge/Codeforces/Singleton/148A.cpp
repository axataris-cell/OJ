#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME ""
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
	int div[4]; for (int i = 0; i < 4; i++) cin >> div[i];
	int d; cin >> d;
	int res = 0;
	auto lcm = [&](int x, int y) -> int {
		return x * y / __gcd(x, y);
	};
	for (int mask = 1; mask < (1 << 4); ++mask) {
		int cur = 1;
		for (int i = 0; i < 4; i++) if ((mask >> i) & 1) {
			cur = lcm(cur, div[i]);
		}
		int cnt = d / cur;

		if (__builtin_popcount(mask) & 1) res += cnt;
		else res -= cnt;
	}
	cout << res;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}

