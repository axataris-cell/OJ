#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(239);

int main() {
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, h;
    cin >> n >> m >> h;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto arr = a;
    vector <int> v(n);
    int tt = 0;
    for (int i = 0; i < m; i++) {
      int b, c;
      cin >> b >> c;
      b--;
      if (v[b] != tt) {
        a[b] = arr[b];
        v[b] = tt;
      }
      a[b] += c;
      if (a[b] > h) {
        tt++;
      }
    }
    for (int i = 0; i < n; i++) cout << (v[i] == tt ? a[i] : arr[i]) << ' ';
    cout << '\n';
  }
}
