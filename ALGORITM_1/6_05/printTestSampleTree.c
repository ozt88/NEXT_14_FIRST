
//�ǽ� ���� (3)
//������ Ʈ���� �׽�Ʈ�ϴ� �Լ�
//main()���� makeSampleTree() �Լ� ȣ���ؼ� Ʈ�� ����
//Root�κ��� ��ũ�� ���� �� ��带 ����
//�� ��忡 ���ؼ�
//������ data, parent�� �ּ�, parent�� ����� data, leftChild�� �ּ�, left child�� ����� data, right child�� �ּ�, right child�� ����� data ���

#include<stdio.h>
#include"tree.h"

int testSampleTree(tree_t* testTree)
{
	if (!testTree)
	{
		return -1;
	}
	printf("\n\nTEST TREE\n\n");
	printNode(testTree->root);

	return 0;
}

int printNode(node_t* node)
{
	if (!node)
	{
		return -1;
	}

	printf("%3c,\t", node->value);

	if (node->parent)
	{
		printf("%7p, %3c,\t", node->parent, node->parent->value);
	}
	else
	{
		printf("%7s, %3s,\t", "NULL", "����");
	}

	if (node->leftChild)
	{
		printf("%7p, %3c,\t", node->leftChild, node->leftChild->value);
	}
	else
	{
		printf("%7s, %3s,\t", "NULL", "����");
	}

	if (node->rightChild)
	{
		printf("%7p, %3c", node->rightChild, node->rightChild->value);
	}
	else
	{
		printf("%7s, %3s", "NULL", "����");
	}
	printf("\n");

	printNode(node->leftChild);
	printNode(node->rightChild);

	return 0;
}