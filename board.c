#include <stdio.h>
#include <stdlib.h>

#include "board.h" 
#include "functions.h" 

void printDivider( int size ){
	int i;
	for(i = 0; i<(size*7)+1; i++){
		printf("-");
	}
	printf("\n");
}

void printBoard(const int* board, int size ){
	int i, j;
	printDivider( size );
	for ( i = 0; i < size; i++){
		printf("|");
		for ( j = 0 ;  j < size ;  j++){

			if(*(board+ i * size + j) == 0)
				printf("      ");
			else
		    		printf("%5d ", *(board+ i * size + j));     
			printf("|");

		}

		printf("\n");
		printDivider( size );

	}
	printf("\n\n");
}

void PrintGameTitle(int score,int bestScore, int maxScore){
	printf("-----------  STARTING A GAME ------------\n");
	printf("           Score for a win %d         \n",maxScore);
	printf("-----------------------------------------\n\n");
	printf("Score %d Best %d\n",score,bestScore);

}

void cleanBoard(int* board, int size){
	int i, j;
	for (i = 0; i < size; i++){
		for (j = 0 ;  j < size ;  j++){
		*(board+i*size+j) = 0;
		}
	}
}

int isBoardFull(int* board, int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++)
			if(*(board + size*i + j) == 0)
				return 0;
	}
	return 1;
}

int isBoardEmpty(int* board,int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++)
			if(*(board + size*i + j) != 0)
				return 0;
	}
	return 1;
}

int isMergeNotPossible(int* board, int size){
	int currNum;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
		currNum = *(board + size*i + j);
			if(*(board + size*i + j + 1) == currNum && j != size-1) //check right
				return 0;
			else if(*(board + size*i + j -1) == currNum && j != 0) //check left
				return 0;
			else if(*(board + size*(i+1) + j) == currNum && i != size-1) //check down
				return 0;
			else if(*(board + size*(i-1) + j) == currNum && i != 0) //check up
				return 0;
		}
	}
	return 1;
}


void insertNewNum(int* board,int size){
	int index1, index2;
	do{
		getRandomIndexes( &index1,&index2, size);
	}while(*(board + index1 * size + index2) != 0);
		*(board + index1*size + index2) = getRandomTwoOrFour();

}

int shiftRight(int* board, int size){
	int count = 0;
	int j = size - 1;
	for(int i = size - 1 ; i >= 0; i--){
		if(*(board + i) != 0){
			if (i != j){
				*(board + j) = *(board + i);
				*(board + i) = 0;
				count++;
			}
			j--;
		}
	}
	if(count) return 1;
	else return 0;
}


int mergeRight(int* board, int size,int* score){
	int count = 0;
	for(int i = size - 1; i > 0; i--){
		if(*(board + i) == *(board + i - 1) && *(board + i) != 0){
			*(board + i) = *(board + i) * 2;
			*score += *(board + i);
			*(board + i - 1) = 0;
			count++;
		}
	}
	if(count) return 1;
	return 0;
}

int shiftLeft(int* board, int size){
	int count = 0;
	int j =0;
	for(int i = 0; i < size; i++){
		if(*(board + i) != 0){
			if (i != j){
				*(board + j) = *(board + i);
				*(board + i) = 0;
				count++;
			}
			j++;
		}
	}
	if(count) return 1;
	else return 0;
}


int mergeLeft(int* board, int size,int* score){
	int count = 0;
	for(int i = 0; i < size-1; i++){
		if(*(board + i) == *(board + i + 1) && *(board + i) != 0){
			*(board + i) = *(board + i) * 2;
			*score += *(board + i);
			*(board + i + 1) = 0;
			count++;
		}
	}
	if(count) return 1;
	return 0;
}


int shiftDown(int* board, int size){
	int count = 0;
	int j = size-1;
	for(int i = size -1 ; i >= 0; i--){
		if(*(board+(i*size)) != 0){
			if (i != j){
				*(board + j*size) = *(board + i*size);
				*(board + i*size) = 0;
				count++;
			}
			j--;
		}
	}
	if(count) return 1;
	else return 0;
}

int mergeDown(int* board, int size,int* score){
	int count = 0;
	for(int i = size - 1; i > 0; i--){
		if(*(board + i*size) == *(board + (i- 1)*size ) && *(board + i*size) != 0){
			*(board + i*size) = *(board + i*size) * 2;
			*score += *(board + i*size);
			*(board + (i - 1)*size) = 0;
			count++;
		}
	}
	if(count) return 1;
	return 0;
}

int shiftUp(int* board, int size){
	int count = 0;
	int j = 0;
	for(int i = 0 ; i < size; i++){
		if(*(board+(i*size)) != 0){
			if (i != j){
				*(board + j*size) = *(board + i*size);
				*(board + i*size) = 0;
				count++;
			}
			j++;
		}
	}
	if(count) return 1;
	else return 0;
}

int mergeUp(int* board, int size,int* score){
	int count = 0;
	for(int i = 0; i <size-1; i++){
		if(*(board + i*size) == *(board + (i- 1)*size ) && *(board + i*size) != 0){
			*(board + i*size) = *(board + i*size) * 2;
			*score += *(board + i*size);
			*(board + (i - 1)*size) = 0;
			count++;
		}
	}
	if(count) return 1;
	return 0;
}


