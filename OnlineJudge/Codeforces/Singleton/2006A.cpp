#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME ""
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=4e18,MAXN=2e5+5,LOG=20,MOD=1e9+7,BASE=113,BLOCK=400;
vector<int> g[MAXN];
int par[MAXN];
int pen[MAXN][2];
int val[MAXN];

void dfs(int u, int p) {
    for (int v : g[u]) if (v != p) {
        par[v] = u;
        if (val[v] != -1) ++pen[u][1 - val[v]];
        dfs(v, u);
    }
    if (p != -1 && val[p] != -1) {
        --pen[u][1 - val[p]];
    }
}

int res = 0;
int cur = 0;
stack<int> st;

void getans(int u, int p) {
    int append = 0;
    if (!st.empty()) {
        if (val[u] == 0 && st.top() == 1) {
            append = 1;
            ++cur;
        }
        if (val[u] == 1 && st.top() == 0) {
            append = -1;
            --cur;
        }
    }
    st.push(val[u]);

    for (int v : g[u]) if (v != p) {
        dfs(v, u);
    }
    
    if (g[u].size() == 1) {
        res += cur;
    }

    st.pop();
    cur -= append;
}

void testcase() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        pen[i][0] = pen[i][1] = 0;
        val[i] = 0;
        par[i] = 1;
        res = 0;
    }
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    string va; cin >> va;
    
    vector<int> iris, dora;
    for (int i = 1; i <= n; i++) {
        if (va[i - 1] == '?') {
            iris.push_back(i);
            dora.push_back(i);
        }
        val[i] = (va[i - 1] == '1' ? 1 : (va[i - 1] == '0' ? 0 : -1));
    }

    dfs(1, -1);

    sort(iris.begin(), iris.end(), [&](const int &x, const int &y) {
        return pen[x][0] > pen[y][0];
    });
    sort(dora.begin(), dora.end(), [&](const int &x, const int &y) {
        return pen[x][1] > pen[y][1];
    });

    vector<bool> vis(n + 1, false);
    int m = iris.size();

    for (int i[2] = {0, 0}; i[0] < m && i[1] < m; i[0]++, i[1]++) {
        if (!vis[iris[i[0]]]) {
            vis[iris[i[0]]] = true;
            val[iris[i[0]]] = 1;
        }
        if (!vis[dora[i[1]]]) {
            vis[dora[i[1]]] = true;
            val[dora[i[1]]] = 0;
        }
    }

    getans(1, 1);

    cout << res << el;

}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}