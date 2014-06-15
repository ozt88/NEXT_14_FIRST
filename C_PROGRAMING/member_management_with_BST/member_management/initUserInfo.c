#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//파일을 읽어서 트리에 입력하는 함수.
int initUserInfo(tree_t* infoTree, FILE* fp)
{
	node_t* currentNode;
	char buffer[BUFFERSIZE];
	int nodeCount = 0;

	if (!infoTree || !fp)
	{
		return -1;
	}
 
	fgets(buffer, sizeof(buffer), fp);
	while (!feof(fp))
	{
		//노드를 만들고 데이터를 입력하고 바로 삽입한다. 
		//BST는 아이디순으로 자동 정렬되어 삽입되므로 그냥 삽입하면 됨.
		currentNode = makeNode();
		fscanf(fp, "%d\t%[^\t]\t%[^\t]\t%[^\n]\n", &(currentNode->data.userId), currentNode->data.userName, currentNode->data.userAddress, currentNode->data.phone);
		bstInsertNode(infoTree, currentNode);
	}
	return 0;
}