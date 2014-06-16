#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"



//�ǽ����� 10


//�Ʒ��� �Լ��� �׽�Ʈ
//3��ó�� ���
int testSearchBSTbyKey(tree_t* BST, int key)
{
	node_t* resultNode;

	if (!BST)
	{
		return -1;
	}

	resultNode = searchBSTbyKey(BST, key);
	testBSTlikeNo3(resultNode);

	return 0;
}


//node_t * bstSearch(node_t *node, int key) �Լ� ����
//������ data, parent�� �ּ�, parent�� ����� data, 
//leftChild�� �ּ�, left child�� ����� data, 
//right child�� �ּ�, right child�� ����� data ���

node_t* searchBSTbyKey(tree_t* BST, int key)
{
	if (!BST || !key)
	{
		return (node_t*)NULL;
	}

	return searchBSTbyKeyWithNode(BST->root, key);
}

node_t* searchBSTbyKeyWithNode(node_t* currentNode, int key)
{
	if (!currentNode || !key)
	{
		return (node_t*)NULL;
	}

	if (key == currentNode->data)
	{
		return currentNode;
	}
	else if (key < currentNode->data)
	{
		return searchBSTbyKeyWithNode(currentNode->leftChild, key);
	}
	else
	{
		return searchBSTbyKeyWithNode(currentNode->rightChild, key);
	}
}