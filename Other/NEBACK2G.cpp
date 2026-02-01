#include <bits/stdc++.h>
#include <chrono>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

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
int n,k;
void backtrack (string s, int pos){
	if (pos == n){
		for (int i = 0; i < n; i++){
			cout << s[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int cnt1 = 0;
	backtrack (s + '0', pos + 1);
	for (int i = pos; i + 1 < n; i++){
		if ((s[i] == '1' && s[i + 1] == '0') || (s[i] = '0' && s[i + 1] == '1')){
			cnt1++;
		}
	}
	if (cnt1 + 1 <= k){
		backtrack (s + '1', pos + 1);
	}
}
void testcase() {
	cin >> n >> k;
	backtrack ("", 0);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
