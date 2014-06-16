
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"

//3번처럼 출력하는 함수
int testBSTlikeNo3(node_t* resultNode)
{
	if (resultNode)
	{
		printf("data : %d\n", resultNode->data);

		if (resultNode->parent)
		{
			printf("parent address : %p\n", resultNode->parent);
			printf("parent data : %d \n", resultNode->parent->data);
		}
		else
		{
			printf("No parent\n");
			printf("No parent\n");
		}
		if (resultNode->leftChild)
		{
			printf("leftChild address : %p\n", resultNode->leftChild);
			printf("leftChild data : %d \n", resultNode->leftChild->data);
		}
		else
		{
			printf("No leftChild\n");
			printf("No leftChild\n");
		}
		if (resultNode->rightChild)
		{
			printf("rightChild address : %p\n", resultNode->rightChild);
			printf("rightChild data : %d \n", resultNode->rightChild->data);
		}
		else
		{
			printf("No rightChild\n");
			printf("No rightChild\n");
		}
	}
	else
	{
		printf("No Data\n");
	}
	printf("\n");

	return 0;
}

//각각 리커시브하게 inorder, preorder, postorder출력
int testBSTWithInorder(tree_t* tree)
{
	if (!tree)
	{
		return -1;
	}

	testBSTWithInorderWithNode(tree->root);
	printf("\n");
	return 0;
}


void testBSTWithInorderWithNode(node_t* node)
{
	if (!node)
	{
		return;
	}

	testBSTWithInorderWithNode(node->leftChild);
	printf("%3d", node->data);
	testBSTWithInorderWithNode(node->rightChild);

	return;
}

int testBSTWithPreorder(tree_t* tree)
{
	if (!tree)
	{
		return -1;
	}

	testBSTWithPreorderWithNode(tree->root);
	printf("\n");
	return 0;
}

void testBSTWithPreorderWithNode(node_t* node)
{
	if (!node)
	{
		return;
	}

	printf("%3d", node->data);
	testBSTWithPreorderWithNode(node->leftChild);
	testBSTWithPreorderWithNode(node->rightChild);

	return;
}

int testBSTWithPostorder(tree_t* tree)
{
	if (!tree)
	{
		return -1;
	}

	testBSTWithPostorderWithNode(tree->root);
	printf("\n");
	return 0;
}

void testBSTWithPostorderWithNode(node_t* node)
{
	if (!node)
	{
		return;
	}
	testBSTWithPostorderWithNode(node->leftChild);
	testBSTWithPostorderWithNode(node->rightChild);
	printf("%3d", node->data);

	return;
}