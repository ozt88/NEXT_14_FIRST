#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//������ �о Ʈ���� �Է��ϴ� �Լ�.
int initUserInfo(list_t* infoList, FILE* fp)
{
	node_t* currentNode;
	node_t* prevNode;
	char buffer[BUFFERSIZE];
	int nodeCount = 0;

	if (!infoList || !fp)
	{
		return -1;
	}
	currentNode = infoList->head;
	fgets(buffer, sizeof(buffer), fp);
	while (!feof(fp))
	{
		//��带 ����� �ռ� ���� ����� �ڿ� �����Ѵ�.
		prevNode = currentNode;
		currentNode = makeNode();
		fscanf(fp, "%d\t%[^\t]\t%[^\t]\t%[^\n]\n", &(currentNode->data.userId), currentNode->data.userName, currentNode->data.userAddress, currentNode->data.phone);
		insertNode(prevNode, currentNode);
		nodeCount++;
	}
	return nodeCount;
}