#include <iostream>
#include <iomanip>
#define el '\n'
#include <conio.h>

using namespace std;

int main() {
	struct {
		char ht[25];
		float t, l, h, td;
	} ts[50], tg;
	int n, i, j;
	cout << "So thi sinh: ";
	cin >> n;
	
	for (i = 1; i <= n; i++) {
		cout << el << "Thi sinh " << i << el;
		cout << "Ho ten: ";
		cin.ignore(1);
		cin.get(ts[i].ht, 25);
		cout << "Cac diem toan, ly, hoa: ";
		cin >> ts[i].t >> ts[i].l >> ts[i].h;
		ts[i].td = ts[i].t + ts[i].l + ts[i].h;
	}
	// Óc chó sort
	for (i = 1; i <= n - 1; i++) {
		for (j = i + 1; j <= n; j++) {
			if (ts[i].td < ts[j].td) {
				tg = ts[i];
				ts[i] = ts[j];
				ts[j] = tg;
			}
		}
	}
	cout << el << "Danh sach thi sinh sau khi sap xep ";
//	cout << setiosflags(ios::showpoint) << setprecision(1);
	for (i = 1; i <= n; i++) {
		cout << el << "Ho ten: " << setw(25) << ts[i].ht;
		cout << el << "Tong diem: " << setw(5) << ts[i].td;
	}
	getch();
}