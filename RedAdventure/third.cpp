/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
void gotoxy(int , int );
void draw_ship(int ,int);
void erase_ship(int, int);
void setcursor(bool);
void setcolor(int, int );
void erasecolor(int, int);
void draw_bullet(int, int);
void clear_bullet(int, int);
void erasecolorBullet(int, int);
void drawStar(int, int);
char cursor(int, int);
void eraseStar(int, int);
int main()
{
	char ch = ' ';
	int x = 20, y = 20, direction = 0, bullet = 0, Bx = x + 2, By = y - 1,ammo=10000;
	int  randX = 0, randY = 0,score=0;
	//setcolor(6, 0);
	printf("Score : %d", score);
	srand(time(NULL));
	for (int round = 0; round < 20; round++)
	{
		randY = rand() % 4 + 2;
		randX = rand() % 60 + 10;
		drawStar(randX, randY);
		randX = 0;
		randY = 0;
	}
	draw_ship(x, y);
	setcolor(4, 2);
	setcursor(0);
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') { direction = 1; }
			if (ch == 'd') { direction = 2; }
			if (ch == 's') { direction = 0; }
			if (ch == ' ') {
				bullet = 1; Bx = x + 2, By = y - 1;
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
		if (bullet == 1 && ammo > 0) { // bullet = 0 mean OFF ,bulet = 1 mean ON
			Bx = x + 2, By = y - 1;
			while (By != 1) {
				erasecolorBullet(0, 0);
				clear_bullet(Bx, By);
				setcolor(4, 2);
				draw_bullet(Bx, --By);
				if (By == 1) {				// if bullet at top
					bullet = 0;
					erasecolorBullet(0, 0);
					clear_bullet(Bx, By);
					/*setcolor(4, 2);
					draw_bullet(Bx, --By);
					Sleep(100);
					erasecolorBullet(0, 0);
					clear_bullet(Bx, By);
					setcolor(4, 2);
				}
				else {
					if (cursor(Bx, By - 1) == '*') {
						//Beep(800, 200);
						erasecolorBullet(0, 0);
						clear_bullet(Bx, By);
						eraseStar(Bx, By);
						do {
							randY = rand() % 4 + 2;
							randX = rand() % 60 + 10;
						} while (cursor(randX, randY)!='*');
						setcolor(4, 2);
						drawStar(randX, randY);
						randX = 0;
						randY = 0;
						bullet = 0;
						score++;
						gotoxy(0, 0);
						//setcolor(6, 0);
						printf("Score : %d", score);
					}
				erasecolorBullet(0, 0);
				clear_bullet(Bx, By);
				setcolor(4, 2);
				draw_bullet(Bx, --By);
				}
				Sleep(100);
			}
			ammo--;
			bullet = 0;
			erasecolorBullet(0, 0);
			clear_bullet(Bx, By);
		}
	{
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
		}
			Sleep(50);
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
	printf("^");
}
void clear_bullet(int Bx, int By) {
	gotoxy(Bx, By);
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
void erasecolorBullet(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
	printf("");
}
void drawStar(int x, int y) {
	gotoxy(x, y); printf("*");
}
void eraseStar(int x, int y) {
	gotoxy(x, y); printf(" ");
}
char cursor(int x, int y) {
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (
		!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))

		return '\0';
	else
		return buf[0];
}*/