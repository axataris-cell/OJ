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
int simulate(long long white, long long dark, bool startWhite) {
    long long size = 1;
    bool isWhite = startWhite;
    int layers = 0;

    while (true) {
        if (isWhite) {
            if (white < size) break;
            white -= size;
        } else {
            if (dark < size) break;
            dark -= size;
        }
        layers++;
        size <<= 1;        // next layer doubles
        isWhite = !isWhite;
    }
    return layers;
}
void testcase() {
    int t; cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;

        int res1 = simulate(a, b, true);   // start with white
        int res2 = simulate(a, b, false);  // start with dark

        cout << max(res1, res2) << el;
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
