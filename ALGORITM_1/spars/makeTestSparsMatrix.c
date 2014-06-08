#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sparse.h"

//실습 4.
//일반 2차 행렬을 받아서 희소 행렬로 변환 후 리턴하는 함수.

spars_t* makeSparseMatrix(int matrix[][COLNUM], int colNum, int rowNum){

	spars_t* sMatrix;
	int valueId = 1;
	int valueNum = 0;
	
	if (!matrix)
	{
		return NULL;
	}

	for (int i = 0; i < rowNum; i++)
	{
		for (int j = 0; j < colNum; j++)
		{
			if (matrix[i][j] != 0) valueNum++;
		}
	}
	sMatrix = (spars_t*)malloc(sizeof(spars_t)*(valueNum + BUFFER));
	memset(sMatrix, 0, sizeof(spars_t)*(valueNum + BUFFER));

	sMatrix[0].rowNum = rowNum;
	sMatrix[0].colNum = colNum;
	sMatrix[0].value = valueNum;

	for (int i = 0; i < rowNum; i++)
	{
		for (int j = 0; j < colNum; j++)
		{
			if (*(*(matrix + i) + j) != 0)
			{
				sMatrix[valueId].rowNum = i;
				sMatrix[valueId].colNum = j;
				sMatrix[valueId].value = matrix[i][j];
				valueId++;
			}
		}
	}

	//맨뒤 추가
	sMatrix[valueId].rowNum = sMatrix[0].rowNum;

	return sMatrix;
}