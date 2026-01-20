#include <bits/stdc++.h>
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

const int MAXN = 1e7 + 7;
vector<int> num;
bool p[MAXN];

void sieve() {
	for (int i = 2; i < MAXN; i++) p[i] = true;
	for (int i = 2; i * i < MAXN; i++) {
		if (p[i]) {
			for (int j = i * i; j < MAXN; j += i) p[j] = false;
		}
	}
	for (int i = 2; i < MAXN; i++) {
		if (p[i]) {
			int k = i;
			while (k < MAXN) {
				num.push_back(i);
				k *=i;
			} 
		}
	}
	sort(num.begin(), num.end());
}

void testcase() {
	
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	file();
	
	sieve();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
