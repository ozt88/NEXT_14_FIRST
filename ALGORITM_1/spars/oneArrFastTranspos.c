#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sparse.h"

//#11.C5
//fastTranspos ���� ���Ǵ� �ΰ��� �迭
//rowTerms �� startPos �� �ϳ��� �ٿ��� �����ϴ� �Լ�
//���ڷ� �������� �޾Ƽ� �������� ��ġ ����� �����Ѵ�.

spars_t* oneArrFastTranspos(spars_t* sMatrix)
{
	spars_t* tMatrix;
	int* startPos;
	int sum = 1, temp = 0, pos = 0;

	if (!sMatrix)
	{
		return NULL;
	}

	tMatrix = (spars_t*)malloc(sizeof(spars_t)*(sMatrix[0].value + BUFFER));
	startPos = (int*)malloc(sizeof(int)*sMatrix[0].colNum);
	memset(tMatrix, 0, sizeof(spars_t)*(sMatrix[0].value + BUFFER));
	memset(startPos, 0, sizeof(int)*sMatrix[0].colNum);

	for (int i = 1; i <= sMatrix[0].value; i++)
	{
		startPos[sMatrix[i].colNum]++;
	}
	for (int i = 0; i < sMatrix[0].colNum; i++)
	{
		temp = startPos[i];
		startPos[i] = sum;
		sum += temp;
	}


	tMatrix[0].colNum = sMatrix[0].rowNum;
	tMatrix[0].rowNum = sMatrix[0].colNum;
	tMatrix[0].value = sMatrix[0].value;

	for (int i = 1; i <= sMatrix[0].value; i++)
	{
		pos = startPos[sMatrix[i].colNum]++;
		tMatrix[pos].rowNum = sMatrix[i].colNum;
		tMatrix[pos].colNum = sMatrix[i].rowNum;
		tMatrix[pos].value = sMatrix[i].value;
	}

	//�ǵ� �߰�
	tMatrix[tMatrix[0].value + 1].rowNum = tMatrix[0].rowNum;

	return tMatrix;
}