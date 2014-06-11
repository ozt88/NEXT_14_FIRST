
//���� �������� ����� �Լ� ����


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"binaryTree.h"

int testTreeWithInorder(tree_t* tree)
{
	if (!tree)
	{
		return -1;
	}

	//printf("INORDER PRINT\n\n");
	inorderPrint(tree->root);
	printf("\n");
	return 0;
}


int inorderPrint(node_t* node)
{
	if (!node)
	{
		return -1;
	}

	inorderPrint(node->leftChild);
	printf("%3c", node->data);
	inorderPrint(node->rightChild);

	return 0;
}