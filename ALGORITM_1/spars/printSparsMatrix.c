#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sparse.h"

//실습 4.
//희소 행렬을 출력하는 함수
//희소 행렬과 그 크기를 받아서 값을 출력한다.

int printSparsMatrix(spars_t* matrix, int size)
{
	if (!matrix)
	{
		return -1;
	}

	for (int i = 0; i < size; i++)
	{
		if (matrix[i].value != 0) printf("[%d, %d] %5d\n", matrix[i].rowNum, matrix[i].colNum, matrix[i].value);
	}

	return 0;
}