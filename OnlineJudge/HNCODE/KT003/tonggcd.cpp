#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'


using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;


void file() {
freopen("", "r", stdin);
freopen("", "w", stdout);
}


const int MOD = 1e9 + 7;


void testcase() {
int n; cin >> n;
vector<int> A(n);
for (int i = 0; i < n; i++) cin >> A[i];


ll res = 0;
vector<pll> cur, nex;


for (int i = 0; i < n; i++) {
nex.clear();


nex.push_back({A[i], 1});


for (pll p : cur) {


ll g = gcd(p.first, A[i]);


if (nex.back().first == g) {
nex.back().second = (nex.back().second + p.second) % MOD;
} else {
nex.push_back({g, p.second});
}


}


cur = nex;


for (pll p : cur) {
res = (res + (p.first % MOD) * (p.second % MOD)) % MOD;
}
}


cout << res;
}


int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);


//file();


ll t = 1; //cin >> t;
while (t--) testcase();


return 0;
}
