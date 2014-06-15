#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//������ �о Ʈ���� �Է��ϴ� �Լ�.
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
		//��带 ����� �����͸� �Է��ϰ� �ٷ� �����Ѵ�. 
		//BST�� ���̵������ �ڵ� ���ĵǾ� ���ԵǹǷ� �׳� �����ϸ� ��.
		currentNode = makeNode();
		fscanf(fp, "%d\t%[^\t]\t%[^\t]\t%[^\n]\n", &(currentNode->data.userId), currentNode->data.userName, currentNode->data.userAddress, currentNode->data.phone);
		bstInsertNode(infoTree, currentNode);
	}
	return 0;
}