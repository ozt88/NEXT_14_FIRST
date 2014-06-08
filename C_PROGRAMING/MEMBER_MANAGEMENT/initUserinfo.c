#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

// ȸ������ ���α׷��� �ʱ�ȭ�ϴ� �Լ�

userInfo_t* initUserinfo(FILE* fp, int* top, int* capacity)
{
	char buffer[BUFFERSIZE] = { 0, };
	userInfo_t* userInfo = (userInfo_t*)malloc(sizeof(userInfo_t)*(*capacity));

	//���α׷� ���۰��Բ� ������ �о���� 
	if (fp == NULL)
	{
		puts("data.txt file read open error!\n");
		return NULL;
	}

	//������ �������� ����ü ũ�� ����
	while ((fgets(buffer, sizeof(buffer), fp)) != NULL)
	{
		(*top)++;
	}
	userInfo = checkCapacity(userInfo, *top, capacity);
	fseek(fp, 0, SEEK_SET);

	//���� ������ ����ü�� ���� �� ����
	inputStructData(userInfo, fp);
	userInfo = arrangeStructData(userInfo, *top);

	return userInfo;
}

//������ �о ����ü�� �Է��ϴ� �Լ�.

int inputStructData(userInfo_t* userInfoArr, FILE* fp)
{
	int top = 0;
	char buffer[BUFFERSIZE];

	fgets(buffer, sizeof(buffer), fp);
	while (!feof(fp))
	{
		top++;
		fscanf(fp, "%d\t%[^\t]\t%[^\t]\t%[^\n]", &(userInfoArr[top].userId), userInfoArr[top].userName, userInfoArr[top].userAddress, userInfoArr[top].phone);
	}
	return 0;
}


