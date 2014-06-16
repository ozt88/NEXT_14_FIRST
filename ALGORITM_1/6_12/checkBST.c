#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"

//#15.C5
//BST인지 여부를 확인하는 함수

int testCheckBST(tree_t* tree)
{
	if (!tree)
	{
		return -1;
	}

	if (checkBST(tree->root, 1000000, -1000000))
	{
		printf("This Tree is BST.\n");
	}
	else
	{
		printf("This Tree is Not BST.\n");
	}
	
	return 0;
}

//BST이면 1을 아니면 0을 리턴하는 리커시브 함수
int checkBST(node_t* node, int max, int min)
{
	
	if (!node)
	{
		return 1;
	}

	if (node->data < min || node->data > max)
	{
		return 0;
	}
	
	return (checkBST(node->leftChild, node->data, min) && checkBST(node->rightChild, max, node->data));
	
}