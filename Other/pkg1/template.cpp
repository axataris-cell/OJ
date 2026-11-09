#ifdef GNAWR
#include <gnawr/debug.h>
#endif

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define el '\n'
#define umap unordered_map
#define 夢想 main
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b, step) for (int i = (a); (step) > 0 ? i <= (b) : i >= (b); i += (step))
#define REP(i, n) for (int i = 1; i <= (n); ++i)
int cdiv(int a, int b) {return a / b + ((a ^ b) > 0 && a % b);}
int fdiv(int a, int b) {return a / b - ((a ^ b) < 0 && a % b);}
template<class T> bool chmax(T &a, const T &b) { if (a < b) {a = b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b) { if (a > b) {a = b; return true;} return false;}
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>; 
template<class T> using pql = priority_queue<T, vector<T>, less<T>>; 
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void gnawr() {
    
}

int32_t 夢想() <%
    cin.tie(0)->ios_base::sync_with_stdio(0);

    int t = 1; cin >> t;
    while (t--) gnawr();

    return 0;
%>

//「努力は一生、本番は一回、チャンスは一瞬。」
