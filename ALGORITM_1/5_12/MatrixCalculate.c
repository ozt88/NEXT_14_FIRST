#include<stdio.h>
#include<stdlib.h>

int** makearray(int m, int n)
{
	int** rows = (int**)malloc(sizeof(int*)*m);
	for (int i = 0; i < m; i++){
		rows[i] = (int*)malloc(sizeof(int)*n);
		for (int j = 0; j < n; j++){
			printf("input [%d, %d] value:", i, j);
			scanf_s("%d", *(rows + i) + j);
		}
	}
	return rows;
}

int** make2darray(int m, int n)
{
	int** rows = (int**)malloc(sizeof(int*)*m);
	for (int i = 0; i < m; i++){
		rows[i] = (int*)malloc(sizeof(int)*n);
	}
	return rows;
}

void matrixSum(int** result, int **matrix1, int **matrix2, int rowNum, int colNum)
{

	for (int rowIdx = 0; rowIdx < rowNum; rowIdx++)
	{
		for (int colIdx = 0; colIdx < colNum; colIdx++)
		{
			result[rowIdx][colIdx] = matrix1[rowIdx][colIdx] + matrix2[rowIdx][colIdx];
		}
	}
}

void matrixMulti( int** result, int **matrixA, int rowNumOfA, int colNumOfA, int **matrixB, int rowNumOfB, int colNumOfB)
{
	int sum;
	
	for (int rowIdx = 0 ; rowIdx < rowNumOfA ; rowIdx++)
	{
		for (int colIdx = 0 ; colIdx < colNumOfB ; colIdx++)
		{
			sum = 0;
			for (int idx = 0; idx < rowNumOfA; idx++)
			{
				sum += matrixA[rowIdx][idx] * matrixB[idx][colIdx];
			}
			result[rowIdx][colIdx] = sum;
		}
	}
}

void matrixTranspose(int** result, int **matrixA, int rowNum, int colNum)
{
	

	for (int i = 0; i < colNum; i++)
	{
		for (int j = 0; j < rowNum; j++)
		{
			result[i][j] = matrixA[j][i];
		}
	}
}

int main(void)
{
	int input = 1, colNum1, rowNum1, colNum2, rowNum2, resultrow, resultcol;
	int** matrix1;
	int** matrix2;
	int** result;

	while (input)
	{
	printf("Make First Matrix\n Input rowNum and colNum:");
	scanf_s("%d %d", &rowNum1, &colNum1);
	matrix1 = makearray( rowNum1, colNum1);
	printf("Make Second Matrix\n Input rowNum and colNum:");
	scanf_s("%d %d", &rowNum2, &colNum2);
	matrix2 = makearray(rowNum2, colNum2);
	printf("Calculate Two Matrix\n1.Sum\n2.Multiply\n3.Transpos (just First one)\n0.Exit\nInput your choice:");
	scanf_s("%d", &input);

	switch (input)
	{
	case 0: 
		return 0;
	case 1: 
		if (colNum1 != colNum2 || rowNum1 != rowNum2)
		{ 
			printf("Error!\n"); 
			continue; 
		}
		result = make2darray( rowNum1, colNum1);
		matrixSum( result, matrix1, matrix2, rowNum1, colNum1);
		resultrow = rowNum1;
		resultcol = colNum1;
		break;

	case 2:
		if (colNum1 != rowNum2)
		{ 
			printf("Error!\n");
			continue; 
		}
		result = make2darray( rowNum1, colNum2);
		matrixMulti( result, matrix1, rowNum1, colNum1 , matrix2, rowNum2, colNum2);
		resultrow = rowNum1;
		resultcol = colNum2;
		break;

	case 3:

		result = make2darray( colNum1, rowNum1 );
		matrixTranspose( result, matrix1, rowNum1, colNum1);
		resultrow = colNum1;
		resultcol = rowNum1;
		break;
	
	default:
		printf("Input Error!\n");
		continue;
	}

	printf("\n Result \n");

	for (int i = 0; i < resultrow; i++)
	{
		for (int j = 0; j < resultcol; j++)
		{
			printf("%3d", result[i][j]);
		}
		printf("\n");
	}

	if (matrix1) free(matrix1);
	if (matrix2) free(matrix2);
	if (result) free(result);
	
	}
}