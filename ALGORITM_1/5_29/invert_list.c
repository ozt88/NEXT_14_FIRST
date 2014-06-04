#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�Ϲ����� ���� ����Ʈ�� �ι�Ʈ ����
//�⺻ ���̵�� : ������ ����Ʈ�� HEAD���� �ϳ��� ���ο� ����Ʈ�� ��忡 ���� �ִ°�. �׸��� ���ο� ����Ʈ�� ����!
//�ٽ� �Լ� invert_linked_list �� �����ϰ� ���� ���� �ι�Ʈ���� �����Ա� ������ ���� �ּ��� ���� �ʾҽ��ϴ�.

#define NUM_OF_NODE 6

typedef struct Node
{
	int value;
	struct Node* next;
}node_t;

typedef struct List
{
	node_t* head;
}list_t;

list_t* invert_linked_list(list_t* normal_list);
list_t* makeList(void);
node_t* makeNode(int data);
int printList(node_t* node);
int clearList(list_t* list);

int main(void)
{
	list_t* list = makeList();
	node_t* nodeArr[NUM_OF_NODE];

	for (int i = 0; i < 6; i++)
	{
		nodeArr[i] = makeNode(10 * (i + 1));
		if (i)
		{
			nodeArr[i - 1]->next = nodeArr[i];
		}
		else
		{
			list->head = nodeArr[i];
		}
	}
	printf("NORMAL LIST\n");
	printList(list->head);
	printf("INVERT LIST\n");
	printList(invert_linked_list(list)->head);
	clearList(list);

	return 0;
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

//����Ʈ�� �޾Ƽ� �� ������ ����Ʈ�� �����ϴ� �Լ� 
//���ο� ����Ʈ�� ����� �Է¹��� ����Ʈ�� ��忡������ �ϳ���
//���ο� ����Ʈ�� �� ��(���)�� ����ִ� ������� ���� ������ ����.

list_t* invert_linked_list(list_t* normal_list)
{
	list_t* invert_list = makeList();
	node_t* currentNode = normal_list->head;
	node_t* nextNode;

	if (!normal_list)
	{
		return (list_t*)NULL;
	}
	while (currentNode)
	{
		nextNode = currentNode->next;
		currentNode->next = invert_list->head;
		invert_list->head = currentNode;
		currentNode = nextNode;
	}

	return invert_list;
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
	free(list);

 	return 0;
}
