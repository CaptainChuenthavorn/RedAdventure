#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
void draw_ship(int ,int);
void erase_ship(int, int);
void draw_bullet(int , int );
void clear_bullet(int , int );

int main()
{
		char ch = ' ';
		int x = 20, y = 5;
		int bx, by, i;
		int bullet = 0;
		draw_ship(x, y);
		do {
			if (_kbhit()) {
				ch = _getch();
				if (ch == 'a') {
					erase_ship(x, y);
					draw_ship(--x, y);
				}
				if (ch == 'd') { 
					erase_ship(x, y);
					draw_ship(++x, y);
				}
				if (ch == 'w') {
					erase_ship(x, y);
					draw_ship(x, --y);
				}
				if (ch == 's') {
					erase_ship(x, y);
					draw_ship(x, ++y);
				}
				if (bullet != 1 && ch == ' ') {
					bullet = 1;
					bx = x + 3;
					by = y - 1;
				}
				fflush(stdin);

				if (bullet == 1) {
					clear_bullet(bx, by);
					if (by == 2) { bullet = 0; }
					else { draw_bullet(bx, --by); }
				}
				if (x < 0) {		 //if out of monitor x<0
					erase_ship(x+6, y);
					x = 0;
					draw_ship(x, y);
				}
				if (x > 80) {        //if out of monitor x>80
					erase_ship(x , y);
					x = 80;
					draw_ship(x, y);
				}
				if (y < 0) {		//if out of monitor y<0
					erase_ship(x + 5, y+1);
					y = 0;
					draw_ship(x, y);
				}
				if (y > 80) {		//if out of monitor y>80
					erase_ship(x, y);
					y = 80;
					draw_ship(x, y);
				}
			}
			Sleep(100);
		} while (ch != 'x');
		return 0;
}
void gotoxy(int x, int y) {
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y) {
	gotoxy(x, y);
	printf("<-o->");
}
void erase_ship(int x, int y) {
	gotoxy(x, y);
	printf("     ");
}
void draw_bullet(int x, int y) {
	gotoxy(x, y); printf("^");
}
void clear_bullet(int x, int y) {
	gotoxy(x, y);
	printf("");
}