#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 2e9
#define LINF 4e18

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
const int MAXA = 1000005;
int min_prime[MAXA];

void sieve() {
    for (int i = 2; i < MAXA; ++i) {
        if (min_prime[i] == 0) {
            for (int j = i; j < MAXA; j += i) {
                if (min_prime[j] == 0) min_prime[j] = i;
            }
        }
    }
}

int get_prime_power_base(int x) {
    if (x <= 1) return 0;
    int p = min_prime[x];
    int temp = x;
    while (temp > 1 && temp % p == 0) temp /= p;
    return (temp == 1) ? p : -1;
}


void testcase() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool initially_sorted = true;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0 && a[i] < a[i - 1]) initially_sorted = false;
    }

    if (initially_sorted) {
        cout << "Bob" << endl;
        return;
    }

    bool seen_non_one = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            if (seen_non_one) {
                cout << "Alice" << endl;
                return;
            }
        } else {
            seen_non_one = true;
        }
    }

    vector<int> prime_bases;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 1) {
            int p = get_prime_power_base(a[i]);
            if (p == -1) {
                cout << "Alice" << endl;
                return;
            }
            prime_bases.push_back(p);
        }
    }

    for (int i = 0; i < (int)prime_bases.size() - 1; ++i) {
        if (prime_bases[i] > prime_bases[i + 1]) {
            cout << "Alice" << endl;
            return;
        }
    }

    cout << "Bob" << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();
	sieve();
	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
