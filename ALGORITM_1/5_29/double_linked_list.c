
//DOUBLE CIRCULAR LINKED LIST�� ����� �װ����� �پ��� ����� �����Ѵ�.
//1.����Ʈ ���� �׽�Ʈ �Լ�
//������ data, ���� ����� �ּ�, ���� ��忡 ����� data, 
//���� ����� �ּ�, ���� ��忡 ����� data ���
//2.����Ʈ�� ��� ����� data�� printf�� ����ϴ� �Լ� ����
//3.�־��� key�� ���� ��� ã�� �Լ� ����
//4.�־��� ��� ������ �� ��� �߰��ϴ� �Լ� ����
//5.��� �����ϴ� �Լ� ����


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

	printf("���� ����Ʈ �׽�Ʈ\n");
	print_current_prev_next(dList);

	printf("����Ʈ ���\n");
	print_list(dList);

	printf("Ű������ ��带 �˻�\n");
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

	printf("���ο� ���(45)�� ���� ���(16) �ڿ� ����\n");
	insert_node(search_node(dList, 16), make_double_node(45));
	print_list(dList);

	printf("������ ���(16)�� ����\n");
	delete_node(dList, search_node(dList, 16));
	print_list(dList);

	clearList(dList);

	return 0;
}


//1-1.���� ��ũ�� ����Ʈ(��ȯ) ����� �Լ�
//������Ʈ�� �����ͷ� �����ϰ� �ַ����� �Ҵ��Ѵ�.
//�����(��Ƽ��)�� �����ͷ� �����ϰ� �ַ����� �Ҵ��Ѵ�.
//�� ��带 �ʱ�ȭ�ϰ� �� ����Ʈ�� ���� �����Ѵ�.

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

//1-2.���� ��ũ�� ��带 �����Ѵ�.
//��� �����͸� �����ϰ� �ַ����� �Ҵ�.
//�ؽ�Ʈ�� �����긦 �η� �ʱ�ȭ �����ְ� �����͸� ������ �ִ´�.
dNode_t* make_double_node(int data)
{
	dNode_t* newDNode = (dNode_t*)malloc(sizeof(dNode_t));
	newDNode->next = (dNode_t*)NULL;
	newDNode->prev = (dNode_t*)NULL;
	newDNode->value = data;

	return newDNode;
}

//1-3.��带 ����Ʈ�� ��� �ڿ� �����ϴ� �Լ�.(����Ʈ�� �ʱ� �����ϴµ� ���δ�.)
//i)���� ��� �ڿ� �ִ� ���(��ǻ� �� �ճ��)�� ���� ����� �ڿ� ���´�.(next & prev)
//ii)����� �ڿ� ��带 ���´�.(next & prev)

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

//1-4.����Ʈ�� ó������ ������ ���鼭 ���簪, ���� �ּ�, ���� ��, ���� �ּ�, ���� ��
//����ϴ� �Լ�
//i)�������� ��� �����͸� �����ϰ� ����� ���� ���� �ʱ�ȭ.
//ii)�ؽ�Ʈ ���� �ϳ��� �Ѿ�鼭 �ʿ��� ������ ����ϰ� ���� ���ƿ��� ����.

//???�ǹ���: ��ȯ ��ũ�� ����Ʈ�̹Ƿ� �ؽ�Ʈ�� �����갡 NULL�� �� ����!
//???�׷��� �������� next�� prev�� NULL�� ��쿡 �ٸ� ������� ����ϱ� ���ϴ� ��,
//???�̰��� �ؽ�Ʈ�� �����갡 �ǹ̾��� ��Ƽ���� head�� ����ų �� �̷��� ����϶�� ���ΰ�?
//???�ϴ� ���� ������ ���缭 �ڵ带 �ۼ��Ͽ���.

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
			printf("%-4s\t", "����");
		}
		
		if (currentNode->next != list->head)
		{
			printf("%-10p\t", currentNode->next);
			printf("%-4d\t", currentNode->next->value);
		}
		else
		{
			printf("%-10s\t", "NULL");
			printf("%-4s\t", "����");
		}
		printf("\n");
		currentNode = currentNode->next;
	}

	return 0;
}

//2.����Ʈ�� �ִ� data���� �ϳ��� ����ϴ� �Լ�
//i)���� ����� ��� �����͸� �����ϰ� ����Ʈ�� ����� �������� �ʱ�ȭ.
//ii)�ؽ�Ʈ�� ���� �ϳ��� ����ϰ� ���� ���ƿ����� ����

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

//3.key���� ������ �ִ� ��带 ã�� �Լ�
//i)���� ����� ��� �����͸� �����ѵ� ����� �ڿ� �ִ� ���� �ʱ�ȭ
//ii)���� ��尡 �ϳ� �� �� ���� ���� �Űܰ��鼭 key���� ������ üũ
//iii)���� ����� ���� Ű ���� ������ �ݺ������� ���ͼ� ���� ����� �ּҸ� ����
//iv)���� ��带 ��� ������ �ѹ��� �������� ��ü�� �׷� key���� ���ٴ� �ǹ��̹Ƿ� NULL�� ����

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

//4.���ο� ��带 � ��� �ڿ� �����ϴ� �Լ�.
//��Ƽ���� �����Ƿ� ��带 �ٲ��� �ʿ䰡 ���� ������ list�� ���ڷ� ���� �ʿ䰡 ����.
//���� ���� �������� NULL�� prevNode�� �� �� ����. �� �տ� �ְ� ������ prev�ڸ��� ��带 �־���Ѵ�.
//i)���ο� ��带 ���� ���� ����� �ڿ��ִ� ��� �տ� �ִ´�.(next & prev)
//ii)�׸��� ���� ����� �ڿ��ٰ� ���ο� ��带 ����ִ´�. (next & prev)
//�� ������ �޶����� ���� ���� ����� �ڿ� �ִ� ��带 �� �� �����Ƿ� ����� ���� ���� �� ����. ����.

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

//5.������ ��带 ����Ʈ���� �����ϴ� �Լ�
//��Ƽ���� �����Ƿ� node->next Ȥ�� node->prev�� NULL�� ��츦 ����� �ʿ����.
//������ ��� �յ��� ��带 �������ְ� �� ��带 �����ϱ⸸ �ϸ� ���� �Ϸ�.
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

//����Ʈ�� �����ϴ� �Լ�.

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
