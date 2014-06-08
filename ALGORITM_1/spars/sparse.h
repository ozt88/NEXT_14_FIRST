#ifndef __SPARSE_H__
#define __SPARSE_H__

typedef struct Spars{
	int colNum;
	int rowNum;
	int value;
}spars_t;

#define ROWNUM 6
#define COLNUM 6
#define RESULTNUM 10000
#define BUFFER 2

int printSparsMatrix(spars_t* matrix, int size);
spars_t* makeSparseMatrix(int matrix[][COLNUM], int colNum, int rowNum);

spars_t* transPos(spars_t* sMatrix);
spars_t* fastTransPos(spars_t* sMatrix);
spars_t* oneArrFastTranspos(spars_t* sMatrix);

int findEndRowPos(spars_t* mat, int startPos);
int startEndMulti(spars_t* mat1, spars_t* mat2, spars_t* result, int startId1, int endId1, int startId2, int endId2);
spars_t* sparseMulti(spars_t* mat1, spars_t* mat2);

spars_t* NonBlockMulti(spars_t* mat1, spars_t* mat2);

spars_t* nonTransMulti(spars_t* mat1, spars_t* mat2);

#endif