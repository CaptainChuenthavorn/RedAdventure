#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
void draw_ship(int ,int);
void erase_ship(int, int);
void setcursor(bool);
void setcolor(int, int );
void erasecolor(int, int);
void Frame_ship(int, int);
void draw_bullet(int, int);
void clear_bullet(int, int);
int main()
{
		char ch = ' ';
		int x = 20, y = 20, direction = 0,bullet = 0,Bx=x+2,By=y-1;
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
				if (ch == ' ') {
					bullet = 1;
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
			if (bullet == 1) {
				Bx = x + 2, By = y - 1;
				
				while (By != 0 ) {
					erasecolor(0, 0);
					clear_bullet(Bx, By);
					setcolor(4, 2);
					draw_bullet(Bx, --By);
					
					if (By == 0) {
						erasecolor(0, 0);
						clear_bullet(Bx, By);
						setcolor(4, 2);
						draw_bullet(Bx, By);
						Sleep(50);
						erasecolor(0, 0);
						clear_bullet(Bx, By);
						setcolor(4, 2);
					}
					Sleep(50);
				}
				bullet--;
				
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

void draw_bullet(int Bx, int By) {
	gotoxy(Bx, By); 
	//erasecolor(0, 0);
	//setcolor(4, 2);
	printf("^");
}
void clear_bullet(int Bx, int By) {
	gotoxy(Bx, By);
	printf("   ");
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
