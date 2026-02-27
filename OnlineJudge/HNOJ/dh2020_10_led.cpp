#include <bits/stdc++.h>
#include <chrono>

#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

#define FILENAME "led"

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
#define int long long 

vector<int> q1(10, 0);
vector<int> q2(10, 0);
void testcase() {
	q1[0] = 6;
	q1[1] = 2;
	q1[2] = 5;
	q1[3] = 5;
	q1[4] = 4;
	q1[5] = 5;
	q1[6] = 6;
	q1[7] = 3;
	q1[8] = 7;
	q1[9] = 6;
	
	q2[0] = 2;
	q2[1] = 6;
	q2[2] = 2;
	q2[3] = 3;
	q2[4] = 3;
	q2[5] = 4;
	q2[6] = 2;
	q2[7] = 3;
	q2[8] = 1;
	q2[9] = 1;
	
	int t; cin >> t;
	string s; cin >> s;
	int n = s.length();
	if (t == 1) {
		int res = 0;
		for (int i = 0; i < n; i++) {
			res += q1[s[i] - '0'];
		}
		cout << res;
	} else {
		int res = 1;
		for (int i = 0; i < n; i++) {
			res *= q2[s[i] - '0'];
		}
		cout << res - 1;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
