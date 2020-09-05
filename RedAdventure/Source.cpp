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
		int x = 5, y = 20;
		draw_ship(x, y);
		do {
			if (_kbhit()) {
				ch = _getch();
				if (ch == 'a') {
					draw_ship(--x, y);
					erase_ship(x + 5, y);
				}
				if (ch == 'd') { 
					draw_ship(++x, y);
					erase_ship(x - 5, y);
				}
				if (ch == 'w') {
				
					draw_ship(x, --y);
					erase_ship(x, y + 1);
				}
				if (ch == 's') {
					
					draw_ship(x, ++y);
					erase_ship(x, y - 1);
				}
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