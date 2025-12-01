#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'
 

using namespace std;
 

void file() {
freopen("", "r", stdin);
freopen("", "w", stdout);
}
 

const int MAXN = 1e6 + 5;
int p[MAXN];
int cnt[MAXN];
 

void sieve() {
for (int i = 1; i <= MAXN; i++) p[i] = i;
for (int i = 1; i * i <= MAXN; i++) {
if (p[i] == i) {
for (int j = i * i; j <= MAXN; j += i) {
p[j] = i;
}
}
}
}
 

bool check(int n) {
ll c = 1; unordered_map<int, int> mp;
while (p[n] != 1 && n != 1) {
++mp[p[n]];
n /= p[n];
}
for (auto x : mp) c *= (mp[x.first] + 1);
 

if (p[c] == c && c != 1) return true;
else return false;
}
 

void testcase() {
int a, b; cin >> a >> b;
cout << cnt[b] - cnt[a - 1] << el;
}
 

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
 

//file();
 

sieve();
 

cnt[0] = 0;
for (int i = 1; i <= MAXN; i++) {
cnt[i] = cnt[i - 1];
if (check(i)) ++cnt[i];
}

ll t = 1; cin >> t;
while (t--) testcase();
 

return 0;
}