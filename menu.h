#ifndef __MENU__
#define __MENU__

char handleMenu();
void printMenu();
int moveUp(int* board,int size,int* score);
int moveDown(int* board,int size,int* score);
int moveLeft(int* board,int size,int* score);
int moveRight(int* board,int size,int* score);
void newGame(int* board,int size);
#endif
