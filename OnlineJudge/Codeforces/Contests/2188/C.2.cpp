#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n), b;
        for(int i = 0; i < n; i++) cin >> a[i];

        b = a;
        sort(b.begin(), b.end());

        if(a == b){
            cout << -1 << '\n';
            continue;
        }

        // lấy các giá trị khác nhau
        vector<long long> vals = b;
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        // map giá trị -> component id
        int m = vals.size();
        vector<long long> gaps;
        for(int i = 0; i + 1 < m; i++){
            gaps.push_back(vals[i+1] - vals[i]);
        }

        long long ans = 0;

        // thử k = gap + 1 (chỉ các điểm làm tách component)
        for(long long kCandidate : gaps){
            long long k = kCandidate + 1;

            // build component
            unordered_map<long long,int> comp;
            int cid = 0;
            comp[vals[0]] = 0;

            for(int i = 1; i < m; i++){
                if(vals[i] - vals[i-1] < k) cid++;
                comp[vals[i]] = cid;
            }

            // đếm tần suất trong mỗi component
            unordered_map<long long, map<long long,int>> ca, cb;
            for(int i = 0; i < n; i++){
                ca[comp[a[i]]][a[i]]++;
                cb[comp[b[i]]][b[i]]++;
            }

            if(ca == cb){
                ans = max(ans, k);
            }
        }

        cout << ans << '\n';
    }
}
