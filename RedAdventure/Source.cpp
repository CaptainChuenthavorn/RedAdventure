#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include<windows.h>
#include<conio.h>
//void clrscr();
void erase_ship(int , int); 
void draw_ship(int ,int);
//void gotoxy(int, int);
int main()
{
		char ch = ' ';
		int x = 75, y = 2;
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
				fflush(stdin);
				if (x < 0) {
					erase_ship(x+6, y);
					x = 0;
					draw_ship(x, y);
				}
				if (x > 80) {
					erase_ship(x , y);
					x = 80;
					draw_ship(x, y);
				}
				if (y < 0) {
					erase_ship(x + 5, y+1);
					y = 0;
					draw_ship(x, y);
				}
				if (y > 80) {
					erase_ship(x, y);
					y = 80;
					draw_ship(x, y);
				}
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
void erase_ship(int x, int y) {
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf("     ");
}
/*
void clrscr()
{
	system("@cls||clear");
}*/