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
	int x = 0, y = 0;
	map<char, pii> dir;
	dir['L'] = {-1, 0};
	dir['R'] = {1, 0};
	dir['U'] = {0, 1};
	dir['D'] = {0, -1};
	int n; cin >> n;
	string s; cin >> s;
	for (auto c : s) {
		auto [dx, dy] = dir[c];
		x += dx;
		y += dy;
		if (x == 1 && y == 1) {
			cout << "YES" << el;
			return;
		}
	}
	cout << "NO" << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}


