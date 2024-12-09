#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "board.h"
#include "menu.h"
#include "functions.h"

char handleMenu(){
	char ch;
	printMenu();
	scanf("\n%c",&ch);
	return tolower(ch);
}
void printMenu(){
	printf("Please choose one of the Following options:\n");
	printf("N/n - New Game\n");
	printf("R/r - Move Right\n");
	printf("L/l - Move Left\n");
	printf("U/u - Move Up\n");
	printf("D/d - Move Down\n");
	printf("E/e - Exit\n");
}
int moveUp(int* board,int size,int* score){
	int isPossible = 0,isEmpty = 0;
	isEmpty = isBoardEmpty(board, size);
	if(isEmpty){
		printf("Need to start game first\n\n\n");
		return 0;
	}
	for(int i = 0; i < size; i++){
		isPossible += shiftUp(board + i , size);
		isPossible += mergeUp(board + i , size,score);
		shiftUp(board + i, size);
	}
	if(!isPossible){
		printf("Nothing to move in this direction, choose another option\n\n\n");
		return 0;
	}
	return 1;
}
int moveDown(int* board, int size,int* score){
	int isPossible = 0,isEmpty = 0;
	isEmpty = isBoardEmpty(board, size);
	if(isEmpty){
		printf("Need to start game first\n\n\n");
		return 0;
	}
	for(int i = 0; i < size; i++){
		isPossible += shiftDown(board + i , size);
		isPossible += mergeDown(board + i , size,score);
		shiftDown(board + i, size);
	}
	if(!isPossible){
		printf("Nothing to move in this direction, choose another option\n\n\n");
		return 0;
	}
	
	
	return 1;
}
int moveLeft(int* board,int size,int* score){
	int isPossible = 0,isEmpty = 0;
	isEmpty = isBoardEmpty(board, size);
	if(isEmpty){
		printf("Need to start game first\n\n\n");
		return 0;
	}
	for(int i = 0; i < size; i++){
		isPossible += shiftLeft(board + i*size, size);
		isPossible += mergeLeft(board + i*size, size,score);
		shiftLeft(board + i*size, size);
	}
	if(!isPossible){
		printf("Nothing to move in this direction, choose another option\n\n\n");
		return 0;
	}
	
	
	return 1;
}
int moveRight(int* board,int size,int* score){
	int isPossible = 0,isEmpty = 0;
	isEmpty = isBoardEmpty(board, size);
	if(isEmpty){
		printf("Need to start game first\n\n\n");
		return 0;
	}
	for(int i = 0; i < size; i++){
		isPossible += shiftRight(board + i*size, size);
		isPossible += mergeRight(board + i*size, size,score);
		shiftRight(board + i*size, size);
	}
	if(!isPossible){
		printf("Nothing to move in this direction, choose another option\n\n\n");
		return 0;
	}
	
	return 1;
}
void newGame(int* board, int size){
	int index1,index2,index3,index4;
	cleanBoard(board,  size);
	getRandomIndexes( &index1,&index2, size);
	do {
		getRandomIndexes( &index3,&index4 ,size);
	}while(index1 == index3 && index2 == index4);
	
	*(board + index1*size + index2 ) = getRandomTwoOrFour();
	*(board + index3*size + index4  ) = getRandomTwoOrFour();
}
