#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        bool found = false;

        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == '1' && s[i + 1] == '0') {
                // Found an inversion: Alice wins
                cout << "Alice\n";
                cout << 2 << "\n";
                cout << i + 1 << " " << i + 2 << "\n";
                found = true;
                break;
            }
        }

        if (!found) {
            // No inversion exists
            cout << "Bob\n";
        }
    }

    return 0;
}
