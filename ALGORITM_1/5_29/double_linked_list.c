
//DOUBLE CIRCULAR LINKED LIST를 만들고 그것으로 다양한 기능을 수행한다.
//1.리스트 생성 테스트 함수
//저장한 data, 이전 노드의 주소, 이전 노드에 저장된 data, 
//다음 노드의 주소, 다음 노드에 저장된 data 출력
//2.리스트의 모든 노드의 data를 printf로 출력하는 함수 구현
//3.주어진 key를 갖는 노드 찾는 함수 구현
//4.주어진 노드 다음에 새 노드 추가하는 함수 구현
//5.노드 삭제하는 함수 구현


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NUM_OF_NODE 4 

typedef struct dNode
{
	int value;
	struct dNode* next;
	struct dNode* prev;
}dNode_t;

typedef struct dList
{
	dNode_t* head;
}dList_t;


dList_t* make_double_linked_list(void);
dNode_t* make_double_node(int data);
int insert_head_node(dList_t* list, dNode_t* node);
int print_current_prev_next(dList_t* list);
int print_list(dList_t* dList);
dNode_t* search_node(dList_t* list, int key);
int insert_node(dNode_t* prevNode, dNode_t* newNode);
int delete_node(dList_t* list, dNode_t* deleteNode);
int clearList(dList_t* list);


int main(void)
{
	dList_t* dList = make_double_linked_list();
	dNode_t* dNodeArr[4] = { 0, };

	for (int i = 0; i < NUM_OF_NODE; i++)
	{
		dNodeArr[i] = make_double_node((i + 1)*(i + 1));
		insert_head_node(dList, dNodeArr[i]);
	}

	printf("생성 리스트 테스트\n");
	print_current_prev_next(dList);

	printf("리스트 출력\n");
	print_list(dList);

	printf("키값으로 노드를 검색\n");
	if (search_node(dList, 1))
	{
		printf("%d is found!\n", search_node(dList, 1)->value);
	}
	else
	{
		printf("Key is not found!\n");
	}

	if (search_node(dList, 20))
	{
		printf("%d is found!\n", search_node(dList, 20)->value);
	}
	else
	{
		printf("Key is not found!\n");
	}

	printf("새로운 노드(45)를 기존 노드(16) 뒤에 삽입\n");
	insert_node(search_node(dList, 16), make_double_node(45));
	print_list(dList);

	printf("기존의 노드(16)를 삭제\n");
	delete_node(dList, search_node(dList, 16));
	print_list(dList);

	clearList(dList);

	return 0;
}


//1-1.더블 링크드 리스트(순환) 만드는 함수
//뉴리스트를 포인터로 선언하고 멀록으로 할당한다.
//뉴헤드(센티널)를 포인터로 선언하고 멀록으로 할당한다.
//뉴 헤드를 초기화하고 뉴 리스트의 헤드로 설정한다.

dList_t* make_double_linked_list(void)
{
	dList_t* newDList = (dList_t*)malloc(sizeof(dList_t));
	dNode_t* newHead = (dNode_t*)malloc(sizeof(dNode_t));
	
	newHead->value = 0;
	newHead->next = newHead;
	newHead->prev = newHead;
	newDList->head = newHead;

	return newDList;
}

//1-2.더블 링크드 노드를 생성한다.
//노드 포인터를 선언하고 멀록으로 할당.
//넥스트와 프리브를 널로 초기화 시켜주고 데이터를 값으로 넣는다.
dNode_t* make_double_node(int data)
{
	dNode_t* newDNode = (dNode_t*)malloc(sizeof(dNode_t));
	newDNode->next = (dNode_t*)NULL;
	newDNode->prev = (dNode_t*)NULL;
	newDNode->value = data;

	return newDNode;
}

//1-3.노드를 리스트의 헤드 뒤에 삽입하는 함수.(리스트를 초기 설정하는데 쓰인다.)
//i)원래 헤드 뒤에 있던 노드(사실상 맨 앞노드)를 넣을 노드의 뒤에 놓는다.(next & prev)
//ii)헤드의 뒤에 노드를 놓는다.(next & prev)

int insert_head_node(dList_t* list , dNode_t* node)
{
	if (!list || !node)
	{
		return -1;
	}
	node->next = list->head->next;
	list->head->next->prev = node;
	list->head->next = node;
	node->prev = list->head;

	return 0;
}

//1-4.리스트의 처음부터 끝까지 돌면서 현재값, 다음 주소, 다음 값, 이전 주소, 이전 값
//출력하는 함수
//i)현재노드라는 노드 포인터를 선언하고 헤드의 다음 노드로 초기화.
//ii)넥스트 노드로 하나씩 넘어가면서 필요한 정보를 출력하고 헤드로 돌아오면 종료.

//???의문점: 순환 링크드 리스트이므로 넥스트나 프리브가 NULL일 수 없다!
//???그런데 문제에는 next나 prev가 NULL인 경우에 다른 방식으로 출력하길 원하는 데,
//???이것은 넥스트나 프리브가 의미없는 센티널인 head를 가르킬 때 이렇게 출력하라는 것인가?
//???일단 위의 가설에 맞춰서 코드를 작성하였다.

int print_current_prev_next(dList_t* list)
{
	dNode_t* currentNode;

	if (!list)
	{
		return -1;
	}

	currentNode = list->head->next;

	while (currentNode != list->head)
	{
		printf("%-4d\t", currentNode->value);
		if (currentNode->prev != list->head)
		{
			printf("%-10p\t", currentNode->prev);
			printf("%-4d\t", currentNode->prev->value);
		}
		else
		{
			printf("%-10s\t", "NULL");
			printf("%-4s\t", "없음");
		}
		
		if (currentNode->next != list->head)
		{
			printf("%-10p\t", currentNode->next);
			printf("%-4d\t", currentNode->next->value);
		}
		else
		{
			printf("%-10s\t", "NULL");
			printf("%-4s\t", "없음");
		}
		printf("\n");
		currentNode = currentNode->next;
	}

	return 0;
}

//2.리스트에 있는 data들을 하나씩 출력하는 함수
//i)현재 노드라는 노드 포인터를 선언하고 리스트의 헤드의 다음노드로 초기화.
//ii)넥스트를 따라 하나씩 출력하고 헤드로 돌아왔을때 종료

int print_list(dList_t* dList)
{
	dNode_t* currentNode;
	if (!dList)
	{
		return -1;
	}
	currentNode = dList->head->next;
	while (currentNode != dList->head)
	{
		printf("%3d", currentNode->value);
		currentNode = currentNode->next;
	}
	printf("\n");
	return 0;
}

//3.key값을 가지고 있는 노드를 찾는 함수
//i)현재 노드라는 노드 포인터를 선언한뒤 헤드의 뒤에 있는 노드로 초기화
//ii)현재 노드가 하나 씩 그 다음 노드로 옮겨가면서 key값과 같은지 체크
//iii)현재 노드의 값이 키 값과 같으면 반복문에서 나와서 현재 노드의 주소를 리턴
//iv)현재 노드를 헤드 노드까지 한바퀴 돌았으면 전체에 그런 key값이 없다는 의미이므로 NULL을 리턴

dNode_t* search_node(dList_t* list, int key)
{
	dNode_t* currentNode;

	if (!list || !key)
	{
		return (dNode_t*)NULL;
	}

	currentNode = list->head->next;

	while (currentNode != list->head)
	{
		if (currentNode->value == key)
		{
			break;
		}
		currentNode = currentNode->next;
	}

	if (currentNode == list->head)
	{
		return (dNode_t*)NULL;
	}
	return currentNode;
}

//4.새로운 노드를 어떤 노드 뒤에 삽입하는 함수.
//센티널이 있으므로 헤드를 바꿔줄 필요가 없기 때문에 list를 인자로 받을 필요가 없다.
//또한 같은 이유에서 NULL이 prevNode가 될 수 없다. 맨 앞에 넣고 싶으면 prev자리에 헤드를 넣어야한다.
//i)새로운 노드를 원래 이전 노드의 뒤에있던 노드 앞에 넣는다.(next & prev)
//ii)그리고 이전 노드의 뒤에다가 새로운 노드를 집어넣는다. (next & prev)
//위 순서가 달라지면 원래 이전 노드의 뒤에 있던 노드를 알 수 없으므로 제대로 끼워 넣을 수 없다. 주의.

int insert_node(dNode_t* prevNode, dNode_t* newNode)
{
	if (!prevNode || !newNode)
	{
		return -1;
	}
	newNode->next = prevNode->next;
	prevNode->next->prev = newNode;
	prevNode->next = newNode;
	newNode->prev = prevNode;
	
	return 0;
}

//5.기존의 노드를 리스트에서 삭제하는 함수
//센티널이 있으므로 node->next 혹은 node->prev가 NULL인 경우를 고려할 필요없다.
//삭제할 노드 앞뒤의 노드를 연결해주고 그 노드를 프리하기만 하면 삭제 완료.
int delete_node(dList_t* list, dNode_t* deleteNode)
{
	if (!list || !deleteNode)
	{
		return -1;
	}
	deleteNode->next->prev = deleteNode->prev;
	deleteNode->prev->next = deleteNode->next;
	free(deleteNode);
	return 0;
}

//리스트를 프리하는 함수.

int clearList(dList_t* list)
{
	dNode_t* currentNode = (dNode_t*)NULL;
	dNode_t* nextNode = (dNode_t*)NULL;

	if (!list)
	{
		return -1;
	}
	currentNode = list->head->next;
	while (currentNode != list->head)
	{
		nextNode = currentNode->next;
		free(currentNode);
		currentNode = nextNode;
	}
	free(list->head);
	free(list);

	return 0;
}
