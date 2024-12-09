#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#include "functions.h"

void getRandomIndexes(int* index1,int* index2,int size){
	*index1 =rand()%size;
	*index2 =rand()%size;
}

int getRandomTwoOrFour(){
	int num = rand() % 101;
	if(num < 70)
		return 2;
	else
		return 4;

}

int checkIfWon(int maxScore,int score){
	if (score>= maxScore)
		return 1;
	return 0;
		
}



