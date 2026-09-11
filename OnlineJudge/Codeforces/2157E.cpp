#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "2157E"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=6e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n*3+5);
    for(int x,i=0;i<n;++i){
        cin>>x;
        a[x]++;
    }
    int current_count = 0, current_source = -1; 
    int ans = 0;
    for(int i=0;i<a.size();++i){
        a[i] += current_count;
        if(current_source !=-1 && current_count != 0){
            ans = max(ans, i-current_source);
        }
        if(a[i]>k){
            if(current_source == -1){
                current_source = i;
            }
            current_count = a[i]-1;
        }else{
            current_source = -1;
            current_count = 0;
        }
    }
    cout<<ans<<el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}