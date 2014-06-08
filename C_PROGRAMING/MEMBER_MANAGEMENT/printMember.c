#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//회원들을 출력하는 함수

int printData(userInfo_t* userInfoArr, int top)
{
	int startPos = 1;
	int endPos = startPos + CONSOLENUM;
	int input = 3;

	if (!userInfoArr) return -1;

	while (input){

		system("cls");
		if (endPos < top && input == 1) startPos = endPos;
		else if (startPos > CONSOLENUM && input == 2) startPos -= CONSOLENUM;

		endPos = startPos + CONSOLENUM;
		printf("%-5s\t%12s\t%15s\t%30s\n", "회원ID", "회원이름", "회원주소", "연락처");
		printf("=============================================================================\n");
		for (int i = startPos; i < endPos; i++)
		{
			if (i < top) printf("%-5d\t%10s\t%-30s\t%15s\n", userInfoArr[i].userId, userInfoArr[i].userName, userInfoArr[i].userAddress, userInfoArr[i].phone);
			else printf("\n");
		}
		printf("=============================================================================\n");
		printf("1.Next 2.Previous 0.Quit :");
		scanf_s("\n%d", &input);
	}

	return 0;
}