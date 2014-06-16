#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"

//�ǽ� ���� 15

//transplant �Լ��� �׽�Ʈ�ϴ� �Լ�,
//�׽�Ʈ �����Ϳ� ���� ����� ��, �̽��� ����� ���� �޾Ƽ� 
//�̽��ϱ� ���� �ĸ� ���� ���
int testTransplantNode(int* testData, int delNum, int transNum)
{
	tree_t* tree;
	node_t* nodeArr[TEST_NUM];
	if (!testData)
	{
		return -1;
	}

	tree = makeTree();
	for (int i = 0; testData[i] && i < TEST_NUM; i++)
	{
		nodeArr[i] = makeNode();
		nodeArr[i]->data = testData[i];
		bstInsertNode(tree, nodeArr[i]);
	}
	printf("Before Transplant");
	testBSTWithInorder(tree);
	printf("After Transplant");
	transplantInBST(tree, searchBSTbyKey(tree, delNum), searchBSTbyKey(tree, transNum));
	testBSTWithInorder(tree);

	clearTreeWithNode(tree->root);
	return 0;
}


//void  bstTransplant(tree_t * tree, node_t * rmNode, node_t * mvNode) �Լ� ����

int transplantInBST(tree_t* tree, node_t* deNode, node_t* newNode)
{
	if (!tree || !deNode )
	{
		return -1;
	}

	if (!deNode->parent)
	{
		tree->root = newNode;
	}
	else if (deNode->parent->leftChild == deNode)
	{
		deNode->parent->leftChild = newNode;
	}
	else
	{
		deNode->parent->rightChild = newNode;
	}

	if (newNode)
	{
		newNode->parent = deNode->parent;
	}

	return 0;
}