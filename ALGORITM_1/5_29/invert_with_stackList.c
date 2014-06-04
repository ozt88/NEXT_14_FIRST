//STACK LINKED LIST를 활용한 INVERT방법입니다.
//스택을 다른 스택으로 옮겨 담았을때 역순이 되는 것을 응용했습니다.


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
	node_t* top;
}stackList_t;

stackList_t* invert_linked_stackList(stackList_t* normal_stackList);
node_t* makeNode(int data);
int printStackList(node_t* node);
stackList_t* makeStackList(void);
int pushStackList(stackList_t* stackList, node_t* newNode);
node_t* popStackList(stackList_t* stackList);
int clearList(stackList_t* list);

int main(void)
{
	stackList_t* normal_stackList = makeStackList();
	stackList_t* invert_stackList;
	node_t* nodeArr[NUM_OF_NODE];

	//노드를 하나하나 생성하는 번거로움을 극복하기 위해서 노드들의 포인터 배열을 선언하고
	//반복문을 돌리면서 makeNode라는 함수로 노드들을 생성했습니다.
	//생성한후에 바로 연결 스택에 푸시했습니다.
	for (int i = 0; i < NUM_OF_NODE ; i++)
	{
		nodeArr[i] = makeNode(60 - (10*i));
		pushStackList(normal_stackList, nodeArr[i]);
	}

	printf("NORMAL LIST\n");
	printStackList(normal_stackList->top);
	printf("INVERT LIST\n");
	invert_stackList = invert_linked_stackList(normal_stackList);
	printStackList(invert_stackList->top);

	clearList(normal_stackList);
	clearList(invert_stackList);

	return 0;
}


//연결 스택을 생성하는 함수
//멀록으로 리스트 포인터를 할당하고 초기화합니다. 
//엠티상태의 탑은 0으로 설정했습니다.

stackList_t* makeStackList(void)
{
	stackList_t* newstackList = (stackList_t*)malloc(sizeof(stackList_t));
	memset(newstackList, 0, sizeof(stackList_t));
	
	newstackList->top = (node_t*)NULL;
	return newstackList;
}

//노드를 생성하는 함수
//멀록으로 노드 포인터를 할당하고 초기화 한뒤에 원하는 값을 입력했습니다.

node_t* makeNode(int data)
{
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	memset(newNode, 0, sizeof(node_t));
	newNode->value = data;
	return newNode;
}

//연결 리스트를 출력하는 함수
//커런트노드라는 노드 포인터를 활용 top(혹은 head)에서부터 하나씩 넥스트로 넘어가면서 출력합니다.

int printStackList(node_t* node)
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

}


//연결 스택에 푸시하는 함수
//스택이 비어있을때와 비어있지 않을때로 나누어 진행됩니다.
//비어있으면 새로운 노드를 탑에 놓기만 하고
//비어있지 않으면 기존의 탑의 넥스트를 새로운 노드로 지정한뒤 새로운 노드를 탑으로 설정합니다.


int pushStackList(stackList_t* stackList, node_t* newNode)
{
	if (!stackList || !newNode)
	{
		return -1;
	}
	if (stackList->top)
	{
		newNode->next = stackList->top;
	}
	stackList->top = newNode;

	return 0;
}


//연결스택의 팝 함수
//먼저 입력이 제대로 이루어지지 않은 경우와 엠티인 경우를 한꺼번에 처리했습니다.
//우선 팝 노드라는 노드 포인터를 활용 임시 저장하는 장소를 만들어 현재 탑 노드를 저장하고
//연결 스택의 탑을 현재 탑의 넥스트로 설정합니다.
//그리고 팝 노드에 저장된 이전 탑 노드의 연결을 끊어준뒤에 리턴합니다.

node_t* popStackList(stackList_t* stackList)
{
	node_t* popNode;
	
	if (!stackList||!stackList->top)
	{
		return (node_t*)NULL;
	}

	popNode = stackList->top;
	stackList->top = stackList->top->next;
	popNode->next = (node_t*)NULL;

	return popNode;
}

//역순인 연결스택을 만드는 함수
//새로운 스택리스트를 만들고 입력된 기존의 연결스택을 팝하면서 튀어나온 노드를 새로운 연결 스택에 푸시합니다.
//입력된 기존의 연결스택이 엠티가 되면 반복문을 종료하고 새로운 스택 리스트를 리턴합니다.

stackList_t* invert_linked_stackList(stackList_t* normal_stackList)
{
	stackList_t* invert_stackList = makeStackList();

	if (!normal_stackList)
	{
		return (stackList_t*)NULL;
	}

	while (normal_stackList->top)
	{
		pushStackList(invert_stackList, popStackList(normal_stackList));
	}

	return invert_stackList;
}

//리스트를 프리하는 함수
//리스트에 포함된 모든 노드들을 헤드에서부터 하나씩 넘어가면서 프리하고
//마지막에 리스트까지 프리한뒤 종료.

int clearList(stackList_t* list)
{
	node_t* currentNode;
	node_t* nextNode;
	if (!list)
	{
		return -1;
	}

	currentNode = list->top;
	while (currentNode)
	{
		nextNode = currentNode->next;
		free(currentNode);
		currentNode = nextNode;
	}

	free(list);
	return 0;
}