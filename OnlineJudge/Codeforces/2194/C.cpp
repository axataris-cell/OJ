#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> allowed(n, 0);

        for (int i = 0; i < k; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                allowed[j] |= (1 << (s[j] - 'a'));
            }
        }

        // find all divisors of n
        vector<int> divs;
        for (int d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                divs.push_back(d);
                if (d * d != n) divs.push_back(n / d);
            }
        }
        sort(divs.begin(), divs.end());

        int best_d = n;
        vector<int> best_choice;

        for (int d : divs) {
            bool ok = true;
            vector<int> choice(d, 0);

            for (int r = 0; r < d; r++) {
                int mask = (1 << 26) - 1;
                for (int pos = r; pos < n; pos += d) {
                    mask &= allowed[pos];
                }
                if (mask == 0) {
                    ok = false;
                    break;
                }
                choice[r] = mask;
            }

            if (ok) {
                best_d = d;
                best_choice = choice;
                break;
            }
        }

        // construct answer string
        string ans(n, 'a');
        for (int r = 0; r < best_d; r++) {
            int mask = best_choice[r];
            int bit = __builtin_ctz(mask); // lowest set bit
            char c = char('a' + bit);

            for (int pos = r; pos < n; pos += best_d) {
                ans[pos] = c;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
