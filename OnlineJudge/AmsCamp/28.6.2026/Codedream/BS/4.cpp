#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n, h;
    cin >> n >> h;
    vector <int> mang(n);
    
    for (int i = 0; i < n; i++){
        cin >> mang[i];
    }

    int l = 1;
    int r = *max_element(mang.begin(), mang.end());
    int ans = 0;
    
    while (l <= r){
        int mid = l + (r - l)/2;
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += (mang[i] + mid - 1)/mid;
//			if (sum > h) break;
        }
        if (sum <= h){
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans;
}
