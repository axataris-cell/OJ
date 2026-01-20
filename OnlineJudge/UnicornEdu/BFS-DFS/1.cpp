#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

const int MAXN = 2e5 + 5;

int n;
string s0, s1;
bool vis[MAXN];
int res = 0;

bool valid(int s, int i) {
	if (s + i < 0 || s + i >= n) return false;

	if (i == -1 || i == 1) {
		if (s0[s + i] == '1') return true;
		else return false;
	} else {
		if (s0[s + i] == '0') return true;
		else return false;
	}
}

// l?a d?o dfs
void dfs(int s) {
	for (int i = -1; i <= 1; i++) {
		if (valid(s, i) && !vis[s + i]) {
			vis[s + i] = true;
			++res;
			break;
		}
	}
}

void testcase() {
	memset(vis, false, sizeof(vis));
	res = 0;
	
	cin >> n;
	cin >> s0 >> s1;
	
	for (int i = 0; i < n; i++) {
		if (s1[i] == '1') {
			dfs(i);
		}
	}
	
	cout << res << el;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
