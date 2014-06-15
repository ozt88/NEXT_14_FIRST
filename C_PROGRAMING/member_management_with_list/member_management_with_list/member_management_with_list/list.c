#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "member_management.h"

//��� ����
int insertNode(node_t* prevNode, node_t* newNode)
{
	if (!prevNode || !newNode)
	{
		return -1;
	}

	newNode->next = prevNode->next;
	prevNode->next = newNode;

	return 0;
}


//��� ����
int deleteNode(list_t* list, node_t* deleteNode)
{
	node_t* prevNode;
	if (!list || !deleteNode)
	{
		return -1;
	}
	prevNode = findPrevNode(list, deleteNode);
	if (prevNode)
	{
		prevNode->next = deleteNode->next;
	}

	free(deleteNode);
	return 0;
}

//���� ��� ã�� - prev�� ��ٸ� ���� �������� ��...
node_t* findPrevNode(list_t* list, node_t* node)
{
	node_t* prevNode;
	if (!list || !node)
	{
		return NULL;
	}
	prevNode = list->head;
	while (prevNode)
	{
		if (prevNode->next == node)
		{
			return prevNode;
		}
		prevNode = prevNode->next;
	}
	return NULL;
}

//���� �������� �ִ� ��� ã�� - tail�� ���ٸ� ���� �������� ��.
//ó�� �ڷᱸ���� �� ��ƾ� �ϴ� ����!
//��带 ������ ���� �ڷ����̶�� 
//tail�� prev�� ���ִ� ���� ������ ���̴�.
node_t* findMaxInListWithNode(list_t* list)
{
	node_t* dstNode = list->head;
	while (dstNode->next)
	{
		dstNode = dstNode->next;
	}
	return dstNode;
}

//����Ʈ�� free�ϴ� �Լ�
int clearList(list_t* list)
{
	node_t* currentNode = (node_t*)NULL;
	node_t* nextNode = (node_t*)NULL;

	if (!list)
	{
		return -1;
	}
	currentNode = list->head->next;
	while (currentNode)
	{
		nextNode = currentNode->next;
		free(currentNode);
		currentNode = nextNode;
	}
	free(list->head);
	free(list);

	return 0;
}

//����Ʈ�� ����� �Լ�. 
//���� �ǹ̾��� ��Ƽ���� �־���.
list_t* makeList(void)
{
	list_t* newList = (list_t*)malloc(sizeof(list_t));
	node_t* newHead = (node_t*)malloc(sizeof(node_t));
	memset(newList, 0, sizeof(list_t));
	memset(newHead, 0, sizeof(node_t));
	newList->head = newHead;
	return newList;
}


node_t* makeNode(void)
{
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	memset(newNode, 0, sizeof(node_t));
	return newNode;
}