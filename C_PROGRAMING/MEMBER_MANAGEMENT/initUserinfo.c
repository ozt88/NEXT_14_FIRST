#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

// 회원관리 프로그램을 초기화하는 함수

userInfo_t* initUserinfo(FILE* fp, int* top, int* capacity)
{
	char buffer[BUFFERSIZE] = { 0, };
	userInfo_t* userInfo = (userInfo_t*)malloc(sizeof(userInfo_t)*(*capacity));

	//프로그램 시작과함께 데이터 읽어오기 
	if (fp == NULL)
	{
		puts("data.txt file read open error!\n");
		return NULL;
	}

	//데이터 개수세서 구조체 크기 조정
	while ((fgets(buffer, sizeof(buffer), fp)) != NULL)
	{
		(*top)++;
	}
	userInfo = checkCapacity(userInfo, *top, capacity);
	fseek(fp, 0, SEEK_SET);

	//파일 데이터 구조체에 저장 후 정렬
	inputStructData(userInfo, fp);
	userInfo = arrangeStructData(userInfo, *top);

	return userInfo;
}

//파일을 읽어서 구조체에 입력하는 함수.

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


