//STACK LINKED LIST�� Ȱ���� INVERT����Դϴ�.
//������ �ٸ� �������� �Ű� ������� ������ �Ǵ� ���� �����߽��ϴ�.


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

	//��带 �ϳ��ϳ� �����ϴ� ���ŷο��� �غ��ϱ� ���ؼ� ������ ������ �迭�� �����ϰ�
	//�ݺ����� �����鼭 makeNode��� �Լ��� ������ �����߽��ϴ�.
	//�������Ŀ� �ٷ� ���� ���ÿ� Ǫ���߽��ϴ�.
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


//���� ������ �����ϴ� �Լ�
//�ַ����� ����Ʈ �����͸� �Ҵ��ϰ� �ʱ�ȭ�մϴ�. 
//��Ƽ������ ž�� 0���� �����߽��ϴ�.

stackList_t* makeStackList(void)
{
	stackList_t* newstackList = (stackList_t*)malloc(sizeof(stackList_t));
	memset(newstackList, 0, sizeof(stackList_t));
	
	newstackList->top = (node_t*)NULL;
	return newstackList;
}

//��带 �����ϴ� �Լ�
//�ַ����� ��� �����͸� �Ҵ��ϰ� �ʱ�ȭ �ѵڿ� ���ϴ� ���� �Է��߽��ϴ�.

node_t* makeNode(int data)
{
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	memset(newNode, 0, sizeof(node_t));
	newNode->value = data;
	return newNode;
}

//���� ����Ʈ�� ����ϴ� �Լ�
//Ŀ��Ʈ����� ��� �����͸� Ȱ�� top(Ȥ�� head)�������� �ϳ��� �ؽ�Ʈ�� �Ѿ�鼭 ����մϴ�.

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


//���� ���ÿ� Ǫ���ϴ� �Լ�
//������ ����������� ������� �������� ������ ����˴ϴ�.
//��������� ���ο� ��带 ž�� ���⸸ �ϰ�
//������� ������ ������ ž�� �ؽ�Ʈ�� ���ο� ���� �����ѵ� ���ο� ��带 ž���� �����մϴ�.


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


//���ὺ���� �� �Լ�
//���� �Է��� ����� �̷������ ���� ���� ��Ƽ�� ��츦 �Ѳ����� ó���߽��ϴ�.
//�켱 �� ����� ��� �����͸� Ȱ�� �ӽ� �����ϴ� ��Ҹ� ����� ���� ž ��带 �����ϰ�
//���� ������ ž�� ���� ž�� �ؽ�Ʈ�� �����մϴ�.
//�׸��� �� ��忡 ����� ���� ž ����� ������ �����صڿ� �����մϴ�.

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

//������ ���ὺ���� ����� �Լ�
//���ο� ���ø���Ʈ�� ����� �Էµ� ������ ���ὺ���� ���ϸ鼭 Ƣ��� ��带 ���ο� ���� ���ÿ� Ǫ���մϴ�.
//�Էµ� ������ ���ὺ���� ��Ƽ�� �Ǹ� �ݺ����� �����ϰ� ���ο� ���� ����Ʈ�� �����մϴ�.

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

//����Ʈ�� �����ϴ� �Լ�
//����Ʈ�� ���Ե� ��� ������ ��忡������ �ϳ��� �Ѿ�鼭 �����ϰ�
//�������� ����Ʈ���� �����ѵ� ����.

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