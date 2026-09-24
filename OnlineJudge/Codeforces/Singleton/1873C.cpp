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
vector<vector<int>> points(11, vector<int>(11, 0));
void testcase() {
	int res = 0;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			char c;
			cin >> c;
			if (c == 'X') res += points[i][j];
		}
	}
	
	cout << res << el;
}
int32_t main() {
    fastio file();
    
	for (int i = 1; i <= 10; i++) {
		points[i][1] = 1;
		points[i][10] = 1;
		points[1][i] = 1;
		points[10][i] = 1;
	}
	
	for (int i = 2; i <= 9; i++) {
		points[i][2] = 2;
		points[i][9] = 2;
		points[2][i] = 2;
		points[9][i] = 2;
	}
	
	for (int i = 3; i <= 8; i++) {
		points[i][3] = 3;
		points[i][8] = 3;
		points[3][i] = 3;
		points[8][i] = 3;
	}
	
	for (int i = 4; i <= 7; i++) {
		points[i][4] = 4;
		points[i][7] = 4;
		points[4][i] = 4;
		points[7][i] = 4;
	}
	
	for (int i = 5; i <= 6; i++) {
		points[i][5] = 5;
		points[i][6] = 5;
		points[6][i] = 5;
		points[5][i] = 5;
	}
	
//	for (int i = 1; i <= 10; i++) {
//		for (int j = 1; j <= 10; j++) {
//			cout << points[i][j] << ' ';
//		}
//		cout << el;
//	}
	
    
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}

