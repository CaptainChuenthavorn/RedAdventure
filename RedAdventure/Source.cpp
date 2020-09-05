#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<windows.h>
#include<conio.h>
void draw_ship(int ,int);
void gotoxy(int, int);
int main()
{
		char ch = ' ';
		int x = 38, y = 20;
		draw_ship(x, y);
		do {
			if (_kbhit()) {
				ch = _getch();
				if (ch == 'a') { draw_ship(--x, y); }
				if (ch == 'd') { draw_ship(++x, y); }
				fflush(stdin);
			}
			Sleep(100);
		} while (ch != 'x');
		return 0;
}
void draw_ship(int x, int y) {
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf("<-o->");
}
void gotoxy(int x, int y) 
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}