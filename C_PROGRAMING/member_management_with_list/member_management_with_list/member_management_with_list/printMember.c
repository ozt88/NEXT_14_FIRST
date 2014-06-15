#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//출력하는 함수
int printData(list_t* userInfoList, int top)
{
	int startPos = 0;
	int input = 3;
	node_t* currentNode;
	if (!userInfoList)
	{
		return -1;
	}

	while (input)
	{
		system("cls");
		if (startPos + CONSOLENUM < top && input == 1)
		{
			startPos = startPos + CONSOLENUM;
		}
		else if (startPos >= CONSOLENUM && input == 2)
		{
			startPos -= CONSOLENUM;
		}
		currentNode = moveNodeByIdx(userInfoList, startPos);
		printf("%-5s\t%12s\t%15s\t%30s\n", "회원ID", "회원이름", "회원주소", "연락처");
		printf("=============================================================================\n");

		for (int count = 0; count < CONSOLENUM; count++)
		{
			if (currentNode)
			{
				printf("%-5d\t%10s\t%-30s\t%15s\n", currentNode->data.userId, currentNode->data.userName, currentNode->data.userAddress, currentNode->data.phone);
				currentNode = currentNode->next;
			}
			else
			{
				printf("\n");
			}
		}

		printf("=============================================================================\n");
		printf("1.Next 2.Previous 0.Quit :");
		fflush(stdin);
		scanf_s("\n%d", &input);
	}

	return 0;
}

//리스트는 넥스트로 이동하는 횟수를 가지고 배열처럼 사용할 수 있다.
//배열에서 사용된 나눠 출력이 쉽게 구현가능.
node_t* moveNodeByIdx(list_t* list, int idx)
{
	node_t* currentNode = list->head->next;
	for (int i = 0; i < idx; i++)
	{
		currentNode = currentNode->next;
	}

	return currentNode;
}