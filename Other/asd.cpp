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
string s;

void backtrack(int pos, int cnt) {
    if (cnt > k) return;
    if (cnt + (n - pos) < k) return;
    
    if (pos == n) {
        if (cnt == k) {
            for (char c : s) cout << c << ' ';
            cout << '\n';
        }
        return;
    }

    s[pos] = '0';
    backtrack(pos + 1, cnt);

    if (cnt < k) {
        s[pos] = '1';
        backtrack(pos + 1, cnt + 1);
    }
}
  
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(0);

    cin >> n >> k;
    s.resize(n);
    backtrack(0, 0);
    
    return 0;
}
