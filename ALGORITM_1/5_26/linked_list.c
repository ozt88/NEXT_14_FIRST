//linked list
//순서리스트(배열)에 삽입 삭제시에 O(n)이 들어간다. 공간도 추가해야된다.
//물리적인 구조와 논리적인 구조를 일치시킬 필요없다.
//뒤에 뭐가 오는지만 알면되니까!

//<head Value, nextPtr> -> <next Value, nextnext Ptr> ->.....

//insert
//노드 하나 만들고 원하는 값 넣고 링크를 들어갈 장소 다음거넣고
//이전거에 포인터를 새로운 넘을 가르치도록 함

//delete
//삭제할 노드 이전것을 찾는다. 걔가 다음가르치는 포인터를 다다음걸로 바꿔준다.
//삭제할 노드 프리

//구린점 
//아무것도 모르는 상태에서 원하는 구역을 찾을라면 처음부터 돌아야된다. 
//그래도 이전값이 무엇인지 알고 관리할 수 있다면 아주 편하게 사용할 수 있다.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"


int main(void){
	list_t list;
	node_t* node1 = (node_t*)malloc(sizeof(node_t));
	node_t* node2 = (node_t*)malloc(sizeof(node_t));
	node_t* node3 = (node_t*)malloc(sizeof(node_t));
	node_t* node4 = (node_t*)malloc(sizeof(node_t));
	node_t* node5 = (node_t*)malloc(sizeof(node_t));
	node_t* node6 = (node_t*)malloc(sizeof(node_t));
	node_t* currentPtr;
	int input;

	while (1)
	{
		list.head = node1;
		node1->value = 10;
		node1->next = node2;
		node2->value = 20;
		node2->next = node3;
		node3->value = 30;
		node3->next = node4;
		node4->value = 40;
		node4->next = node5;
		node5->value = 50;
		node5->next = node6;
		node6->value = 100;
		node6->next = (node_t *)NULL;

		system("cls");
		printf("linked list practice\n\n");
		printf(" practice 2 - input 1\n practice 3~4 - input 2\n practice 5 - input 3\n pracice 6~7 - input 4\n practice 8~9 - input 5\n");
		printf(" Quit - input 0\n");
		printf("\ninput number :");
		fflush(stdin);
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			practice2(list);
			break;
		case 2:
			practice34(&list, node1, node2, node3, node4, node5, node6);
			break;
		case 3:
			practice5(list);
			break;
		case 4:
			practice67(list);
			break;
		case 5:
			practice89(list);
			break;
		case 0:
			if (node1) free(node1);
			if (node2) free(node2);
			if (node3) free(node3);
			if (node4) free(node4);
			if (node5) free(node5);
			if (node6) free(node6);
			return 0;
		default:
			break;
		}
	}
}


void printAllNodes(list_t * list)
{
	node_t* ptr = list->head;
	while (ptr != (node_t*)NULL)
	{
		printf("%d  ", ptr->value);
		ptr = ptr->next;
	}
	printf("\n");
	return;
}

void insertNode(list_t* listPtr, node_t* prevNodePtr, node_t* newNodePtr)
{
	if (listPtr == (list_t*)NULL || newNodePtr == (node_t*)NULL)
	{
		printf("NO DATA ERROR!\n");
		return -1;
	}

	if (prevNodePtr)
	{
		newNodePtr->next = prevNodePtr->next;
		prevNodePtr->next = newNodePtr;
	}
	else
	{
		newNodePtr->next = listPtr->head;
		listPtr->head = newNodePtr;
	}
}

node_t* searchNode(list_t *list, int key)
{
	node_t* ptr = list->head;

	while (ptr != (node_t*)NULL)
	{
		if (ptr->value == key) return ptr;
		else ptr = ptr->next;
	}

	return (node_t*)NULL;
}

void deleteNode(list_t *list, node_t *prevN, node_t *targetN)
{
	node_t* ptr = list->head;

	if (list == NULL || targetN == NULL)
	{
		printf("Delete Error\n");
		return;
	}

	if (prevN == NULL)
	{
		list->head = targetN->next;
		//free(targetN);
		//프리하면 반복문에서 오류날 수 있어서 종료할때만 프리하게 했습니다.
	}

	else
	{
		prevN->next = targetN->next;
		//free(targetN);
	}
	return;
}

node_t* findPrevNode(list_t* list, node_t* currentNode)
{
	node_t* ptr = list->head;
	while (ptr)
	{
		if (ptr->next == currentNode) return ptr;
		else ptr = ptr->next;
	}

	printf("not found!\n");
	return NULL;
}

node_t* findCycleHead(list_t* list, node_t* one, node_t* two)
{
	int cycleCount = 0;

	do{
		one = one->next;
		cycleCount++;
	} while (one != two);

	//순환고리의 길이를 잽니다. 

	one = list->head;
	two = list->head;

	//전체길이는 순환고리길이(q) + 아닌길이(p)
	//one을 q만큼 보내면 cycle head까지는 p가 남아요
	//list head에 있는 two도 cycle head 까지는 p만큼 남아요
	//왜냐면 head에서 cycle head까지의 길이는 전체에서 순환고리의 길이를 제외한 p이기 때문입니다.

	while (cycleCount)
	{
		one = one->next;
		cycleCount--;
	}

	//이제 둘이 만날때까지 앞으로 가라고 하면 됩니다. 

	while (one != two)
	{
		one = one->next;
		two = two->next;
	}

	return one;
}


node_t* cycleFinder(list_t* list)
{
	node_t* one;
	node_t* two;

	one = list->head;
	two = list->head;

	while (two != NULL)
	{
		two = two->next;

		if (one == two) return findCycleHead(list, one, two);
		else if (one != two && two != NULL)
		{
			two = two->next;
			one = one->next;
			if (one == two) return findCycleHead(list, one, two);
		}
	}
	return NULL;
}


void practice2(list_t list)
{
	node_t* currentPtr = list.head;

	printf("\n저장한 data, 다음 노드의 주소, 다음 노드에 저장된 data 출력\n\n");

	while (currentPtr)
	{
		printf("%d, ", currentPtr->value);
		currentPtr = currentPtr->next;
		printf("%p, ", currentPtr);
		if (currentPtr != (node_t *)NULL) printf("%d\n", currentPtr->value);
		else printf("없음\n");
	}
	fflush(stdin);
	getchar();
	return;
}

void practice34(list_t* list, node_t* node1, node_t* node2, node_t* node3, node_t* node4, node_t* node5, node_t* node6)
{

	printf("\n모든 노드의 data를 printf로 출력하는 함수구현\nList의 맨 앞에 node 추가하는 함수 구현\n\n");

	list->head = (node_t*)NULL;
	node1->next = (node_t*)NULL;
	node2->next = (node_t*)NULL;
	node3->next = (node_t*)NULL;
	node4->next = (node_t*)NULL;
	node5->next = (node_t*)NULL;
	node6->next = (node_t*)NULL;


	printAllNodes(list);
	insertNode(list, (node_t*)NULL, node1);
	printAllNodes(list);
	insertNode(list, (node_t*)NULL, node2);
	printAllNodes(list);
	insertNode(list, (node_t*)NULL, node3);
	printAllNodes(list);
	insertNode(list, (node_t*)NULL, node4);
	printAllNodes(list);
	insertNode(list, (node_t*)NULL, node5);
	printAllNodes(list);
	insertNode(list, (node_t*)NULL, node6);
	printAllNodes(list);

	fflush(stdin);
	getchar();

	return;
}

void practice5(list_t list)
{
	node_t* currentPtr;

	printf("\n주어진 key를 갖는 노드 찾는 함수 구현 70 & 100\n\n");

	printf("전체 리스트: ");
	printAllNodes(&list);
	currentPtr = searchNode(&list, 70);
	currentPtr ? printf("%d is found\n", currentPtr->value) : printf("Key is Not Found!\n");
	currentPtr = searchNode(&list, 100);
	currentPtr ? printf("%d is found!\n", currentPtr->value) : printf("Key is Not Found!\n");

	fflush(stdin);
	getchar();
	return;
}

void practice67(list_t list)
{
	node_t* newNode1 = (node_t*)malloc(sizeof(node_t));
	node_t* newNode2 = (node_t*)malloc(sizeof(node_t));
	node_t* currentPtr;

	printf("\n주어진 노드(40) 다음에 새 노드(45) 추가하는 함수 구현\n맨앞(NULL뒤)에 새 노드(5) 추가하는 함수 구현\n\n");


	newNode1->value = 45;
	newNode2->value = 5;
	printf("전체 리스트\n");
	printAllNodes(&list);
	currentPtr = searchNode(&list, 40);
	insertNode(&list, currentPtr, newNode1);
	printf("40뒤에 45추가\n");
	printAllNodes(&list);
	insertNode(&list, NULL, newNode2);
	printf("맨 앞에 5 추가\n");
	printAllNodes(&list);

	fflush(stdin);
	getchar();

	return;
}

void practice89(list_t list)
{

	node_t* nodePtr;

	printf("\n값이 40인 노드 삭제하는 함수\n헤드가 없을때까지 계속 헤드를 삭제하는 함수\n\n");
	printf("전체 리스트\n");
	printAllNodes(&list);
	nodePtr = searchNode(&list, 40);
	deleteNode(&list, findPrevNode(&list, nodePtr), nodePtr);
	printf("값이 40인 노드 삭제\n");
	printAllNodes(&list);
	printf("헤드가 없어질때까지 헤드를 삭제\n");
	while (list.head)
	{
		deleteNode(&list, (node_t*)NULL, list.head);
		printAllNodes(&list);
	}

	fflush(stdin);
	getchar();

	return;
}