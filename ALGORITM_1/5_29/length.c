#include<stdio.h>

typedef struct node
{
	int value;
	struct node* next;
}node_t;

typedef struct list
{
	node_t* head;
}list_t;

//����Ʈ�� ����(��� ����)�� ���ϴ� �Լ�
//i)���� ����� ��� �����͸� �����ϰ� ����Ʈ�� ���� �����Ѵ�.
//ii)�ؽ�Ʈ�� ���� �Ѱ��� �Ѿ�鼭 count�� ������Ų��.
//iii)��� �Ѿ�ٰ� ���� ��尡 NULL�� �Ǹ� �ߴ��ϰ� count�� �����Ѵ�.

int list_length_count(list_t* list)
{
	int count = 0;
	node_t* currentNode;

	if (!list)
	{
		return -1;
	}
	currentNode = list->head;
	while (currentNode)
	{
		currentNode = currentNode->next;
		count++;
	}

	return count;
}


//���⼭���� TEST�� �ڵ�
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


int main(void)
{
	list_t* list = makeList();
	node_t* nodeArr[10] = { 0, };

	for (int i = 0; i < 10; i++)
	{
		nodeArr[i] = makeNode(i + 1);
		if (i)
		{
			nodeArr[i - 1]->next = nodeArr[i];
		}
		else
		{
			list->head = nodeArr[i];
		}
	}

	printf("%d\n",list_length_count(list));
	return 