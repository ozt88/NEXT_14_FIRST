#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"

//HW#15.C3 ��Ŀ�ú�� �����Լ� ����
//�׽�Ʈ �����͸� ���ڷ� �޾Ƽ� �Ʒ��� �Լ��� �׽�Ʈ�ϴ� �Լ�

int testInsertNodeWithRecursive(int* testData)
{
	tree_t* tree;
	node_t* nodeArr[TEST_NUM];
	if (!testData)
	{
		return -1;
	}

	tree = makeTree();
	for (int i = 0; testData[i] && i < TEST_NUM; i++)
	{
		nodeArr[i] = makeNode();
		nodeArr[i]->data = testData[i];
		bstInsertNodeWithRecursive(tree, tree->root, (node_t*)NULL, nodeArr[i]);
	}

	testBSTWithInorder(tree);
	clearTreeWithNode(tree->root);
	return 0;
}

//��Ŀ�ú�� �����Լ� ����

int bstInsertNodeWithRecursive(tree_t* tree, node_t* currentNode, node_t* parentNode, node_t* givenNode)
{
	if (!givenNode)
	{
		return -1;
	}

	
	if (!currentNode)
	{
		if (!parentNode)
		{
			tree->root = givenNode;
		}
		else if (givenNode->data < parentNode->data)
		{
			parentNode->leftChild = givenNode;
		}
		else
		{
			parentNode->rightChild = givenNode;
		}
	}
	else if (currentNode->data < givenNode->data)
	{
		bstInsertNodeWithRecursive(tree, currentNode->rightChild, currentNode, givenNode);
	}
	else
	{
		bstInsertNodeWithRecursive(tree, currentNode->leftChild, currentNode, givenNode);
	}
	return 0;
}