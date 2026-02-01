#include <bits/stdc++.h>
#define nam
#define sau using namespace std;
#define bay
#define tam void file() {
#define chin    freopen("", "r", stdin);
#define muoi    freopen("", "w", stdout);
#define one }
#define two
#define three int A[100005] = {};
#define four int S[100005] = {};
#define five int B[100005] = {};
#define six
#define seven void testcase() {
#define eight   int n; cin >> n;
#define nine    for (int i = 1; i <= n; i++) {
#define ten             cin >> A[i];
#define H2O             S[i] = A[i] - A[i - 1];
#define H3O     }
#define h4O     int q; cin >> q;
#define bach    while (q--) {
#define la              int l, r; cin >> l >> r;
#define thang           ++S[l]; --S[r + 1];
#define dau     }
#define buoi
#define con     B[1] = S[1]; cout << B[1] << ' ';
#define cac     for (int i = 2; i <= n; i++) {
#define khanh           B[i] = S[i] + B[i - 1];
#define nho             cout << B[i] << ' ';
#define chinchin        }
#define xinxin
#define sin }
#define cos
#define tan int main() {
#define cotan   ios_base::sync_with_stdio(false);
#define cot     cin.tie(NULL);
#define sinh    cout.tie(NULL);
#define dit
#define me      //file();
#define xam
#define vai     long long t = 1; //cin >> t;
#define ca      while (t--) testcase();
#define lon
#define cc      return 0;
#define ccccc }
using namespace std;