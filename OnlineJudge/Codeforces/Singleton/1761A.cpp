#include<bits/stdc++.h>
using namespace std;void test(){int n,a,b;cin>>n>>a>>b;cout<<(a+b<n-1?"YES":(a==b&&b==n?"YES":"NO"))<<'\n';}int main(){int t;cin>>t;while(t--)test();}