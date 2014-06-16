#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"


//�ǽ� ���� 13

//�Ʒ��� �Լ��� 3��ó�� ����Ͽ� �׽�Ʈ�ϴ� �Լ�

int testSuccessor(node_t* node)
{
	node_t* resultNode;
	if (!node)
	{
		return -1;
	}
	resultNode = bstSuccessorOf(node);
	printf("%d's successor\n", node->data);
	testBSTlikeNo3(resultNode);

	return 0;
}

//node_t * bstSuccessorOf(node_t * node) �Լ� ����
//Node�� successor node�� ���

node_t* bstSuccessorOf(node_t* node)
{
	node_t* parent;
	if (!node)
	{
		return (node_t*)NULL;
	}
	parent = node->parent;

	if (node->rightChild)
	{
		return findMinInBSTWithNode(node->rightChild);
	}

	while (parent) 
	{
		if (parent->leftChild == node)
		{
			break;
		}
		node = parent;
		parent = node->parent;
	}

	return parent;
}