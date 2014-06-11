
//저번 과제에서 사용된 함수 재탕

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"binaryTree.h"


node_t* makeNode(void)
{
	node_t* newNode = (node_t*)malloc(sizeof(node_t));

	memset(newNode, 0, sizeof(node_t));
	return newNode;
}

tree_t* makeTree(void)
{
	tree_t* newTree = (tree_t*)malloc(sizeof(tree_t));

	memset(newTree, 0, sizeof(tree_t));
	return newTree;
}


tree_t* makeSampleTree(void)
{
	tree_t* testTree = makeTree();
	node_t* nodeArr[NODE_NUM];
	char input;

	for (int i = 0; i < NODE_NUM; i++)
	{
		nodeArr[i] = makeNode();
	}

	testTree->root = nodeArr[0];

	nodeArr[0]->data = '+';
	nodeArr[0]->leftChild = nodeArr[1];
	nodeArr[0]->rightChild = nodeArr[2];
	nodeArr[0]->parent = NULL;

	nodeArr[1]->data = '*';
	nodeArr[1]->leftChild = nodeArr[3];
	nodeArr[1]->rightChild = nodeArr[4];
	nodeArr[1]->parent = nodeArr[0];

	nodeArr[2]->data = 'E';
	nodeArr[2]->leftChild = NULL;
	nodeArr[2]->rightChild = NULL;
	nodeArr[2]->parent = nodeArr[0];

	nodeArr[3]->data = '*';
	nodeArr[3]->leftChild = nodeArr[5];
	nodeArr[3]->rightChild = nodeArr[6];
	nodeArr[3]->parent = nodeArr[1];

	nodeArr[4]->data = 'D';
	nodeArr[4]->leftChild = NULL;
	nodeArr[4]->rightChild = NULL;
	nodeArr[4]->parent = nodeArr[1];

	nodeArr[5]->data = '/';
	nodeArr[5]->leftChild = nodeArr[7];
	nodeArr[5]->rightChild = nodeArr[8];
	nodeArr[5]->parent = nodeArr[3];

	nodeArr[6]->data = 'C';
	nodeArr[6]->leftChild = NULL;
	nodeArr[6]->rightChild = NULL;
	nodeArr[6]->parent = nodeArr[3];

	nodeArr[7]->data = 'A';
	nodeArr[7]->leftChild = NULL;
	nodeArr[7]->rightChild = NULL;
	nodeArr[7]->parent = nodeArr[5];

	nodeArr[8]->data = 'B';
	nodeArr[8]->leftChild = NULL;
	nodeArr[8]->rightChild = NULL;
	nodeArr[8]->parent = nodeArr[5];

	return testTree;
}

