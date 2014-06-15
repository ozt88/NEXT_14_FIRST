#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//����ϴ� �Լ�
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
		printf("%-5s\t%12s\t%15s\t%30s\n", "ȸ��ID", "ȸ���̸�", "ȸ���ּ�", "����ó");
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

//����Ʈ�� �ؽ�Ʈ�� �̵��ϴ� Ƚ���� ������ �迭ó�� ����� �� �ִ�.
//�迭���� ���� ���� ����� ���� ��������.
node_t* moveNodeByIdx(list_t* list, int idx)
{
	node_t* currentNode = list->head->next;
	for (int i = 0; i < idx; i++)
	{
		currentNode = currentNode->next;
	}

	return currentNode;
}