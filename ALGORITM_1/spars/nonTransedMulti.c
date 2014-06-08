#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sparse.h"

//#11.C6
//��ġ ����� ������� �ʰ� ��� ��� ������ �����ϴ� �Լ�
//���ڷ� �ΰ��� ��� ����� �޾Ƽ� �� ����� ���� ��� ��ķ� �����Ѵ�.

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

	//multiStart mat2�� �� rowNum�� ��� �����ϴ����� �˷��ִ� �迭

	for (int i = 1; i <= mat2[0].value; i++)
	{
		multiStart[mat2[i].rowNum]++;
		count++;
		//����Ƚ�� ��ä ����
	}
	for (int i = 0; i < mat2[0].rowNum; i++)
	{
		temp = multiStart[i];
		multiStart[i] = sum;
		sum += temp;
		count++;
		//����Ƚ�� �� ����
	}

	//Boundary Condition Check 
	//mat1�� colNum�� mat2�� rowNum�� ������ ���� ��츦 ����ؼ�  
	//��ü���� + 1 ���� multiStart�� �־��ְ� �� �κ��� �ʱ�ȭ���� �ʴ´�.
	multiStart[mat2[0].rowNum] = mat2[0].value + 1;

	//mat1�� ��Ϻ��� �����Ѵ�.
	//multiStart�� �����ؼ� mat1�� ���� rowNum�� ���� mat2���� ��ġ�� �ľ��ϰ� �װ͸� ������ ����� valueArr�� �����Ѵ�.
	//valueArr�� mat2�� colNum�� ���� ���� �����ϰ� mat1�� �� �� ������ ������ ���� result���� �����Ѵ�.
	//�̰��� ������ ������ mat1�� �� ���� ��� ���� rowNum�� ������ �ֱ� �����̴�. 
	//mat1�� rowNum�� valueArr�� �ִ� colNum�� value���� �����ؼ� result���� ��� ���� ���� ������ �� �ִ�.

	while (startPos <= mat1[0].value){
		endPos = findEndRowPos(mat1, startPos);
		memset(valueArr, 0, sizeof(int)*mat2[0].colNum);
		count++;
		for (int i = startPos; i <= endPos; i++)
		{
			//����� �����ϹǷ� �ᱹ ����Ƚ�� ��ä ����
			for (int j = multiStart[mat1[i].colNum]; j < multiStart[(mat1[i].colNum) + 1]; j++)
			{
				//����Ƚ�� �� ���� ����(�־��� ��� ��ü ���� ����)
				if (mat1[i].colNum == mat2[j].rowNum)
				{
					valueArr[mat2[j].colNum] += mat1[i].value * mat2[j].value;
					count++;

				}
			}
		}
		//�ᱹ �־��� ��� ��ü ���� * �� ����
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
			//���� �����ϹǷ� �� ����*�� ����
			//�־��� ��� ��ü ����*�� ����
		}
		startPos = endPos + 1;
	}
	printf("NonTrans Multi Count = %d\n", count);
	//��ü ���� �־��� ��� = O(��ü ����*������)
	return result;
}
