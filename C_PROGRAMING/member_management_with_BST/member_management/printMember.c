#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//출력하는 함수
int printData(tree_t* infoTree)
{
	//node_t* currentNode;
	if (!infoTree)
	{
		return -1;
	}
	system("cls");
	printf("%-5s\t%12s\t%15s\t%30s\n", "회원ID", "회원이름", "회원주소", "연락처");
	printf("=============================================================================\n");
	inorderPrint(infoTree->root);
	printf("=============================================================================\n");
	printf("계속하려면 아무키나 눌러주세요\n");
	fflush(stdin);
	getchar();

	return 0;
}

//인오더가 리커시브라서 배열, 리스트처럼 나눠 출력하는 기능 구현이 어렵다.
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