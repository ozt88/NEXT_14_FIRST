#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"binaryTree.h"

// �ǽ� ���� 8 TEST�Լ�

int EqaulityTest(tree_t* srcTree)
{
	tree_t* dstTree;

	if (!srcTree)
	{
		return -1;
	}

	//���纻�� ����
	dstTree = copyBinaryTree(srcTree);
	testingTreeEquality(srcTree, dstTree);

	//������� Ȯ���ϴ� ���� (Ʈ���� �ƴ϶� ���� ���ؾߵǼ� �ٸ� �Լ� ���)
	if (testingTreeEqualityWithNode(srcTree->root, (node_t*)NULL))
	{
		printf("These trees are equal.\n");
	}
	else
	{
		printf("These trees are different.\n");
	}

	if (testingTreeEqualityWithNode((node_t*)NULL, dstTree->root))
	{
		printf("These trees are equal.\n");
	}
	else
	{
		printf("These trees are different.\n");
	}

	return 0;
}

//�ΰ��� Ʈ���� ���ڷ� �޾Ƽ� �� Ʈ���� ���������� �׽�Ʈ�ϴ� �Լ�.
//�Է��� �߸������� -1, ���̸� 1, �����̸� 0�� �����Ѵ�.

int testingTreeEquality(tree_t* tree1, tree_t* tree2)
{
	int output = 0;

	if (!tree1 || !tree2)
	{
		printf("input Error.\n");
		output = -1;
	}

	else if (testingTreeEqualityWithNode(tree1->root, tree2->root))
	{
		printf("These trees are equal.\n");
		output = 1;
	}
	else
	{
		printf("These trees are different.\n");
		output = 0;
	}

	return output;
}

int testingTreeEqualityWithNode(node_t* node1, node_t* node2)
{
	if (!node1 && node2 || node1 && !node2)
	{
		return 0;
	}
	if (!node1 && !node2)
	{
		return 1;
	}

	else if (node1->data != node2->data)
	{
		return 0;
	}
	else if (!testingTreeEqualityWithNode(node1->leftChild, node2->leftChild))
	{
		return 0;
	}
	else if (!testingTreeEqualityWithNode(node1->rightChild, node2->rightChild))
	{
		return 0;
	}

	return 1;
}