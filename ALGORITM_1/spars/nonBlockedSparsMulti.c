#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sparse.h"

//#11.C7 ��� ������ ������� �ʴ� ������� ��� ��� ������ �����ϴ� �Լ�
//�ΰ��� ��� ����� ���ڷ� �޾Ƽ� �� ���� �����ϴ� �Լ�.

spars_t* NonBlockMulti(spars_t* mat1, spars_t* mat2)
{
	spars_t* result;
	spars_t* tMat2;
	int i = 0, idx1 = 1, idx2 = 1, count = 0;
	if (!mat1 || !mat2)
	{
		return NULL;
	}

	tMat2 = fastTransPos(mat2);
	result = (spars_t*)malloc(sizeof(spars_t)* RESULTNUM);
	memset(result, 0, sizeof(spars_t)* RESULTNUM);

	while (mat1[idx1].rowNum != mat1[0].rowNum && tMat2[idx2].rowNum != tMat2[0].rowNum)
	{
		result[i].rowNum = mat1[idx1].rowNum;
		result[i].colNum = tMat2[idx2].rowNum;
		count++;
		//�ϴ� �Ѻ� ������ ����

		while (mat1[idx1].rowNum == mat1[idx1 + 1].rowNum && tMat2[idx2].rowNum == tMat2[idx2 + 1].rowNum)
		{
			if (mat1[idx1].colNum == tMat2[idx2].colNum)
			{
				result[i].value += mat1[idx1].value * tMat2[idx2].value;
				idx1++; idx2++;
			}
			else if (mat1[idx1].colNum < tMat2[idx2].colNum) {
				idx1++;
			}
			else if (mat1[idx1].colNum > tMat2[idx2].colNum) {
				idx2++;
			}
			count++;
		}

		while (mat1[idx1].rowNum == mat1[idx1 + 1].rowNum)
		{
			if (mat1[idx1].colNum == tMat2[idx2].colNum)
			{
				result[i].value += mat1[idx1].value * tMat2[idx2].value;
			}
			idx1++;
			count++;
		}

		while (tMat2[idx2].rowNum == tMat2[idx2 + 1].rowNum)
		{
			if (mat1[idx1].colNum == tMat2[idx2].colNum)
			{
				result[i].value += mat1[idx1].value * tMat2[idx2].value;
			}
			idx2++;
			count++;
		}

		//�ٿ���� ����� Ȯ���ϸ鼭 ���� result�� ����

		if (tMat2[idx2 + 1].rowNum == tMat2[0].rowNum)
		{
			if (mat1[idx1].colNum == tMat2[idx2].colNum)
			{
				result[i].value += mat1[idx1].value * tMat2[idx2].value;
			}
			idx1++;
			idx2 = 1;
			i++;
			count++;
		}

		else
		{
			if (mat1[idx1].colNum == tMat2[idx2].colNum)
			{
				result[i].value += mat1[idx1].value * tMat2[idx2].value;
			}
			for (int j = 0; j < (mat1[0].value); j++)
			{
				count++;
				if (mat1[j].rowNum == mat1[idx1].rowNum)
				{
					idx1 = j;
					break;
				}
			}
			idx2++;
			i++;
		}
		count++;

	}
	printf("Nonblocked Multi Count = %d\n", count);
	return result;
}
