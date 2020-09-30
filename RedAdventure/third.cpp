#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
void draw_ship(int ,int);
void erase_ship(int, int);
void setcursor(bool);
void setcolor(int fg, int bg);
void erasecolor(int fg, int bg);
void Frame_ship(int x, int y);
int main()
{
		char ch = ' ';
		int x = 20, y = 5, direction = 0;
		setcolor(4, 2);
		setcursor(0);
		draw_ship(x, y);
		do {
			if (_kbhit()) {
				ch = _getch();
				if (ch == 'a') {
					direction = 1;
				}
				if (ch == 'd') {
					direction = 2;
				}
				if (ch == 's') {
					direction = 0;
				}
				setcolor(4, 2);
				fflush(stdin);
				
			}
			if (direction == 1) {
				erasecolor(0, 0);
				erase_ship(x, y);
				setcolor(4, 2);
				draw_ship(--x, y);
			}
			if (direction == 2) {
				erasecolor(0, 0);
				erase_ship(x, y);
				setcolor(4, 2);
				draw_ship(++x, y);
			}
			if (direction == 0) {
				
				erase_ship(x, y);
				
				draw_ship(x, y);
			}
			if (x < 0) {		 //if out of monitor x<0
				erasecolor(0, 0);
				erase_ship(x + 6, y);
				setcolor(4, 2);
				x = 0;
				draw_ship(x, y);
			}
			if (x > 80) {        //if out of monitor x>80
				erasecolor(0, 0);
				erase_ship(x, y);
				x = 80;
				setcolor(4, 2);
				draw_ship(x, y);
			}
			if (y < 0) {		//if out of monitor y<0
				erase_ship(x + 5, y + 1);
				y = 0;
				draw_ship(x, y);
			}
			if (y > 80) {		//if out of monitor y>80
				erase_ship(x, y);
				y = 80;
				draw_ship(x, y);
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
	printf(" ");
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void erasecolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
	printf("     ");
}
void Frame_ship(int x,int y)
{
	if (x < 0) {		 //if out of monitor x<0
		erase_ship(x + 6, y);
		x = 0;
		draw_ship(x, y);
	}
	if (x > 80) {        //if out of monitor x>80
		erase_ship(x, y);
		x = 80;
		draw_ship(x, y);
	}
	if (y < 0) {		//if out of monitor y<0
		erase_ship(x + 5, y + 1);
		y = 0;
		draw_ship(x, y);
	}
	if (y > 80) {		//if out of monitor y>80
		erase_ship(x, y);
		y = 80;
		draw_ship(x, y);
	}
}
