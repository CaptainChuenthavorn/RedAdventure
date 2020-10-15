#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	gotoxy(x, y); printf("<-0->");
}
void erase_ship(int x, int y)
{
	gotoxy(x, y); printf("     ");
}
void draw_bullet(int x, int y)
{
	gotoxy(x, y); printf("^");
}
void clear_bullet(int x, int y)
{
	gotoxy(x, y); printf(" ");
}
void drawStar(int x, int y) {
	gotoxy(x, y), printf("*");
}
void eraseStar(int x, int y) {
	gotoxy(x, y); printf(" ");
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void erasecolorBullet(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
	printf("");
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
char cursor(int x, int y);
int main() {
	char ch = '.';
	int x = 38, y = 20;
	int bx, by, i;
	int bullet = 0;
	int  randX = 0, randY = 0;
	int score = 0, direction=0,ammo=100;
	srand(time(NULL));
	for (int round = 0; round < 20; round++)
	{
		randY = rand() % 4 + 2;
		randX = rand() % 60 + 10;
		drawStar(randX, randY);
		randX = 0;
		randY = 0;
	}
	setcursor(0);
	setcolor(4, 2);
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') { direction = 1; }
			if (ch == 'd') { direction = 2; }
			if (ch == 's') { direction = 0; }
			if (bullet != 1 && ch == ' ') {
				bullet = 1; bx = x + 2; by = y - 1;
			}
			fflush(stdin);
		}
		if (direction == 1) {
			setcolor(0, 0);
			erase_ship(x, y);
			setcolor(4, 2);
			draw_ship(--x, y);
		}
		if (direction == 2) {
			setcolor(0, 0);
			erase_ship(x, y);
			setcolor(4, 2);
			draw_ship(++x, y);
		}
		if (bullet == 1 && ammo>0) {
			erasecolorBullet(0, 0);
			clear_bullet(bx, by);
			setcolor(4, 2);
			if (by == 2) { bullet = 0; }
			else {
				if (cursor(bx, by - 1) == '*') {
					//Beep(700, 100);
					erasecolorBullet(0, 0);
					clear_bullet(bx, by);
					eraseStar(bx, by - 1);
					do {
							randY = rand() % 4 + 2;
							randX = rand() % 60 + 10;
						} while (cursor(randX, randY)=='*');
						setcolor(7, 0);
						drawStar(randX, randY);
					randX = 0;
					randY = 0;
					bullet = 0;
					ammo--;
					score++;
					gotoxy(0, 0);
					setcolor(6, 0);
					printf("Ammo : %d\n", ammo);
					printf("Score : %d\n", score);
					
				}
				draw_bullet(bx, --by);	
				if (bullet == 0) { clear_bullet(bx, by); }
			}
			
		}
		if (x < 0) {		 //if out of monitor x<0
			setcolor(0, 0);
			erase_ship(x + 6, y);
			setcolor(4, 2);
			x = 0;
			draw_ship(x, y);
		}
		if (x > 80) {        //if out of monitor x>80
			setcolor(0, 0);
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
		Sleep(50);
		
	} while (ch != 'x');
	return 0;
}
char cursor(int x, int y) {
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (
		!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))
		return '\0';
	else
		return buf[0];
}