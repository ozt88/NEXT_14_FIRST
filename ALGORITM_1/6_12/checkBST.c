#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"

//#15.C5
//BST���� ���θ� Ȯ���ϴ� �Լ�

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

//BST�̸� 1�� �ƴϸ� 0�� �����ϴ� ��Ŀ�ú� �Լ�
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