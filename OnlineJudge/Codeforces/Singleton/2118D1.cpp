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
void testcase() {
	int n, k; cin >> n >> k;
	vector<int> p(n + 1,0), d(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	for(int i = 1; i <= n; i++) cin >> d[i];
	vector<int> cyc(n + 1, false);
	{
		vector<vector<int>> vis(2, vector<int>(n + 1, 0));
		vector<int> left(n + 1, -1), right(n + 1, -1);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				int dist = p[i] - p[j];
				if ((d[i] + dist) % k == d[j]) left[i] = j;
			}
			for (int j = n; j > i; j--) {
				int dist = p[j] - p[i];
				if ((d[i] + dist) % k == d[j]) right[i] = j;
			}
		}
		
		
//		for (int i = 1; i <= n; i++) {
//			cout << i << ": " << left[i] << ' ' << right[i] << el;
//		}
//		
//		return;
		
		
		int timeVis = 0;
		for (int start = 1; start <= n; start++) { // to the left cyc
			++timeVis;
			int cur = start;
			int step = 0;
			while (cur != -1) {
				vis[step][cur] = timeVis;
				if (step & 1) {
					cur = right[cur];
					if (cur != -1 && vis[1 - step][cur] == timeVis) {
						cyc[start] = true;
						break;
					}
				} else {
					cur = left[cur];
					if (cur != -1 && vis[1 - step][cur] == timeVis) {
						cyc[start] = true;
						break;
					}
				}
				step = 1 - step;
			}
			
		}
	}
	
//	for (int i = 1; i <= n; i++) cout << cyc[i] << ' ';
//	
//	return;

	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		auto pos = lower_bound(p.begin() + 1, p.end(), x) - p.begin();
		if (pos > n) {
			cout << "YES" << el;
			continue;
		}
		bool chosen = false;
		for (int i = pos; i <= n; i++) {
			int dist = p[i] - x;
			if (dist % k != d[i]) {
				continue;
			}
			if (cyc[i]) {
				cout << "NO" << el;
			} else cout << "YES" << el;
			chosen = true;
			break;
		} 
		if (!chosen) {
			cout << "YES" << el;
		}
	}
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}

