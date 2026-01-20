#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

#define FILENAME "TRAFFIC"

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
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    stack<int> A, B;

    for (int i = n; i >= 1; i--) A.push(i);

    ll buoc = 0;

    for (int x : a) {
        if (!A.empty() && A.top() == x) {
            A.pop();
            buoc++;
        } else if (!B.empty() && B.top() == x) {
            B.pop();
            buoc++;
        } else {
            bool found = false;
            while (!A.empty()) {
                if (A.top() == x) {
                    A.pop();
                    buoc++;
                    found = true;
                    break;
                }
                B.push(A.top());
                A.pop();
                buoc++;
            }
            if (!found) {
                cout << "NO";
                return;
            }
        }
    }
	cout << "YES" << el;
    cout << buoc;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
