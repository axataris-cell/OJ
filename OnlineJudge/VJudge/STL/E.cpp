#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> neg, pos, zero;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) neg.push_back(a[i]);
        else if (a[i] > 0) pos.push_back(a[i]);
        else zero.push_back(a[i]);
    }

    vector<int> x, y, z;

    x.push_back(neg.back());
    neg.pop_back();

    if (pos.empty()) {
        y.push_back(neg.back()); neg.pop_back();
        y.push_back(neg.back()); neg.pop_back();
    } else {
        for (int p : pos) y.push_back(p);
    }

    for (int nd : neg) z.push_back(nd);
    for (int zz : zero) z.push_back(zz);

    cout << x.size();
    for (int v : x) cout << " " << v;
    cout << "\n";

    cout << y.size();
    for (int v : y) cout << " " << v;
    cout << "\n";

    cout << z.size();
    for (int v : z) cout << " " << v;
    cout << "\n";

    return 0;
}
