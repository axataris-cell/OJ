#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

typedef struct {
	int x, y;
	int maul
} DIEM;

int main() {
	int mh = 0, mode = 0;
	initgraph(&mh, &mode, "");
	int loi = graphresult();
	if (loi) {
		cout << "Loi do hoa: " << grapherrormsg(loi);
		getch(); return 0;
	}
	const DIEM gmh = {getmaxx() / 2, getmaxy() / 2, WHITE};
	putpixel(gmh.x, gmh.y, gmh.mau); getch();
	closegraph();
}