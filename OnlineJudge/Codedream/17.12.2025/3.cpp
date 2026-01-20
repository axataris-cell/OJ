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

void testcase() {
    string s; 
    cin >> s;
    int n = s.size();
    s += s;

    int res = 0;

    for (char c = 'a'; c <= 'z'; c++) {
        int l = 0;
        for (int r = 0; r < (int)s.size(); r++) {
            if (s[r] != c && s[r] != '0') {
                l = r + 1;
            }
            if (r - l + 1 > n) {
                l++;
            }
            res = max(res, r - l + 1);
        }
    }

    cout << res;
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
