#ifndef __SPARSE_H__
#define __SPARSE_H__


typedef struct Spar{
	int colNum;
	int rowNum;
	int value;
}spar;

#define ROWNUM 6
#define COLNUM 6
#define RESULTNUM 10000

spar* makeSparseMatrix(int matrix[][COLNUM], int colNum, int rowNum);
spar* transePos(spar* smatrix);
spar* fastTransePos(spar* smatrix);
int findEndRowPos(spar* mat, int startPos);
int startEndMulti(spar* mat1, spar* mat2, spar* result, int startid1, int endid1, int startid2, int endid2);
spar* sparseMulti(spar* mat1, spar* mat2);
spar* NonBlockMulti(spar* mat1, spar* mat2);
spar* oneArrFastTransepos(spar* smatrix);
spar* nonTransMulti(spar* mat1, spar* mat2);
int** make2darray(int m, int n);

#endif