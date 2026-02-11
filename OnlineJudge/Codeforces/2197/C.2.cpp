#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
	    long long p, q;
	    cin >> p >> q;
	
	    if (q >= (2*p)/3 + 1 && q <= (2*p + 2)/3 + 1) {
	        cout << "Bob\n";
	    } else {
	        cout << "Alice\n";
	    }
    }
    return 0;
}
