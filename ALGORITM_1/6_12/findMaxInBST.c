#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"

//�ǽ����� 12

//�ִ밪 ã�� ���� 3��ó�� ����Ͽ� �׽�Ʈ�ϴ� �Լ�
int testFindMaxInBST(tree_t* BST)
{
	node_t* resultNode;

	if (!BST)
	{
		return -1;
	}
	resultNode = findMaxInBST(BST);
	testBSTlikeNo3(resultNode);

	return 0;
}

//�Ʒ��� �Լ��� ����Ͽ� Ʈ���� ���ڷ� �޾Ƽ� MAX�� ã�� �Լ�

node_t* findMaxInBST(tree_t* BST)
{
	node_t* currentNode;
	if (!BST)
	{
		return (node_t*)NULL;
	}
	currentNode = BST->root;
	while (currentNode)
	{
		if (!currentNode->rightChild)
		{
			break;
		}
		currentNode = currentNode->rightChild;
	}
	return currentNode;
}


//node_t * bstMaximumBelow(node_t * node) �Լ� ����
//Node�� root�� �ϴ� tree���� key ���� ū ��� return
//�Է� node�� NULL�̸� NULL�� return


node_t* findMaxInBSTWithNode(node_t* currentNode)
{
	if (!currentNode)
	{
		return (node_t*)NULL;
	}

	else if (!currentNode->rightChild)
	{
		return currentNode;
	}

	else
	{
		return findMaxInBSTWithNode(currentNode->rightChild);
	}
}