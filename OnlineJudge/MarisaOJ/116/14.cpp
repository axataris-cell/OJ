#include<bits/stdc++.h>
#define N int(1e5)
using namespace std;
int n, m, k, dd_M[N + 5], dd_A[N + 5], Marisa[N + 5], Alice[N + 5], ans = 0;
vector<int> adj[N + 5], p;
void BFS_Alice(int u)
{
    queue<int> Q;
    Q.push(u);
    dd_A[u] = 1;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for(auto v: adj[u])
        if(dd_A[v] == 0)
        {
            Q.push(v);
            dd_A[v] = 1;
            Alice[v] = Alice[u] + 1;
        }
    }
}
void BFS_Marisa(int u)
{
    queue<int> Q;
    Q.push(u);
    dd_M[u] = 1;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for(auto v: adj[u])
        if(dd_M[v] == 0)
        {
            Q.push(v);
            dd_M[v] = 1;
            Marisa[v] = Marisa[u] + 1;
        }
    }
}
int main()
{
    cin >> n >> m >> k;
    int x;
    for(int i = 1; i <= k; i++)
    {
        cin >> x;
        p.push_back(x);
    }
    int u, v;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS_Alice(n);
    BFS_Marisa(1);
    for(auto x: p)
    if(Alice[x] <= Marisa[n]) ans++;
    cout << ans;
    return 0;
}