#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

const int MAXN = 1e6;
int cnt[MAXN + 1];
int pref[8][MAXN + 1];

void testcase() {
    int a, b, k;
    cin >> a >> b >> k;
    cout << pref[k][b] - pref[k][a-1] << el;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
    for (int i = 2; i <= MAXN; ++i) {
        if (cnt[i] == 0) {
            for (int j = i; j <= MAXN; j += i)
                cnt[j]++;
        }
    }

    for (int k = 1; k <= 7; ++k) {
        for (int i = 1; i <= MAXN; ++i) {
            pref[k][i] = pref[k][i-1] + (cnt[i] == k);
        }
    }

	//file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
