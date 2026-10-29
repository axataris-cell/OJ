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
	vector<vector<char>> g(9, vector<char>(9));
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			cin >> g[i][j];
		}
	}
	auto get = [&](int i, int j) -> char {
		return ((i <= 8 && j <= 8 && i >= 1 && j >= 1) ? g[i][j] : '.');
	};
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if (get(i - 1, j - 1) == '#' && get(i + 1, j + 1) == '#' && get(i - 1, j + 1) == '#' && get(i + 1, j - 1) == '#') {
				cout << i << ' ' << j << el;
				return;
			}
		}
	}
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}



