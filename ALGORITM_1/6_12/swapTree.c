#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"

//#15.C4 5.4 2������
//Ʈ���� �Է¹޾Ƽ� ��� ����� ���� �ڽİ� ������ �ڽ��� ��ȯ�ϴ� �Լ�

//���� ������ ��ȯ�ϴ� �Լ� �׽�Ʈ
//Ʈ���� ���ڷ� �޾Ƽ� ������ �����ϰ� ���

int testSwapTree(tree_t* tree)
{
	if (!tree)
	{
		return -1;
	}

	printf("Before Swap\n");
	testBSTWithInorder(tree);
	swapTreeWithNode(tree->root);
	printf("After Swap\n");
	testBSTWithInorder(tree);

	return 0;
}
int swapTreeWithNode(node_t* node)
{
	node_t* temp;
	if (!node)
	{
		return 0;
	}

	temp = node->rightChild;
	node->rightChild = node->leftChild;
	node->leftChild = temp;
	
	swapTreeWithNode(node->leftChild);
	swapTreeWithNode(node->rightChild);

	return 0;
}