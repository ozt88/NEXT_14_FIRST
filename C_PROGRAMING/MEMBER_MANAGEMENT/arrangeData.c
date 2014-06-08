#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//저장된 회원 정보를 id순으로 정렬하는 함수


userInfo_t* arrangeStructData(userInfo_t* userInfoArr, int top)
{
	int minIdx;
	int tempNum = 0;

	for (int startId = 1; startId < top; startId++)
	{
		minIdx = findMinIdx(userInfoArr, startId, top);

		tempNum = userInfoArr[startId].userId;
		userInfoArr[startId].userId = userInfoArr[minIdx].userId;
		userInfoArr[minIdx].userId = tempNum;

		swapStr(userInfoArr[startId].userName, userInfoArr[minIdx].userName);
		swapStr(userInfoArr[startId].userAddress, userInfoArr[minIdx].userAddress);
		swapStr(userInfoArr[startId].phone, userInfoArr[minIdx].phone);

	}

	userInfoArr[top].userId = (userInfoArr[top - 1].userId) + 1;

	return userInfoArr;
}

int swapStr(char* str1, char* str2)
{
	char tempStr[BUFFERSIZE] = { 0, };
	
	if (!str1 || !str2)
	{
		return -1;
	}

	strcpy(tempStr, str1);
	strcpy(str1, str2);
	strcpy(str2, tempStr);

	return 0;
}

int findMinIdx(userInfo_t* userInfo_t, int startId, int top)
{

	int minIdx = startId;

	for (int i = startId + 1; i < top; i++)
	{
		if (userInfo_t[minIdx].userId > userInfo_t[i].userId) minIdx = i;
	}

	return minIdx;
}