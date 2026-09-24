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
	int n; cin >> n;
	++n;
	auto check = [&](int x) -> bool {
		vector<int> mp(10, 0);
		while (x > 0) {
			int k = x % 10;
			++mp[k];
			x /= 10;
		}
		for (int i = 0; i < 10; i++) {
			if (mp[i] > 1) return false;
		}
		return true;
	};
	while (!check(n)) {
		++n;
	}
	cout << n;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}

