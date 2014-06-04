//CONCATENATE 함수 - 두 리스트를 하나로 연결해서 연결된 리스트를 리턴하는 함수
//기본 아이디어 : 먼저 오는 리스트의 마지막 노드를 찾아서, 다음 오는 리스트의 헤드를 연결한다. 
//마지막 노드의 넥스트가 다음 리스트의 헤드가 되게 한다. 그리고 먼저왔던 리스트를 리턴하면 연결된 리스트가 나온다.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NUM_OF_NODE 6

typedef struct Node
{
	int value;
	struct Node* next;
}node_t;

typedef struct stackList
{
	node_t* head;
}list_t;

list_t* concatenate(list_t* list1, list_t* list2);
list_t* makeList(void);
node_t* makeNode(int data);
int printList(node_t* node);

int main(void)
{
	list_t* list1 = makeList();
	list_t* list2 = makeList();
	node_t* nodeArr1[NUM_OF_NODE] = { 0, }; 
	node_t* nodeArr2[NUM_OF_NODE] = { 0, };

	for (int i = 0; i < NUM_OF_NODE; i++)
	{
		nodeArr1[i] = makeNode(10 * (i + 1));
		nodeArr2[i] = makeNode(100 + (10 * (i + 1)));
		if (i)
		{
			nodeArr1[i - 1]->next = nodeArr1[i];
			nodeArr2[i - 1]->next = nodeArr2[i];
		}
		else
		{
			list1->head = nodeArr1[i];
			list2->head = nodeArr2[i];
		}
	}

	printf("LIST1\n");
	printList(list1->head);
	printf("LIST2\n");
	printList(list2->head);
	printf("CONCATENATE\n");
	printList(concatenate(list1, list2)->head);

	clearList(list1);
	clearList(list2);

	return 0;
}

list_t* concatenate(list_t* list1, list_t* list2)
{
	if (!list1 || !list2)
	{
		return (node_t*)NULL;
	}
	node_t* currentNode = list1->head;
	while (currentNode->next)
	{
		currentNode = currentNode->next;
	}
	currentNode->next = list2->head;
	list2->head = (node_t*)NULL;

	return list1;
}


list_t* makeList(void)
{
	list_t* newList = (list_t*)malloc(sizeof(list_t));
	memset(newList, 0, sizeof(list_t));

	newList->head = (node_t*)NULL;
	return newList;
}

node_t* makeNode(int data)
{
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	memset(newNode, 0, sizeof(node_t));
	newNode->value = data;
	return newNode;
}

int printList(node_t* node)
{
	node_t* currentNode = node;

	if (!node)
	{
		return -1;
	}

	while (currentNode)
	{
		printf("%-4d", currentNode->value);
		currentNode = currentNode->next;
	}
	printf("\n");

	return 0;
}


int clearList(list_t* list)
{
	node_t* currentNode = (node_t*)NULL;
	node_t* nextNode = (node_t*)NULL;

	if (!list)
	{
		return -1;
	}
	currentNode = list->head;
	while (currentNode)
	{
		nextNode = currentNode->next;
		free(currentNode);
		currentNode = nextNode;
	}
	if(list) free(list);

	return 0;
}
