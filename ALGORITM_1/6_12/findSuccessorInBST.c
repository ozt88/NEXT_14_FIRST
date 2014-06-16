#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"


//실습 주제 13

//아래의 함수를 3번처럼 출력하여 테스트하는 함수

int testSuccessor(node_t* node)
{
	node_t* resultNode;
	if (!node)
	{
		return -1;
	}
	resultNode = bstSuccessorOf(node);
	printf("%d's successor\n", node->data);
	testBSTlikeNo3(resultNode);

	return 0;
}

//node_t * bstSuccessorOf(node_t * node) 함수 구현
//Node의 successor node를 출력

node_t* bstSuccessorOf(node_t* node)
{
	node_t* parent;
	if (!node)
	{
		return (node_t*)NULL;
	}
	parent = node->parent;

	if (node->rightChild)
	{
		return findMinInBSTWithNode(node->rightChild);
	}

	while (parent) 
	{
		if (parent->leftChild == node)
		{
			break;
		}
		node = parent;
		parent = node->parent;
	}

	return parent;
}