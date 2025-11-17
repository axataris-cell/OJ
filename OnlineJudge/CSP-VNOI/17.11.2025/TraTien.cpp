#include <bits/stdc++.h>
using namespace std;

int a[101], f[10001];
int n, s, t, d, ma;

int main() {
    cin >> s;
    ma = 100*100;
    for (int i = 1; i <= 100; i++) {
    	t += i*i;
    }

    //
    // for (int i = 1; i <= n; i++) {
    //     cin >> a[i];
    //     t += a[i];
    //     ma = max(ma, a[i]);
    // }

    for (int i = 1; i <= 10000; i++)
        f[i] = int(1e9);
    f[0] = 0;

    for (int i = 1; i <= 10000; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= a[j])
                f[i] = min(f[i], f[i - a[j]] + 1);
        }
    }

    if (s <= t) {
        cout << f[s];
    } else {
        d = (s - t) / ma + f[(s - t) % ma + t];
        cout << d;
    }

    return 0;
}
