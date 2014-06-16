#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"

//트리를 모두 프리하는 함수

void clearTreeWithNode(node_t* node)
{
	if (!node)
	{
		return;
	}

	if (!node->leftChild && !node->rightChild)
	{
		free(node);
		return;
	}
	clearTreeWithNode(node->rightChild);
	clearTreeWithNode(node->leftChild);

	return;
}