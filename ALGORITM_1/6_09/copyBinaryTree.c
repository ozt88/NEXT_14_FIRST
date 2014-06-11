#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"binaryTree.h"

//�ǽ� ���� 7 TEST

int copyTreeTest(tree_t* srcTree)
{
	tree_t* dstTree;
	if (!srcTree)
	{
		return -1;
	}
	//ī�Ǻ��� ���� ����
	printf("Original Tree\n");
	testTreeWithInorder(srcTree);
	printf("Copyied Tree\n");
	dstTree = copyBinaryTree(srcTree);
	testTreeWithInorder(srcTree);

	return 0;
}

//Ʈ���� ���ڷ� �޾Ƽ� �� Ʈ���� ������ Ʈ���� �����ϴ� �Լ�
//�Ȱ��� ���� ���ο� Ʈ���� �����Ѵ�.

tree_t* copyBinaryTree(tree_t* srcTree)
{
	tree_t* copyBinaryTree;
	if (!srcTree)
	{
		return -1;
	}
	copyBinaryTree = makeTree();
	copyBinaryTree->root = copyBinaryTreeWithNode(srcTree->root, NULL);

	return copyBinaryTree;
}

node_t* copyBinaryTreeWithNode(node_t* srcNode, node_t* parent)
{
	node_t* dstNode;

	if (!srcNode)
	{
		return (node_t*)NULL;
	}

	dstNode = (node_t*)malloc(sizeof(node_t));

	dstNode->data = srcNode->data;
	dstNode->parent = parent;
	dstNode->leftChild = copyBinaryTreeWithNode(srcNode->leftChild, dstNode);
	dstNode->rightChild = copyBinaryTreeWithNode(srcNode->rightChild, dstNode);

	return dstNode;
}