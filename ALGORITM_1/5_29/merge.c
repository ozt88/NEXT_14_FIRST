//오름차순으로 정렬된 두 리스트를 받아서 두 리스트가 정렬된 상태로 합쳐진 리스트를 리턴하는 함수를 만들자.
//기본 아이디어: 내적을 구하는 함수와 유사한 형태로 구현하자.

//1.리스트 두 개를 체크하는 두 개의 노드 포인터를 둔다.
//2.두 리스트의 노드의 값을 노드 포인터를 통해서 순차적으로 비교한다.
//3.연산 횟수를 줄이기 위해서, 비교된 결과에 따라서 노드 포인터의 움직임을 결정하게 한다.
	//3-1.두 리스트를 순차적으로 비교하는 구체적인 방법
		//i)두 노드의 값이 같은 경우 두 노드 포인터가 가르치는 노드를 머지 리스트에 삽입하고, 두 노드 포인터를 모두 한 단계 뒤로 보낸다.
		//ii)두 노드의 값이 다른 경우 두 노드 포인터중에 작은 것을 머지 리스트에 삽입하고, 값이 작은 쪽의 노드 포인터를 한단계 뒤로 보낸다.
		//위와 같은 작업을 반복하면 각 리스트가 이미 오름차순으로 정렬되어 있기 때문에, 모든 리스트의 값들을 비교할 수 있게 된다.
		//한 리스트에서 이미 처리한 앞 노드의 값은 뒤 노드의 값보다 반드시 작다는 전제가 있기 때문이다.
//4.경계 조건을 조심스럽게 다룬다.
	//4-1.노드 포인터가 전체 리스트를 체크하고 결국 NULL이 된 경우
		//i)두 노드 포인터가 전체 리스트를 모두 체크했다면 연산을 종료하고 머지된 리스트를 리턴한다.
		//ii)한개의 노드 포인터만 NULL이 되었다면 나머지 노드 포인터만 머지 리스트에 삽입하고 한단계 뒤로 보낸다.
//5.새로운 리스트에 노드를 삽입하는 방법
	//i)오름차순으로 정렬해야하는데 우리는 작은 수부터 순차적으로 찾고 삽입한다.
	//ii)새로운 노드가 삽입되면 그 노드는 맨 뒤에 삽입 되어야 한다.
	//iii)마지막 노드를 노드 포인터를 통해 기억하고 그 장소에 새로운 노드를 삽입한다.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NUM_OF_NODE 5

typedef struct node
{
	int value;
	struct node* next;
}node_t;

typedef struct list
{
	node_t* head;
}list_t;

list_t* makeList(void);
node_t* makeNode(int data);
int printList(node_t* node);
list_t* merge(list_t* list1, list_t* list2);
int insertNode(node_t* preNode, node_t* newNode);


list_t* merge(list_t* list1, list_t* list2)
{
	list_t* newList = makeList();
	node_t* nodePtr1; //list1을 도는 노드 포인터.
	node_t* nodePtr2; //list2를 도는 노드 포인터.
	node_t* nodePtr3; //newList를 도는 노드 포인터.
	node_t* tempPtr; //임시 저장용.

	if (!list1 || !list2)
	{
		return (list_t*)NULL;
	}

	nodePtr1 = list1->head;
	nodePtr2 = list2->head;
	nodePtr3 = newList->head; //노드 포인터들을 헤드로 초기화한다. nodePtr3는 NULL임에 주의. 

	while (nodePtr1 || nodePtr2) 
	{
		if (!nodePtr2)
		{
			tempPtr = nodePtr1->next;
			insertNode(newList, nodePtr3, nodePtr1);
			nodePtr3 = nodePtr1; //새로 삽입된 노드가 마지막 노드이므로 새로운 리스트를 도는 노드 포인터 3은 새로 삽입된 노드포인터의 주소를 받는다.
			nodePtr1 = tempPtr;
		}
		else if (!nodePtr1)
		{
			tempPtr = nodePtr2->next;
			insertNode(newList, nodePtr3, nodePtr2);
			nodePtr3 = nodePtr2;
			nodePtr2 = tempPtr;
		}
		else if (nodePtr1->value < nodePtr2->value)
		{
			tempPtr = nodePtr1->next;
			insertNode(newList, nodePtr3, nodePtr1);
			nodePtr3 = nodePtr1;
			nodePtr1 = tempPtr;
		}

		else if (nodePtr1->value > nodePtr2->value)
		{
			tempPtr = nodePtr2->next;
			insertNode(newList, nodePtr3, nodePtr2);
			nodePtr3 = nodePtr2;
			nodePtr2 = tempPtr;
		}

		else if (nodePtr1->value == nodePtr2->value)
		{
			tempPtr = nodePtr1->next;
			insertNode(newList, nodePtr3, nodePtr1);
			nodePtr3 = nodePtr1;
			nodePtr1 = tempPtr;

			tempPtr = nodePtr2->next;
			insertNode(newList, nodePtr3, nodePtr2);
			nodePtr3 = nodePtr2;
			nodePtr2 = tempPtr;
		}
	}

	return newList;
}


int insertNode(list_t* list, node_t* preNode, node_t* newNode)
{
	if (!list || !newNode)
	{
		return -1;
	}
	if (preNode)
	{
		newNode->next = preNode->next;
		preNode->next = newNode;
	}
	else
	{
		newNode->next = list->head;
		list->head = newNode;
	}
	return 0;
}

list_t* makeList(void)
{
	list_t* newList = (list_t*)malloc(sizeof(list_t));
	
	memset(newList, 0, sizeof(list_t));
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
	list_t* list1 = makeList();
	list_t* list2 = makeList();
	node_t* nodeArr1[NUM_OF_NODE] = { 0, };
	node_t* nodeArr2[NUM_OF_NODE] = { 0, };

	for (int i = 0; i < NUM_OF_NODE; i++)
	{
		nodeArr1[i] = makeNode(2 * (i + 1));
		nodeArr2[i] = makeNode(3 * i + 1);

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
	printf("리스트 1\n");
	printList(list1->head);
	printf("리스트 2\n");
	printList(list2->head);
	printf("머지 리스트\n");
	printList(merge(list1, list2)->head);

	return 0;
}