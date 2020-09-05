#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include<windows.h>
#include<conio.h>
void clrscr();
void erase_ship(int , int); 
void draw_ship(int ,int);
void gotoxy(int, int);
int main()
{
		char ch = ' ';
		int x = 5, y = 20;
		draw_ship(x, y);
		do {
			if (_kbhit()) {
				ch = _getch();
				if (ch == 'a') {
					system("cls");
					draw_ship(--x, y);
				}
				if (ch == 'd') { 
					system("cls");
					draw_ship(++x, y);
				}
				if (ch == 'w') {
					system("cls");
					
					draw_ship(x, --y);
				}
				if (ch == 's') {
					system("cls");
					draw_ship(x, ++y);
				}if (x = 0)
				{
					system("cls");
					x = 0;
					draw_ship(x, y);
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
void gotoxy(int x, int y) 
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void erase_ship(int x, int y) {
	printf("    ");
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
/*
void clrscr()
{
	system("@cls||clear");
}*/