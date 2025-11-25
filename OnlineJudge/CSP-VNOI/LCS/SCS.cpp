#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

// Bai toan: Tim xau c sao cho xau a va xau b deu la cac xau con cua c (xau c chua ca a va b)

int f[2006][2006] = {};

void testcase() {
    string a, b; cin >> a >> b;

    int n = a.length();
    int m = b.length();

    for (int i = 0; i <= n; i++) f[i][0] = i;
    for (int j = 0; j <= m; j++) f[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
        }
    }

    string res = "";
    int i = n, j = m;

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            res.push_back(a[i - 1]);
            i--, j--;
        } else if (f[i - 1][j] < f[i][j - 1]) {
            res.push_back(a[i - 1]);
            i--;
        } else {
            res.push_back(b[j - 1]);
            j--;
        }
    }

    while (i > 0) res.push_back(a[i - 1]), i--;
    while (j > 0) res.push_back(b[j - 1]), j--;

    reverse(res.begin(), res.end());
    cout << res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
