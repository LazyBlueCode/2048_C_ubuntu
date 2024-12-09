#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "menu.h"
#include "board.h"
 #include "functions.h"

void playGame(int* board, int size, int maxScore){
	char input;
	int isWin = 0,isLose =0 , score=0,bestScore =0;
	printBoard((int*)board, size);
	input = handleMenu();
	while (input){
		
		int isMoved = 0;
		if (input == 'n' ){
			score = 0;
			newGame((int*) board ,size);
			PrintGameTitle(score,bestScore,maxScore);
			printBoard((int*)board, size);
		}
		else if (input == 'r' ){
			isMoved = moveRight((int*) board ,size,&score);	
		}
		else if (input == 'l' ){
			isMoved = moveLeft((int*) board ,size,&score);
		}
		else if (input == 'u' ){
			isMoved = moveUp((int*) board ,size,&score);
		}
		else if (input == 'd' ){
			isMoved = moveDown((int*) board ,size,&score);
		}
		else if (input == 'e' ){
			cleanBoard((int*) board, size);
			return;
		}
		else {
			printf("Wrong option\n\n");	

		}
		if(isMoved){
				insertNewNum((int*)board, size);
				if(score>bestScore)
					bestScore = score;
				printf("Score %d Best %d\n",score,bestScore);
				printBoard((int*)board, size);
		}
		isWin = checkIfWon(maxScore,score);
		isLose = isBoardFull((int*)board, size) && isMergeNotPossible((int*)board, size);
		if(isWin){
			cleanBoard((int*) board, size);			
			printf("You won %d!  - Ending Game\n\n",score);	
		}
		if(isLose){
			cleanBoard((int*) board, size);			
			printf("Game over your score is %d\n\n",score);	
		}
		input = handleMenu();
	}
}



