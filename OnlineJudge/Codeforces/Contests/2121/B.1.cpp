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

void testcase() {
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = ' ' + s;
	int pref[n + 1][27] = {0};
	int suff[n + 1][27] = {0};
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= 25; j++){
			pref[i][j] = pref[i - 1][j];
		}
		pref[i][s[i] - 'a']++;
	}
	suff[n][s[n] - 'a']++; 
	for (int i = n - 1; i >= 1; i--){
		for (int j = 0; j <= 25; j++){
			suff[i][j] = suff[i + 1][j];
		}
		suff[i][s[i] - 'a']++;
	}
	
	bool check = false;
	for (int i = 2; i + 1 <= n; i++){
		if (pref[i - 1][s[i] - 'a'] > 0 || suff[i + 1][s[i] - 'a'] > 0){
			check = true;
		}
	}
	if (check){
		cout << "YES" << el;
	}else {
		cout << "NO" << el;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t; cin >> t;
	while (t--) testcase();

	return 0;
}