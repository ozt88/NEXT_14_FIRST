#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"

//실습주제 12

//최대값 찾는 것을 3번처럼 출력하여 테스트하는 함수
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

//아래의 함수를 사용하여 트리를 인자로 받아서 MAX를 찾는 함수

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


//node_t * bstMaximumBelow(node_t * node) 함수 구현
//Node를 root로 하는 tree에서 key 값이 큰 노드 return
//입력 node가 NULL이면 NULL을 return


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