#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sparse.h"

//TEST DATA
static int matrix[ROWNUM][COLNUM] =
{
	{ 15, 0, 0, 22, 0, -15 },
	{ 0, 11, 3, 0, 0, 0 },
	{ 0, 0, 0, -6, 0, 0 },
	{ 0, 0, 12, 0, 0, 0 },
	{ 91, 0, 0, 0, 1, 0 },
	{ 0, 0, 28, 0, 0, 24 }
};

//실제 구현 여부를 확인하는 메인 함수.
int main(void){

	spars_t* sMatrix;
	spars_t* tMatrix;
	spars_t* result1;
	spars_t* result2;
	spars_t* result3;

	sMatrix = makeSparseMatrix(matrix, ROWNUM, COLNUM);
	printf("Sparse matrix\n");
	printSparsMatrix(sMatrix, sMatrix[0].value + BUFFER );

	tMatrix = transPos(sMatrix);
	printf("\nTransposed Sparse matrix\n");
	printSparsMatrix(tMatrix, tMatrix[0].value + BUFFER );


	tMatrix = fastTransPos(sMatrix);
	printf("\nFast Transposed Sparse matrix\n");
	printSparsMatrix(tMatrix, tMatrix[0].value + BUFFER);

	tMatrix = oneArrFastTranspos(sMatrix);
	printf("\nTransposed Sparse matrix with One Array\n");
	printSparsMatrix(tMatrix, tMatrix[0].value + BUFFER);

	printf("\nMulti Result with Block\n");
	result1 = sparseMulti(sMatrix, tMatrix);
	printSparsMatrix(result1, RESULTNUM);

	printf("\nMulti Result without Block\n");
	result2 = NonBlockMulti(sMatrix, tMatrix);
	printSparsMatrix(result2, RESULTNUM);

	printf("\nMulti Result without Transpos\n");
	result3 = nonTransMulti(sMatrix, tMatrix);
	printSparsMatrix(result3, RESULTNUM);


	if (sMatrix)free(sMatrix);
	if (tMatrix)free(tMatrix);
	if (result1)free(result1);
	if (result2)free(result2);
	if (result3)free(result3);

	return 0;
}






