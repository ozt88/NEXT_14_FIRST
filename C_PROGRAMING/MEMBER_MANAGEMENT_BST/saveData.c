#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//구조체의 정보를 다시 파일에 저장하는 함수

int saveData(tree_t* userInfoTree, FILE* fp)
{
	if (fp == NULL)
	{
		puts("data.txt file write open error!\n");
		return -1;
	}

	fputs("학생번호\t학생이름\t학생주소\t학생번호\n", fp);
	saveDataWithNode(userInfoTree->root, fp);
	printf("\n\t저장 완료\n");
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
