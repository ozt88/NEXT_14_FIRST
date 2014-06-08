#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sparse.h"

//실습 4
//transpos 함수 구현
//희소 행렬을 인자로 받아서 희소 행렬의 전치 행렬을 리턴하는 함수

spars_t* transPos(spars_t* sMatrix)
{
	int pos = 1;
	spars_t* tMatrix;

	if (!sMatrix)
	{
		return NULL;
	}

	tMatrix = (spars_t*)malloc(sizeof(spars_t)*(sMatrix[0].value + BUFFER));
	memset(tMatrix, 0, sizeof(spars_t)*(sMatrix[0].value + BUFFER));

	tMatrix[0].colNum = sMatrix[0].rowNum;
	tMatrix[0].rowNum = sMatrix[0].colNum;
	tMatrix[0].value = sMatrix[0].value;
	for (int i = 0; i < sMatrix[0].colNum; i++)
	{
		for (int j = 0; j < sMatrix[0].value; j++)
		{
			if (sMatrix[j + 1].colNum == i)
			{
				tMatrix[pos].rowNum = sMatrix[j + 1].colNum;
				tMatrix[pos].colNum = sMatrix[j + 1].rowNum;
				tMatrix[pos++].value = sMatrix[j + 1].value;
			}
		}
	}

	//맨뒤 추가
	tMatrix[tMatrix[0].value + 1].rowNum = tMatrix[0].rowNum;

	return tMatrix;
}
