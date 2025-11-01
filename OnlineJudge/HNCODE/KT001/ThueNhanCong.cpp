#include <bits/stdc++.h>
#define ll long long
#define el '\n'
using namespace std;

const ll INF = 1e18;
const int MAXN = 400005;

int n;
ll H, S, D;
ll a[MAXN];
ll F[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	freopen("PROJECT.INP", "r", stdin);
	freopen("PROJECT.OUT", "w", stdout);

    cin >> n;
    cin >> H >> S >> D;
    for (int i = 1; i <= n; i++) cin >> a[i];

    F[0] = 0;
    vector<int> inc, dec;

    for (int i = 1; i <= n; i++) {
        F[i] = INF;

        for (int j = i - 1; j >= 0; j--) {
            ll cost = F[j] + a[j] * S * (i - j - 1);
            if (a[j] < a[i]) cost += (a[i] - a[j]) * H;
            else cost += (a[j] - a[i]) * D;
            F[i] = min(F[i], cost);
        }
    }

    cout << F[n] + a[n] * D << el;
    return 0;
}
