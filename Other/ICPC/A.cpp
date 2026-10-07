#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m;
int par[200005];
int SIZE[200005];

void build(int pos)
{
	par[pos]=pos;
    SIZE[pos] = 1;	
}
int get_anscestor(int pos)
{
	if(par[pos]==pos)
	{
		return par[pos];
	}
	return par[pos]=get_anscestor(par[pos]);
}
void combine(int l,int r)
{
	l = get_anscestor(l);
	r = get_anscestor(r);
	if(l==r)
	{
		return;
	}
	par[r]=l;
	SIZE[l]+=SIZE[r];
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		build(i);
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		combine(x,y);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,SIZE[i]);
	}
	cout<<ans;
}
