#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int A[1005][1005] = {};
vector<vector<pair<int,int>>> RLE(1005);

void testcase() {
    int n, m; 
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> A[i][j];

    int maxlen = 0;

    for (int j = 1; j <= m; j++) {
        RLE[j].clear();
        int cur = A[1][j], cnt = 1;
        for (int i = 2; i <= n; i++) {
            if (A[i][j] == cur) ++cnt;
            else {
                RLE[j].push_back({cur, cnt});
                cur = A[i][j];
                cnt = 1;
            }
        }
        RLE[j].push_back({cur, cnt});
        maxlen = max(maxlen, (int)RLE[j].size());
    }

    for (int row = 0; row < maxlen * 2; row++) {
        for (int j = 1; j <= m; j++) {
            int idx = row / 2;
            if (idx < (int)RLE[j].size()) {
                if (row % 2 == 0) cout << RLE[j][idx].first;
                else cout << RLE[j][idx].second;
            } else cout << "-";
            if (j < m) cout << " ";
        }
        cout << el;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
