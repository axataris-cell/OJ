#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	if (FILE *f = fopen(FILENAME".INP", "r")) {
		fclose(f);
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
}

void testcase() {
    int n;
    long long k;
    cin >> n >> k;

    map<long long,long long> s,t;

    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        s[x%k]++;
    }

    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        t[x%k]++;
    }

    if(s[0]!=t[0]){
        cout<<"NO\n";
        return;
    }

    for(auto &[r,c]:s){
        if(r==0) continue;

        if(s[r] + s[k-r] != t[r] + t[k-r]){
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
