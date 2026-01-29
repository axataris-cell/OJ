#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        long long p = x;
        long long q = y & (~x);
        long long p1 = x & (~y);
        long long q1 = y;
        
        if (abs(x - p) + abs(y - q) < abs(x - p1) + abs(y - q1)) cout << p << " " << q << "\n";
        else cout << p1 << ' ' << q1 << endl;
    }
    return 0;
}
