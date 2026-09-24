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
	string s; cin >> s;
	auto f = s[0];
	if (f == '0') {
		vector<vector<int>> suf(2, vector<int>(n + 2, 0));
		for (int i = n; i >= 1; i--) {
			suf[0][i] = suf[0][i + 1];
			suf[1][i] = suf[1][i + 1];
			suf[s[i - 1] - '0'][i]++;
		}
		int res = INF;
		int cnt1 = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') ++cnt1;
			res = min(res, cnt1 + suf[0][i + 2]);
		}
		cout << res << el;
	} else {
		int cnt = 0;
		for (auto c : s) if (c == '0') ++cnt;
		cout << cnt << el;
	}
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}

