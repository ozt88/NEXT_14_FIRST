#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"

//실습주제 11

//아래의 함수를 3번처럼 출력해서 테스트
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

//아래의 함수를 트리를 인자로 받아서 작동하게 만든 함수

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

//node_t * bstMinimumBelow(node_t * node) 함수 구현
//Node를 root로 하는 tree에서 key 값이 제일 작은 노드 return
//입력 node가 NULL이면 NULL을 return


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