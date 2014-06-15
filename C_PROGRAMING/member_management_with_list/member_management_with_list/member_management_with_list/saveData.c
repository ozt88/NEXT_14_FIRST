#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//����ü�� ������ �ٽ� ���Ͽ� �����ϴ� �Լ�

int saveData(list_t* userInfoList, FILE* fp)
{
	if (fp == NULL)
	{
		puts("data.txt file write open error!\n");
		return -1;
	}

	fputs("�л���ȣ\t�л��̸�\t�л��ּ�\t�л���ȣ\n", fp);
	for (node_t* currentNode = userInfoList->head->next; currentNode; currentNode = currentNode->next)
	{
		fprintf(fp, "%d\t%s\t%s\t%s\n", currentNode->data.userId, currentNode->data.userName, currentNode->data.userAddress, currentNode->data.phone);
	}
	printf("\n\t���� �Ϸ�\n");
	fflush(stdin);
	getchar();

	return 0;
}
