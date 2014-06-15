#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//����ü�� ������ �ٽ� ���Ͽ� �����ϴ� �Լ�

int saveData(tree_t* userInfoTree, FILE* fp)
{
	if (fp == NULL)
	{
		puts("data.txt file write open error!\n");
		return -1;
	}

	fputs("�л���ȣ\t�л��̸�\t�л��ּ�\t�л���ȣ\n", fp);
	saveDataWithNode(userInfoTree->root, fp);
	printf("\n\t���� �Ϸ�\n");
	fflush(stdin);
	getchar();

	return 0;
}

void saveDataWithNode(node_t* node, FILE* fp)
{
	if (!node)
	{
		return;
	}
	saveDataWithNode(node->leftChild, fp);
	fprintf(fp, "%d\t%s\t%s\t%s\n", node->data.userId, node->data.userName, node->data.userAddress, node->data.phone);
	saveDataWithNode(node->rightChild, fp);

	return;
}
