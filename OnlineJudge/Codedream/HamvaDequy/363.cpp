#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}
int d, m, y, k;

bool leap(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int ngay(int m, int y) {
    if (m == 2) return leap(y) ? 29 : 28;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

void testcase() {
	cin >> d >> m >> y >> k;
	
	int d1 = d, m1 = m, y1 = y;
    int k1 = k - 1;
    if (k1 < 2) k1 = 8;

    d1--;
    if (d1 == 0) {
        m1--;
        if (m1 == 0) {
            m1 = 12;
            y1--;
        }
        d1 = ngay(m1, y1);
    }
    
    int d2 = d, m2 = m, y2 = y;
    int k2 = k + 1;
    if (k2 > 8) k2 = 2;

    d2++;
    if (d2 > ngay(m2, y2)) {
        d2 = 1;
        m2++;
        if (m2 == 13) {
            m2 = 1;
            y2++;
        }
    }
	
    cout << d1 << " " << m1 << " " << y1 << " " << k1 << el;
    cout << d2 << " " << m2 << " " << y2 << " " << k2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
