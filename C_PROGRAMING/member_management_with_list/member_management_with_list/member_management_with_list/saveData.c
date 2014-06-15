#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//구조체의 정보를 다시 파일에 저장하는 함수

int saveData(list_t* userInfoList, FILE* fp)
{
	if (fp == NULL)
	{
		puts("data.txt file write open error!\n");
		return -1;
	}

	fputs("학생번호\t학생이름\t학생주소\t학생번호\n", fp);
	for (node_t* currentNode = userInfoList->head->next; currentNode; currentNode = currentNode->next)
	{
		fprintf(fp, "%d\t%s\t%s\t%s\n", currentNode->data.userId, currentNode->data.userName, currentNode->data.userAddress, currentNode->data.phone);
	}
	printf("\n\t저장 완료\n");
	fflush(stdin);
	getchar();

	return 0;
}
