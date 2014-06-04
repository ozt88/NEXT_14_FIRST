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

//리스트의 길이(노드 갯수)를 구하는 함수
//i)현재 노드라는 노드 포인터를 선언하고 리스트의 헤드로 선언한다.
//ii)넥스트를 통해 한개씩 넘어가면서 count를 증가시킨다.
//iii)계속 넘어가다가 현재 노드가 NULL이 되면 중단하고 count를 리턴한다.

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


//여기서부터 TEST용 코드
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