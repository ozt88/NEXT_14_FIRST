#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"

//�ǽ����� 11

//�Ʒ��� �Լ��� 3��ó�� ����ؼ� �׽�Ʈ
int testFindMinInBST(tree_t* BST)
{
	node_t* resultNode;

	if (!BST)
	{
		return -1;
	}
	resultNode = findMinInBST(BST);
	testBSTlikeNo3(resultNode);

	return 0;
}

//�Ʒ��� �Լ��� Ʈ���� ���ڷ� �޾Ƽ� �۵��ϰ� ���� �Լ�

node_t* findMinInBST(tree_t* BST)
{
	node_t* currentNode;
	if (!BST)
	{
		return (node_t*)NULL;
	}
	currentNode = BST->root;
	while (currentNode)
	{
		if (!currentNode->leftChild)
		{
			break;
		}
		currentNode = currentNode->leftChild;
	}
	return currentNode;
}

//node_t * bstMinimumBelow(node_t * node) �Լ� ����
//Node�� root�� �ϴ� tree���� key ���� ���� ���� ��� return
//�Է� node�� NULL�̸� NULL�� return


node_t* findMinInBSTWithNode(node_t* currentNode)
{
	if (!currentNode)
	{
		return (node_t*)NULL;
	}

	else if (!currentNode->leftChild)
	{
		return currentNode;
	}

	else
	{
		return findMinInBSTWithNode(currentNode->leftChild);
	}
}