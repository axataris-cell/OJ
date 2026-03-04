#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	if (FILE *f = fopen(FILENAME".INP", "r")) {
		fclose(f);
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
}

string a;
string ans = "0";
string res = "";

bool valid(string s) {
	for (int i = 1; i < s.length(); i++) {
		if (s[i] <= s[i - 1]) return false;
	}
	return true;
}

void dfs(int c, int idx) {
	res.push_back(c + '0');
	if (!valid(res) || res.size() > a.size() || stoi(res) > stoi(a)) {
		res.pop_back();
		return;	
	}
	if (idx == a.length() - 1) {
		if (res.size() && stoi(ans) < stoi(res) && valid(res)) ans = res;
		res.pop_back();
		return;
	}
	for (int i = c + 1; i <= 9; i++) {
		dfs(i, idx + 1);
	}
	res.pop_back();
}

void testcase() {
	cin >> a;
	ans = "0";
	res = "";
	
	if (a.size() == 1 || valid(a)) {
		cout << a << el;
		return;
	}
	
	dfs(a[0] - '0', 0);
	
	int cur = 9;
	string in = "";
	int inp = a.size() - 1;
	while (inp > 0) {
		in.push_back(cur + '0');
		--inp; --cur;
	}
	in.push_back(a[0] - 1);
	reverse(in.begin(), in.end());
	
	cout << max(stoi(in), stoi(ans)) << el;
}
	
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
