//linked list
//��������Ʈ(�迭)�� ���� �����ÿ� O(n)�� ����. ������ �߰��ؾߵȴ�.
//�������� ������ ������ ������ ��ġ��ų �ʿ����.
//�ڿ� ���� �������� �˸�Ǵϱ�!

//<head Value, nextPtr> -> <next Value, nextnext Ptr> ->.....

//insert
//��� �ϳ� ����� ���ϴ� �� �ְ� ��ũ�� �� ��� �����ųְ�
//�����ſ� �����͸� ���ο� ���� ����ġ���� ��

//delete
//������ ��� �������� ã�´�. �°� ��������ġ�� �����͸� �ٴ����ɷ� �ٲ��ش�.
//������ ��� ����

//������ 
//�ƹ��͵� �𸣴� ���¿��� ���ϴ� ������ ã����� ó������ ���ƾߵȴ�. 
//�׷��� �������� �������� �˰� ������ �� �ִٸ� ���� ���ϰ� ����� �� �ִ�.


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
		//�����ϸ� �ݺ������� ������ �� �־ �����Ҷ��� �����ϰ� �߽��ϴ�.
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

	//��ȯ���� ���̸� ��ϴ�. 

	one = list->head;
	two = list->head;

	//��ü���̴� ��ȯ������(q) + �ƴѱ���(p)
	//one�� q��ŭ ������ cycle head������ p�� ���ƿ�
	//list head�� �ִ� two�� cycle head ������ p��ŭ ���ƿ�
	//�ֳĸ� head���� cycle head������ ���̴� ��ü���� ��ȯ���� ���̸� ������ p�̱� �����Դϴ�.

	while (cycleCount)
	{
		one = one->next;
		cycleCount--;
	}

	//���� ���� ���������� ������ ����� �ϸ� �˴ϴ�. 

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

	printf("\n������ data, ���� ����� �ּ�, ���� ��忡 ����� data ���\n\n");

	while (currentPtr)
	{
		printf("%d, ", currentPtr->value);
		currentPtr = currentPtr->next;
		printf("%p, ", currentPtr);
		if (currentPtr != (node_t *)NULL) printf("%d\n", currentPtr->value);
		else printf("����\n");
	}
	fflush(stdin);
	getchar();
	return;
}

void practice34(list_t* list, node_t* node1, node_t* node2, node_t* node3, node_t* node4, node_t* node5, node_t* node6)
{

	printf("\n��� ����� data�� printf�� ����ϴ� �Լ�����\nList�� �� �տ� node �߰��ϴ� �Լ� ����\n\n");

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

	printf("\n�־��� key�� ���� ��� ã�� �Լ� ���� 70 & 100\n\n");

	printf("��ü ����Ʈ: ");
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

	printf("\n�־��� ���(40) ������ �� ���(45) �߰��ϴ� �Լ� ����\n�Ǿ�(NULL��)�� �� ���(5) �߰��ϴ� �Լ� ����\n\n");


	newNode1->value = 45;
	newNode2->value = 5;
	printf("��ü ����Ʈ\n");
	printAllNodes(&list);
	currentPtr = searchNode(&list, 40);
	insertNode(&list, currentPtr, newNode1);
	printf("40�ڿ� 45�߰�\n");
	printAllNodes(&list);
	insertNode(&list, NULL, newNode2);
	printf("�� �տ� 5 �߰�\n");
	printAllNodes(&list);

	fflush(stdin);
	getchar();

	return;
}

void practice89(list_t list)
{

	node_t* nodePtr;

	printf("\n���� 40�� ��� �����ϴ� �Լ�\n��尡 ���������� ��� ��带 �����ϴ� �Լ�\n\n");
	printf("��ü ����Ʈ\n");
	printAllNodes(&list);
	nodePtr = searchNode(&list, 40);
	deleteNode(&list, findPrevNode(&list, nodePtr), nodePtr);
	printf("���� 40�� ��� ����\n");
	printAllNodes(&list);
	printf("��尡 ������������ ��带 ����\n");
	while (list.head)
	{
		deleteNode(&list, (node_t*)NULL, list.head);
		printAllNodes(&list);
	}

	fflush(stdin);
	getchar();

	return;
}