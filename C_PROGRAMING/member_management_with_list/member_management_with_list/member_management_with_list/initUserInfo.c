#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//파일을 읽어서 트리에 입력하는 함수.
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
		//노드를 만들고 앞서 만든 노드의 뒤에 삽입한다.
		prevNode = currentNode;
		currentNode = makeNode();
		fscanf(fp, "%d\t%[^\t]\t%[^\t]\t%[^\n]\n", &(currentNode->data.userId), currentNode->data.userName, currentNode->data.userAddress, currentNode->data.phone);
		insertNode(prevNode, currentNode);
		nodeCount++;
	}
	return nodeCount;
}