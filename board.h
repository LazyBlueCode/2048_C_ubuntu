#ifndef __BOARD__
#define __BOARD__

void printBoard(const int* board, int size );
void PrintGameTitle(int score,int bestScore, int maxScore);
void printDivider( int size );
void cleanBoard(int* board, int size);
int shiftRight(int* board, int size);
int shiftLeft(int* board, int size);
int shiftDown(int* board, int size);
int shiftUp(int* board, int size);
int mergeUp(int* board, int size,int* score);
int mergeDown(int* board,int  size,int* score);
int mergeRight(int* board, int size,int* score);
int mergeLeft(int* board, int size,int* score);
void insertNewNum(int* board,int size);
int isBoardFull(int* board, int size);
int isMergeNotPossible(int* board, int size);
int isBoardEmpty(int* board,int size);

#endif
