#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sparse.h"

//�ǽ� 4.
//��� ����� ����ϴ� �Լ�
//��� ��İ� �� ũ�⸦ �޾Ƽ� ���� ����Ѵ�.

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