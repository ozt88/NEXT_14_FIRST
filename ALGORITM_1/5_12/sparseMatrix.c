#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sparse.h"


int main(void){

	spar* smatrix;
	spar* tmatrix;
	spar* result1;
	spar* result2;
	spar* result3;
	int** arr;
	int m, n;
	int matrix[ROWNUM][COLNUM] =
	{
		{ 15, 0, 0, 22, 0, -15 },
		{ 0, 11, 3, 0, 0, 0 },
		{ 0, 0, 0, -6, 0, 0 },
		{ 0, 0, 12, 0, 0, 0 },
		{ 91, 0, 0, 0, 1, 0 },
		{ 0, 0, 28, 0, 0, 24 }
	};
	printf("input m, n: ");
	scanf("%d %d", &m, &n);
	arr = make2darray(m, n);
	smatrix = makeSparseMatrix(arr, m, n);
	//smatrix = makeSparseMatrix(matrix, ROWNUM, COLNUM);
	printf("Sparse matrix\n");
	for (int i = 0; i < smatrix[0].value + 2; i++)
	{
		//printf("[%d , %d] %5d\n", smatrix[i].rowNum, smatrix[i].colNum, smatrix[i].value);
	}
	
	//tmatrix = transePos(smatrix);
	//tmatrix = fastTransePos(smatrix);
	tmatrix = oneArrFastTransepos(smatrix);
	printf("\nTranseposed Sparse matrix\n");
	for (int i = 0; i < tmatrix[0].value + 2; i++)
	{
		//printf("[%d , %d] %5d\n", tmatrix[i].rowNum, tmatrix[i].colNum, tmatrix[i].value);
	}

	printf("\nMulti Result with Block\n");
	result1 = sparseMulti(smatrix, tmatrix);
	for (int z = 0; z < RESULTNUM; z++)
	{
		if (result1[z].value != 0) printf("[%d, %d] %5d\n", result1[z].rowNum, result1[z].colNum, result1[z].value);
	}

	printf("\nMulti Result without Block\n");
	result2 = NonBlockMulti(smatrix, tmatrix);
	for (int z = 0; z < RESULTNUM ; z++)
	{
		if (result2[z].value != 0) printf("[%d, %d] %5d\n", result2[z].rowNum, result2[z].colNum, result2[z].value);
	}

	printf("\nMulti Result without Transpos\n");
	result3 = nonTransMulti(smatrix, tmatrix);
	for (int z = 0; z < RESULTNUM ; z++)
	{
		if (result3[z].value != 0) printf("[%d, %d] %5d\n", result3[z].rowNum, result3[z].colNum, result3[z].value);
	}

	if (smatrix)free(smatrix);
	if (tmatrix)free(tmatrix);
	if (result1)free(result1);
	if (result2)free(result2);
	if (result3)free(result3);

	return 0;
}


spar* makeSparseMatrix(int** matrix, int colNum, int rowNum){

	spar* smatrix;
	int valueId = 1;
	int valueNum = 0;

	for (int i = 0; i < rowNum; i++)
	{
		for (int j = 0; j < colNum; j++)
		{
			if (matrix[i][j] != 0) valueNum++;
		}
	}
	 
	smatrix = (spar*)malloc(sizeof(spar)*(valueNum + 2));
	memset(smatrix, 0, sizeof(spar)*(valueNum + 2));
	
	smatrix[0].rowNum = rowNum;
	smatrix[0].colNum = colNum;
	smatrix[0].value = valueNum;

	for (int i = 0; i < rowNum; i++)
	{
		for (int j = 0; j < colNum; j++)
		{
			if (*(*(matrix + i) + j) != 0)
			{
				smatrix[valueId].rowNum = i;
				smatrix[valueId].colNum = j;
				smatrix[valueId].value = matrix[i][j];
				valueId++;
			}
		}
	}

	//맨뒤 추가
	smatrix[valueId].rowNum = smatrix[0].rowNum;

	return smatrix;
}

spar* transePos(spar* smatrix)
{
	spar* tmatrix;
	int pos = 1;

	tmatrix = (spar*)malloc(sizeof(spar)*(smatrix[0].value + 2));
	memset(tmatrix, 0, sizeof(spar)*(smatrix[0].value + 2));

	tmatrix[0].colNum = smatrix[0].rowNum;
	tmatrix[0].rowNum = smatrix[0].colNum;
	tmatrix[0].value = smatrix[0].value;
	for (int i = 0; i < smatrix[0].colNum; i++)
	{
		for (int j = 0; j < smatrix[0].value; j++)
		{
			if (smatrix[j + 1].colNum == i)
			{
				tmatrix[pos].rowNum = smatrix[j + 1].colNum;
				tmatrix[pos].colNum = smatrix[j + 1].rowNum;
				tmatrix[pos++].value = smatrix[j + 1].value;
			}
		}
	}

	//맨뒤 추가
	tmatrix[tmatrix[0].value + 1].rowNum = tmatrix[0].rowNum;

	return tmatrix;
}


spar* fastTransePos(spar* smatrix)
{
	spar* tmatrix;
	int* rowTerms;
	int* startPos;
	int pos;
	int valNum = smatrix[0].value;
	int colNum = smatrix[0].colNum;
	int rowNum = smatrix[0].rowNum;

	tmatrix = (spar*)malloc(sizeof(spar)*(valNum + 2));
	rowTerms = (int*)malloc(sizeof(int)*colNum);
	startPos = (int*)malloc(sizeof(int)*colNum);

	memset(tmatrix, 0, sizeof(spar)*(valNum + 2));
	memset(rowTerms, 0, sizeof(int)*colNum);
	memset(startPos, 0, sizeof(int)*colNum);

	for (int i = 1; i <= valNum; i++)
	{
		rowTerms[smatrix[i].colNum]++;
	}

	startPos[0] = 1;

	for (int i = 1; i < colNum; i++)
	{
		startPos[i] = startPos[i - 1] + rowTerms[i - 1];
	}


	tmatrix[0].colNum = smatrix[0].rowNum;
	tmatrix[0].rowNum = smatrix[0].colNum;
	tmatrix[0].value = smatrix[0].value;

	for (int i = 1; i <= smatrix[0].value; i++)
	{
		pos = startPos[smatrix[i].colNum]++;
		tmatrix[pos].rowNum = smatrix[i].colNum;
		tmatrix[pos].colNum = smatrix[i].rowNum;
		tmatrix[pos].value = smatrix[i].value;
	}

	//맨뒤 추가
	tmatrix[tmatrix[0].value + 1].rowNum = tmatrix[0].rowNum;

	return tmatrix;
}


spar* oneArrFastTransepos(spar* smatrix)
{
	spar* tmatrix;
	int* startPos;
	int sum = 1, temp = 0, pos = 0;

	tmatrix = (spar*)malloc(sizeof(spar)*(smatrix[0].value + 2));
	startPos = (int*)malloc(sizeof(int)*smatrix[0].colNum);
	memset(tmatrix, 0, sizeof(spar)*(smatrix[0].value + 2));
	memset(startPos, 0, sizeof(int)*smatrix[0].colNum);

	for (int i = 1; i <= smatrix[0].value; i++)
	{
		startPos[smatrix[i].colNum]++;
	}
	for (int i = 0; i < smatrix[0].colNum; i++)
	{
		temp = startPos[i];
		startPos[i] = sum;
		sum += temp;
	}


	tmatrix[0].colNum = smatrix[0].rowNum;
	tmatrix[0].rowNum = smatrix[0].colNum;
	tmatrix[0].value = smatrix[0].value;

	for (int i = 1; i <= smatrix[0].value; i++)
	{
		pos = startPos[smatrix[i].colNum]++;
		tmatrix[pos].rowNum = smatrix[i].colNum;
		tmatrix[pos].colNum = smatrix[i].rowNum;
		tmatrix[pos].value = smatrix[i].value;
	}

	//맨뒤 추가
	tmatrix[tmatrix[0].value + 1].rowNum = tmatrix[0].rowNum;

	return tmatrix;
}

int findEndRowPos(spar* mat, int startPos)
{
	int endPos = startPos;
	while (endPos + 1 <= mat[0].value  && mat[endPos + 1].rowNum == mat[endPos].rowNum) endPos++;
	return endPos;
}


int startEndMulti(spar* mat1, spar* mat2, spar* result, int startid1, int endid1, int startid2, int endid2)
{
	int count = 0;
	int sum = 0;
	int idx1 = startid1, idx2 = startid2;
	while (idx1 <= endid1 && idx2 <= endid2)
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

	result->rowNum = mat1[startid1].rowNum;
	result->colNum = mat2[startid2].rowNum;
	result->value = sum;
	return count;
}


spar* sparseMulti(spar* mat1, spar* mat2)
{
	spar* tmat2;
	spar* result;
	int count = 0;
	int idx = 0;
	int startPos1 = 1, endPos1 = 1, startPos2 = 1, endPos2 = 1;

	result = (spar*)malloc(sizeof(spar)* RESULTNUM);
	memset(result, 0, sizeof(spar)* RESULTNUM);
	tmat2 = fastTransePos(mat2);

	do{
		endPos1 = findEndRowPos(mat1, startPos1);
		startPos2 = 1;
		do{
			endPos2 = findEndRowPos(tmat2, startPos2);
			count += startEndMulti(mat1, tmat2, &result[idx++], startPos1, endPos1, startPos2, endPos2);
			startPos2 = endPos2 + 1;
			count++;
		} while (startPos2 <= tmat2[0].value);
		startPos1 = endPos1 + 1;
		count++;
	} while (startPos1 <= mat1[0].value);
	printf("blocked transed count\n%d\n", count);
	return result;
}


spar* NonBlockMulti(spar* mat1, spar* mat2)
{
	spar* result;
	spar* tmat2 = fastTransePos(mat2);
	int i = 0, idx1 = 1, idx2 = 1, count = 0;

	result = (spar*)malloc(sizeof(spar)* RESULTNUM);
	memset(result, 0, sizeof(spar)* RESULTNUM);

	while (mat1[idx1].rowNum != mat1[0].rowNum && tmat2[idx2].rowNum != tmat2[0].rowNum)
	{
		result[i].rowNum = mat1[idx1].rowNum;
		result[i].colNum = tmat2[idx2].rowNum;
		count++;
		//일단 한블럭 끝까지 보냄

		while (mat1[idx1].rowNum == mat1[idx1 + 1].rowNum && tmat2[idx2].rowNum == tmat2[idx2 + 1].rowNum)
		{
			if (mat1[idx1].colNum == tmat2[idx2].colNum)
			{
				result[i].value += mat1[idx1].value * tmat2[idx2].value;
				idx1++; idx2++;
				//printf("[%d %d] [%d %d]\n", mat1[idx1].rowNum, mat1[idx1].colNum, tmat2[idx2].rowNum, tmat2[idx2].colNum);
			}
			else if (mat1[idx1].colNum < tmat2[idx2].colNum) {
				idx1++;  
				//printf("[%d %d] [%d %d]\n", mat1[idx1].rowNum, mat1[idx1].colNum, tmat2[idx2].rowNum, tmat2[idx2].colNum);
			}
			else if (mat1[idx1].colNum > tmat2[idx2].colNum) {
				idx2++;  
				//printf("[%d %d] [%d %d]\n", mat1[idx1].rowNum, mat1[idx1].colNum, tmat2[idx2].rowNum, tmat2[idx2].colNum);
			}
			count++;
		}

		while (mat1[idx1].rowNum == mat1[idx1 + 1].rowNum)
		{
			if (mat1[idx1].colNum == tmat2[idx2].colNum)
			{
				result[i].value += mat1[idx1].value * tmat2[idx2].value;
			}
			idx1++;
			count++;
			//printf("[%d %d] [%d %d]\n", mat1[idx1].rowNum, mat1[idx1].colNum, tmat2[idx2].rowNum, tmat2[idx2].colNum);
		}

		while (tmat2[idx2].rowNum == tmat2[idx2 + 1].rowNum)
		{
			if (mat1[idx1].colNum == tmat2[idx2].colNum)
			{
				result[i].value += mat1[idx1].value * tmat2[idx2].value;
			}
			idx2++;
			count++;
			//printf("[%d %d] [%d %d]\n", mat1[idx1].rowNum, mat1[idx1].colNum, tmat2[idx2].rowNum, tmat2[idx2].colNum);
		}

		//바운더리 컨디션 확인하면서 다음 result로 진행

		if (tmat2[idx2 + 1].rowNum == tmat2[0].rowNum)
		{
			if (mat1[idx1].colNum == tmat2[idx2].colNum)
			{
				result[i].value += mat1[idx1].value * tmat2[idx2].value;
			}
			idx1++;
			idx2 = 1;
			i++;
			count++;
			//printf("[%d %d] [%d %d]\n", mat1[idx1].rowNum, mat1[idx1].colNum, tmat2[idx2].rowNum, tmat2[idx2].colNum);
		}

		else
		{
			if (mat1[idx1].colNum == tmat2[idx2].colNum)
			{
				result[i].value += mat1[idx1].value * tmat2[idx2].value;
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
			//printf("[%d %d] [%d %d]\n", mat1[idx1].rowNum, mat1[idx1].colNum, tmat2[idx2].rowNum, tmat2[idx2].colNum);
		}
		count++;

	}
	printf("nonblocked transed count\n%d\n", count);
	return result;
}


spar* nonTransMulti(spar* mat1, spar* mat2)
{
	spar* result;
	int idx = 0;
	int sum = 1, temp = 0;
	int* multiStart;
	int* valueArr;
	int startPos=1, endPos=1;
	int count = 0;

	result = (spar*)malloc(sizeof(spar)* RESULTNUM);
	multiStart = (int*)malloc(sizeof(int)*mat1[0].colNum + 1);
	valueArr = (int*)malloc(sizeof(int)*mat2[0].colNum);
	memset(result, 0, sizeof(spar)* RESULTNUM);
	memset(multiStart, 0, sizeof(int)*(mat1[0].colNum + 1));
	memset(valueArr, 0, sizeof(int)*mat2[0].colNum);

	//multiStart mat2의 각 rowNum이 어디서 시작하는지를 알려주는 배열

	for (int i = 1; i <= mat2[0].value; i++)
	{
		multiStart[mat2[i].rowNum]++;
		count++;
		//연산횟수 전채 갯수
	}
	for (int i = 0; i < mat2[0].rowNum; i++)
	{
		temp = multiStart[i];
		multiStart[i] = sum;
		sum += temp;
		count++;
		//연산횟수 행 갯수
	}

	//Boundary Condition Check 
	//mat1의 colNum이 mat2의 rowNum의 마지막 수인 경우를 대비해서  
	//전체갯수 + 1 값을 multiStart에 넣어주고 그 부분은 초기화하지 않는다.
	multiStart[mat2[0].rowNum] = mat2[0].value + 1;

	//mat1의 블록별로 진행한다.
	//multiStart를 참조해서 mat1과 같은 rowNum을 가진 mat2들의 위치를 파악하고 그것만 연산후 결과를 valueArr에 저장한다.
	//valueArr은 mat2의 colNum별 연산 값을 저장하고 mat1의 한 블럭 연산이 끝나면 값을 result에게 전달한다.
	//이것이 가능한 이유는 mat1의 한 블럭은 모두 같은 rowNum을 가지고 있기 때문이다. 
	//mat1의 rowNum과 valueArr에 있는 colNum별 value값을 참조해서 result에게 모든 연산 값을 전달할 수 있다.

	while (startPos <= mat1[0].value){
		endPos = findEndRowPos(mat1, startPos);
		memset(valueArr, 0, sizeof(int)*mat2[0].colNum);
		count++;
		for (int i = startPos; i <= endPos; i++)
		{
			//블락별 연산하므로 결국 연산횟수 전채 갯수
			for (int j = multiStart[mat1[i].colNum]; j < multiStart[(mat1[i].colNum) + 1]; j++)
			{
				//연산횟수 한 열의 갯수(최악의 경우 전체 열의 갯수)
				if (mat1[i].colNum == mat2[j].rowNum)
				{
					valueArr[mat2[j].colNum] += mat1[i].value * mat2[j].value;
					count++;
					
				}
			}
		}
		//결국 최악의 경우 전체 갯수 * 열 개수
		for (int i = 0; i < mat2[0].colNum; i++)
		{
			if (valueArr[i]) 
			{
				result[idx].rowNum = mat1[startPos].rowNum;
				result[idx].colNum = i;
				result[idx].value = valueArr[i];
				idx++;
			}
			count++;
			//블럭당 연산하므로 블럭 개수*열 개수
			//최악의 경우 전체 개수*열 개수
		}
		startPos = endPos + 1;
	}
	printf("Nontranse count\n%d\n", count);
	//전체 연산 최악의 경우 = O(전체 개수*열개수)
	return result;
}

int** make2darray(int m, int n){
	int** rows;
	rows = (int**)malloc(sizeof(int*)*m);
	for (int i = 0; i < m; i++)
	{
		rows[i] = (int*)malloc(sizeof(int)*n);
		for (int j = 0; j < n; j++)
		{
			rows[i][j] = rand()%3;
		}
	}
	return rows;
}
