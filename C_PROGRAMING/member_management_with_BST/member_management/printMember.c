#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//����ϴ� �Լ�
int printData(tree_t* infoTree)
{
	//node_t* currentNode;
	if (!infoTree)
	{
		return -1;
	}
	system("cls");
	printf("%-5s\t%12s\t%15s\t%30s\n", "ȸ��ID", "ȸ���̸�", "ȸ���ּ�", "����ó");
	printf("=============================================================================\n");
	inorderPrint(infoTree->root);
	printf("=============================================================================\n");
	printf("����Ϸ��� �ƹ�Ű�� �����ּ���\n");
	fflush(stdin);
	getchar();

	return 0;
}

//�ο����� ��Ŀ�ú�� �迭, ����Ʈó�� ���� ����ϴ� ��� ������ ��ƴ�.
int inorderPrint(node_t* node)
{
	if (!node)
	{
		return 0;
	}
	inorderPrint(node->leftChild);
	printf("%-5d\t%10s\t%-30s\t%15s\n", node->data.userId, node->data.userName, node->data.userAddress, node->data.phone);
	inorderPrint(node->rightChild);

	return 0;
}