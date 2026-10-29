#include<bits/stdc++.h>
using namespace std; int main() { int t; cin >> t; while (t--) { int n; cin >> n; int sn = 0, sp = 0; for (int i = 1; i <= n; i++) { int x; cin >> x; sn += (x < 0 ? x : 0), sp += (x >= 0 ? x : 0);
}cout << sp - sn << '\n';
}
}
