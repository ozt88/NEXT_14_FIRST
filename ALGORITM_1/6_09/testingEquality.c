#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"binaryTree.h"

// 실습 주제 8 TEST함수

int EqaulityTest(tree_t* srcTree)
{
	tree_t* dstTree;

	if (!srcTree)
	{
		return -1;
	}

	//복사본과 대조
	dstTree = copyBinaryTree(srcTree);
	testingTreeEquality(srcTree, dstTree);

	//경계조건 확인하는 대조 (트리가 아니라 노드로 비교해야되서 다른 함수 사용)
	if (testingTreeEqualityWithNode(srcTree->root, (node_t*)NULL))
	{
		printf("These trees are equal.\n");
	}
	else
	{
		printf("These trees are different.\n");
	}

	if (testingTreeEqualityWithNode((node_t*)NULL, dstTree->root))
	{
		printf("These trees are equal.\n");
	}
	else
	{
		printf("These trees are different.\n");
	}

	return 0;
}

//두개의 트리를 인자로 받아서 두 트리가 동일한지를 테스트하는 함수.
//입력이 잘못됬으면 -1, 참이면 1, 거짓이면 0을 리턴한다.

int testingTreeEquality(tree_t* tree1, tree_t* tree2)
{
	int output = 0;

	if (!tree1 || !tree2)
	{
		printf("input Error.\n");
		output = -1;
	}

	else if (testingTreeEqualityWithNode(tree1->root, tree2->root))
	{
		printf("These trees are equal.\n");
		output = 1;
	}
	else
	{
		printf("These trees are different.\n");
		output = 0;
	}

	return output;
}

int testingTreeEqualityWithNode(node_t* node1, node_t* node2)
{
	if (!node1 && node2 || node1 && !node2)
	{
		return 0;
	}
	if (!node1 && !node2)
	{
		return 1;
	}

	else if (node1->data != node2->data)
	{
		return 0;
	}
	else if (!testingTreeEqualityWithNode(node1->leftChild, node2->leftChild))
	{
		return 0;
	}
	else if (!testingTreeEqualityWithNode(node1->rightChild, node2->rightChild))
	{
		return 0;
	}

	return 1;
}