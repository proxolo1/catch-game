#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
int score = 0;
int x, y,speed=1,n=30;
int targetx, targety;
const int width = 50;
const int height = 30;
bool game; 
enum directions {STOP = 0, UP, DOWN,LEFT,RIGHT};
directions dir;
void gamesetup() {
	game = true;
	dir = STOP;
	x = rand() % width;
	y = rand() % height;
	targetx = rand() % width;
	targety = rand() % height;
	if (x == targetx && y == targety) {
		x = rand() % width;
		y = rand() % height;
		targetx = rand() % width;
		targety = rand() % height;
	}


}

void gamewindow() {
	system("cls");
	for (int i = 0; i < width; i++) {
		cout << "*";
	}
	cout << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width-1) {
				cout << "*";
			}
			else if(i==y && j==x) {
				cout << "0";
			}
			else if (i == targety && j == targetx) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < width; i++) {
		cout << "*";
	}
}

void gamecontrol() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			if (dir != RIGHT) {
				dir = LEFT;
			}
			break;
		case 'd':
			if (dir != LEFT) {
				dir = RIGHT;
			}
			break;
		case 'w':
			if (dir != DOWN) {
				dir = UP;
			}
			break;
		case's':
			if (dir != UP) {
				dir = DOWN;
			}
			break;
		case '0':
			game = false;
			break;
		}
	}
}
void gameprogram() {
	switch (dir) {
	case LEFT:
		x -= speed;
		break;
	case UP:
		y -= speed;
		break;
	case DOWN:
		y += speed;
		break;
	case RIGHT:
		x += speed;
		break;
	}
	if (x == 0 || x == width || y < 0 || y > height) {
		game = false;
		cout << "\n GAME OVER";
	}
	if (targetx == x && targety == y) {
		score=score+10;
		targetx = rand() % width;
		targety = rand() % height;
	}
}
int main() {
	gamesetup();
	while (game == true) {
		gamewindow();
		gamecontrol();
		gameprogram();
		Sleep(n);
		cout << "\n " << "SCORE-->  "<<score;
		if (score == 50) {
			n=5;
		}
	}
}