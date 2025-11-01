#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int f[1001][1001];

void testcase() {
	string a, b;
	cin >> a >> b;
	
	// Định nghĩa F[i][j] là xâu con dài nhất có thể đạt được tại vị tri i của xâu a và vị trí j của xâu b
	
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i-1] == b[j-1]) {
				f[i][j] = f[i-1][j-1] + 1;
			} else {
				f[i][j] = max(f[i-1][j], f[i][j-1]);
			}
		}
	}
	
	cout << f[a.size()][b.size()];
}

/*
Giải thích các bước làm trong bài:
Lấy VD nhé:
Xâu a: abcde
Xâu b: ace
Khi chúng ta xét đến c trong a và a trong b
chúng ta sẽ nhận thấy nó sẽ khác nhau vì vậy nên gọi max của  b,a hoặc c,0.
Trong trường hợp này thì nó sẽ lấy b, a.
Mà trước đó khi xét b, a chúng ta đã thấy nó khác nhau nên đã lấy max tương tự, là a, a == 1.
Tức là khi xét đến kí tự thứ i trong xâu a, kí tự thứ j trong xâu b.
chúng ta sẽ thấy là nó đều dựa vào những max của cái trước mà nên.
Nếu bằng nhau, thì tức là chúng ta chỉ cần lấy số max của iterator khi mà cả hai lùi về 1 bước
Nếu khác nhau, thì chúng ta lại đẩy lùi pointer của cái thứ nhất, hoặc cái thứ hai về một và lấy cái lớn hơn.
Đối với những bài dp, chúng ta chỉ cần xét những trường hợp nhỏ thôi là biết nó có đúng hay không.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
