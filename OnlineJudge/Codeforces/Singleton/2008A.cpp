#include<bits/stdc++.h>
using namespace std;int main(){int t;cin>>t;while(t--){int a,b;cin>>a>>b;if(!a){cout<<(b&1?"NO":"YES")<<'\n';continue;}cout<<((a+2*b)&1?"NO":"YES")<<'\n';}}