#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sparse.h"

//실습 4.
//두 희소 행렬을 인자로 받아서 그 곱을 리턴하는 함수.

spars_t* sparseMulti(spars_t* mat1, spars_t* mat2)
{
	spars_t* tMat2;
	spars_t* result;
	int count = 0;
	int idx = 0;
	int startPos1 = 1, endPos1 = 1, startPos2 = 1, endPos2 = 1;
	
	if (!mat1 || !mat2)
	{
		return NULL;
	}

	tMat2 = fastTransPos(mat2);
	result = (spars_t*)malloc(sizeof(spars_t)* RESULTNUM);
	memset(result, 0, sizeof(spars_t)* RESULTNUM);

	do{
		endPos1 = findEndRowPos(mat1, startPos1);
		startPos2 = 1;
		do{
			endPos2 = findEndRowPos(tMat2, startPos2);
			count += startEndMulti(mat1, tMat2, &result[idx++], startPos1, endPos1, startPos2, endPos2);
			startPos2 = endPos2 + 1;
			count++;
		} while (startPos2 <= tMat2[0].value);
		startPos1 = endPos1 + 1;
		count++;
	} while (startPos1 <= mat1[0].value);
	printf("Blocked Multi Count = %d\n", count);
	return result;
}

int findEndRowPos(spars_t* mat, int startPos)
{
	int endPos = startPos;
	while (endPos + 1 <= mat[0].value  && mat[endPos + 1].rowNum == mat[endPos].rowNum) endPos++;
	return endPos;
}

int startEndMulti(spars_t* mat1, spars_t* mat2, spars_t* result, int startId1, int endId1, int startId2, int endId2)
{
	int count = 0;
	int sum = 0;
	int idx1 = startId1, idx2 = startId2;
	while (idx1 <= endId1 && idx2 <= endId2)
	{
		if (mat1[idx1].colNum == mat2[idx2].colNum)
		{
			sum += mat1[idx1].value * mat2[idx2].value;
			idx1++; idx2++;
		}
		else if (mat1[idx1].colNum < mat2[idx2].colNum) idx1++;
		else idx2++;
		count++;
	}

	result->rowNum = mat1[startId1].rowNum;
	result->colNum = mat2[startId2].rowNum;
	result->value = sum;
	return count;
}

