#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Dish {
    ll a, b, c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<Dish> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i].a >> v[i].b >> v[i].c;

    // Sort by b decreasing
    sort(v.begin(), v.end(), [](const Dish &x, const Dish &y) {
        return x.b > y.b;
    });

    static ll dp[505][505];
    for (int i = 0; i <= M; i++)
        for (int j = 0; j <= N; j++)
            dp[i][j] = -4e18;

    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int money = M; money >= v[i].c; money--) {
            for (int k = N; k >= 1; k--) {
                if (dp[money - v[i].c][k - 1] == -4e18) continue;

                ll gain = v[i].a - (ll)(k - 1) * v[i].b;
                dp[money][k] = max(
                    dp[money][k],
                    dp[money - v[i].c][k - 1] + gain
                );
            }
        }
    }

    ll ans = 0;
    for (int money = 0; money <= M; money++)
        for (int k = 0; k <= N; k++)
            ans = max(ans, dp[money][k]);

    cout << ans;
}