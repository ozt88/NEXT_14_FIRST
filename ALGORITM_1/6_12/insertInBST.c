#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"

//실습 주제 14
//테스트 데이터를 인자로 받아서 아래의 함수를 테스트하는 함수

int testInsertNode(int* testData)
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
		bstInsertNode(tree, nodeArr[i]);
	}
	
	testBSTWithInorder(tree);
	clearTreeWithNode(tree->root);
	return 0;
}


//void bstInsertNode(tree_t * tree, node_t * givenNode) 함수 구현
//트리와 삽입할 노드를 받아서 트리에 삽입하는 함수

int bstInsertNode(tree_t* tree, node_t* givenNode)
{
	node_t* currentNode;
	node_t* parentNode;
	if (!tree || !givenNode)
	{
		return -1;
	}

	currentNode = tree->root;
	parentNode = (node_t*)NULL;

	while (currentNode)
	{
		parentNode = currentNode;
		if (currentNode->data > givenNode->data)
		{
			currentNode = currentNode->leftChild;
		}
		else
		{
			currentNode = currentNode->rightChild;
		}
	}

	givenNode->parent = parentNode;

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
	

	return 0;
}