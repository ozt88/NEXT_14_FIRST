#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "member_management.h"

//노드 삽입
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


//노드 삭제
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

//이전 노드 찾기 - prev를 썼다면 좀더 간결했을 것...
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

//가장 마지막에 있는 노드 찾기 - tail을 썻다면 좀더 간결했을 것.
//처음 자료구조를 잘 잡아야 하는 이유!
//노드를 여러개 쓰는 자료형이라면 
//tail과 prev를 써주는 것이 현명할 것이다.
node_t* findMaxInListWithNode(list_t* list)
{
	node_t* dstNode = list->head;
	while (dstNode->next)
	{
		dstNode = dstNode->next;
	}
	return dstNode;
}

//리스트를 free하는 함수
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

//리스트를 만드는 함수. 
//별로 의미없이 센티널을 넣었다.
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