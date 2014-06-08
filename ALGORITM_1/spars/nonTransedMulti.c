#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sparse.h"

//#11.C6
//전치 행렬을 사용하지 않고 희소 행렬 곱셈을 구현하는 함수
//인자로 두개의 희소 행렬을 받아서 두 행렬의 곱을 희소 행렬로 리턴한다.

spars_t* nonTransMulti(spars_t* mat1, spars_t* mat2)
{
	spars_t* result;
	int idx = 0;
	int sum = 1, temp = 0;
	int* multiStart;
	int* valueArr;
	int startPos = 1, endPos = 1;
	int count = 0;
	
	if (!mat1 || !mat2)
	{
		return NULL;
	}

	result = (spars_t*)malloc(sizeof(spars_t)* RESULTNUM);
	multiStart = (int*)malloc(sizeof(int)*mat1[0].colNum + 1);
	valueArr = (int*)malloc(sizeof(int)*mat2[0].colNum);
	memset(result, 0, sizeof(spars_t)* RESULTNUM);
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
	printf("NonTrans Multi Count = %d\n", count);
	//전체 연산 최악의 경우 = O(전체 개수*열개수)
	return result;
}
