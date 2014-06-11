#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"binaryTree.h"

//실습 주제 7 TEST

int copyTreeTest(tree_t* srcTree)
{
	tree_t* dstTree;
	if (!srcTree)
	{
		return -1;
	}
	//카피본과 원본 대조
	printf("Original Tree\n");
	testTreeWithInorder(srcTree);
	printf("Copyied Tree\n");
	dstTree = copyBinaryTree(srcTree);
	testTreeWithInorder(srcTree);

	return 0;
}

//트리를 인자로 받아서 그 트리와 동일한 트리를 복사하는 함수
//똑같이 생긴 새로운 트리를 리턴한다.

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