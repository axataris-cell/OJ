#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define FILENAME "PDX"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	if (FILE *f = fopen(FILENAME".INP", "r")) {
		fclose(f);
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}

    ll N;
    int M;
    cin >> N >> M;

    map<ll, ll> diff;

    auto add_segment = [&](ll l, ll r) {
        diff[l] += 1;
        if (r + 1 <= N) diff[r + 1] -= 1;
    };

    for (int i = 0; i < M; i++) {
        ll L, R;
        cin >> L >> R;
        if (L <= R) {
            add_segment(L, R);
        } else {
            // wrap around
            add_segment(L, N);
            add_segment(1, R);
        }
    }

    ll cur = 0;
    ll last_pos = 1;
    ll max_coin = 0;
    ll count_max = 0;`

    for (auto &[pos, delta] : diff) {
        if (last_pos <= pos - 1) {
            ll len = pos - last_pos;
            if (cur > max_coin) {
                max_coin = cur;
                count_max = len;
            } else if (cur == max_coin) {
                count_max += len;
            }
        }
        cur += delta;
        last_pos = pos;
    }

    // do?n cu?i
    if (last_pos <= N) {
        ll len = N - last_pos + 1;
        if (cur > max_coin) {
            max_coin = cur;
            count_max = len;
        } else if (cur == max_coin) {
            count_max += len;
        }
    }

    cout << max_coin << " " << count_max << "\n";
    return 0;
}
