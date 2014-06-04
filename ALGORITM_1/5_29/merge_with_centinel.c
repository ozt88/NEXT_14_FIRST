//������������ ���ĵ� �� ����Ʈ�� �޾Ƽ� �� ����Ʈ�� ���ĵ� ���·� ������ ����Ʈ�� �����ϴ� �Լ��� ������.
//�⺻ ���̵��: ������ ���ϴ� �Լ��� ������ ���·� ��������.

//1.����Ʈ �� ���� üũ�ϴ� �� ���� ��� �����͸� �д�.

//2.�� ����Ʈ�� ����� ���� ��� �����͸� ���ؼ� ���������� ���Ѵ�.

//3.���� Ƚ���� ���̱� ���ؼ�, �񱳵� ����� ���� ��� �������� �������� �����ϰ� �Ѵ�.
	//3-1.�� ����Ʈ�� ���������� ���ϴ� ��ü���� ���
		//i)�� ����� ���� ���� ��� �� ��� �����Ͱ� ����ġ�� ��带 ���� ����Ʈ�� �����ϰ�, �� ��� �����͸� ��� �� �ܰ� �ڷ� ������.
		//ii)�� ����� ���� �ٸ� ��� �� ��� �������߿� ���� ���� ���� ����Ʈ�� �����ϰ�, ���� ���� ���� ��� �����͸� �Ѵܰ� �ڷ� ������.
		//���� ���� �۾��� �ݺ��ϸ� �� ����Ʈ�� �̹� ������������ ���ĵǾ� �ֱ� ������, ��� ����Ʈ�� ������ ���� �� �ְ� �ȴ�.
		//�� ����Ʈ���� �̹� ó���� �� ����� ���� �� ����� ������ �ݵ�� �۴ٴ� ������ �ֱ� �����̴�.

//4.��� ������ ���ɽ����� �ٷ��.
	//4-1.��� �����Ͱ� ��ü ����Ʈ�� üũ�ϰ� �ᱹ NULL�� �� ���
		//i)�� ��� �����Ͱ� ��ü ����Ʈ�� ��� üũ�ߴٸ� ������ �����ϰ� ������ ����Ʈ�� �����Ѵ�.
		//ii)�Ѱ��� ��� �����͸� NULL�� �Ǿ��ٸ� ������ ��� �����͸� ���� ����Ʈ�� �����ϰ� �Ѵܰ� �ڷ� ������.

//5.���ο� ����Ʈ�� ��带 �����ϴ� ���
	//i)������������ �����ؾ��ϴµ� �츮�� ���� ������ ���������� ã�� �����Ѵ�.
	//ii)���ο� ��尡 ���ԵǸ� �� ���� �� �ڿ� ���� �Ǿ�� �Ѵ�.
	//iii)������ ��带 ��� �����͸� ���� ����ϰ� �� ��ҿ� ���ο� ��带 �����Ѵ�.

//6. ��Ƽ�� ��尡 �ʿ��� ����
	//i)���ο� ����Ʈ�� ���� ��� �����ʹ� ��Ƽ���� ���ٸ� �ʱⰪ�� NULL�� �ȴ�. 
	//ii)��带 ������ �� ���� ��� �����͸� �����ؼ� �� �ڿ� �����ϰ� �ȴ�.
	//iii)������ �ڿ� ��� �����ʹ� �ؽ�Ʈ�� �Űܰ����ϴµ�, 
	//NULL�� �ڷ� �����϶�� ���� ������ NULL�� �ؽ�Ʈ�� ��ġ��Ű�� ���� �ƴ϶� �׳� ��忡 ��ġ��Ų��.
	//���� ���ο� ����Ʈ�� ���� ��� �����ʹ� �� ���� �ؽ�Ʈ�� �������� ���Ѵ�.
	//�Լ��� �ǵ��� �� �¾� �������� �ϱ� ���ؼ��� ��尡 �׻� �����ϵ��� ��Ƽ���� �ϳ� �δ� ����� �����ϴٰ� �����Ѵ�.

//6-1. ��Ƽ�� ��带 ���� �ʴ� ���
	//�Լ��� �ǵ��� �����غ��� ���ο� ����Ʈ�� ���� ��� �����ʹ� �׻� ������ ���� ����ġ�� �ϸ�ȴ�.
	//���� ���ԵǴ� ��尡 ������ ��ġ�� ���� �ǹǷ� �� ����� �ּҸ� ���ο� ����Ʈ�� ���� ��� �����Ͱ� �޵��� �ϸ� �ذ��� �� �ִ�.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NUM_OF_NODE 10

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


int main(void)
{
	list_t* list1 = makeList();
	list_t* list2 = makeList();
	list_t* mergeList;
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
			list1->head->next = nodeArr1[i];
			list2->head->next = nodeArr2[i];
		}
	}
	printf("����Ʈ 1\n");
	printList(list1->head->next);
	printf("����Ʈ 2\n");
	printList(list2->head->next);
	printf("���� ����Ʈ\n");
	printList(merge(list1, list2)->head->next);

	return 0;
}

list_t* merge(list_t* list1, list_t* list2)
{
	list_t* newList = makeList();
	node_t* nodePtr1; //list1�� ���� ��� ������.
	node_t* nodePtr2; //list2�� ���� ��� ������.
	node_t* nodePtr3; //newList�� ���� ��� ������.
	node_t* tempPtr; //�ӽ� �����.

	if (!list1 || !list2)
	{
		return (list_t*)NULL;
	}

	nodePtr1 = list1->head->next; //list���� �ǹ��ִ� ù��° ����� �ּҷ� �ʱ�ȭ.
	nodePtr2 = list2->head->next;
	nodePtr3 = newList->head; //�����Լ��� �� ������ �ڿ� ���ο� ��带 �����ϹǷ� ���� �ʱ�ȭ.

	while (nodePtr1 || nodePtr2) //��������. �� ��� ������ ��� NULL�� �Ǹ� ����
	{
		if (!nodePtr2) //�������. �Ѱ��� ��� �����͸� NULL�̸� �ٸ� ����Ʈ�� ��带 �����Ѵ�.
		{
			tempPtr = nodePtr1->next;	//��� ������ 1�� ���� �ּҴ� ���� �Լ��� ��ġ�� �ٲ�� ������ �ӽ� �����Ϳ� �����Ѵ�.
			insertNode(newList, nodePtr3, nodePtr1); 
			nodePtr1 = tempPtr;	//����Ʈ 1�� ���� ��� �����Ͱ� ����Ʈ 1�� ���� �ּҷ� �����ϱ� ���ؼ� �ӽ� ����� �������� �ּҸ� �޴´�.
			nodePtr3 = nodePtr3->next;	//����Ʈ 3�� ���� ��������ʹ� ������ �� �ڸ� �����ľ� �� �� ����� �ּҸ� �����Եȴ�.
		}
		else if (!nodePtr1)
		{
			tempPtr = nodePtr2->next;
			insertNode(newList, nodePtr3, nodePtr2);
			nodePtr2 = tempPtr;
			nodePtr3 = nodePtr3->next;
		}
		else if (nodePtr1->value < nodePtr2->value) //���� ���� �����Ѵ�.
		{
			tempPtr = nodePtr1->next;
			insertNode(newList, nodePtr3, nodePtr1);
			nodePtr1 = tempPtr;
			nodePtr3 = nodePtr3->next;
		}

		else if (nodePtr1->value > nodePtr2->value)
		{
			tempPtr = nodePtr2->next;
			insertNode(newList, nodePtr3, nodePtr2);
			nodePtr2 = tempPtr;
			nodePtr3 = nodePtr3->next;
		}

		else if (nodePtr1->value == nodePtr2->value) //������ �Ѵ� ����.
		{
			tempPtr = nodePtr1->next;
			insertNode(newList, nodePtr3, nodePtr1);
			nodePtr1 = tempPtr;
			nodePtr3 = nodePtr3->next;

			tempPtr = nodePtr2->next;
			insertNode(newList, nodePtr3, nodePtr2);
			nodePtr2 = tempPtr;
			nodePtr3 = nodePtr3->next;
		}
	}

	return newList;
}

//��Ƽ���� ���ٸ� ����Ʈ �����ܰ迡�� �߰��ϴ� ���� ����.

list_t* makeList(void)
{
	list_t* newList = (list_t*)malloc(sizeof(list_t));
	node_t* sentinelHead = (node_t*)malloc(sizeof(node_t));

	memset(newList, 0, sizeof(list_t));
	memset(sentinelHead, 0, sizeof(node_t));
	newList->head = sentinelHead;
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

//��Ƽ�� ������ �����ϰ� ���� �� �ִ� �����Լ�.
//��Ƽ���� ���ٸ� preNode�� NULL�� ��츦 ����ϰ� ��带 ���� �����ϴ� ������ �߰��ȴ�.

int insertNode(list_t* list, node_t* preNode, node_t* newNode)
{
	if (!list || !newNode || !preNode)
	{
		return -1;
	}

	newNode->next = preNode->next;
	preNode->next = newNode;

	return 0;
}
