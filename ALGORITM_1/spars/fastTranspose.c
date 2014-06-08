#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sparse.h"

//�ǽ� 4
//fastTranspos �Լ� ����
//��� ����� ���ڷ� �޾Ƽ� ��� ����� ��ġ ����� �����ϴ� �Լ�
//���� ��ġ�� ����ؼ� �ð� ���⵵�� ����

spars_t* fastTransPos(spars_t* sMatrix)
{
	spars_t* tMatrix;
	int* rowTerms;
	int* startPos;
	int pos;
	int valNum = sMatrix[0].value;
	int colNum = sMatrix[0].colNum;
	int rowNum = sMatrix[0].rowNum;
	
	if (!sMatrix)
	{
		return NULL;
	}

	tMatrix = (spars_t*)malloc(sizeof(spars_t)*(valNum + BUFFER));
	memset(tMatrix, 0, sizeof(spars_t)*(valNum + BUFFER));
	rowTerms = (int*)malloc(sizeof(int)*colNum);
	startPos = (int*)malloc(sizeof(int)*colNum);

	memset(rowTerms, 0, sizeof(int)*colNum);
	memset(startPos, 0, sizeof(int)*colNum);

	for (int i = 1; i <= valNum; i++)
	{
		rowTerms[sMatrix[i].colNum]++;
	}

	startPos[0] = 1;

	for (int i = 1; i < colNum; i++)
	{
		startPos[i] = startPos[i - 1] + rowTerms[i - 1];
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

