
//EXTRA BONUS

//level traveral�� ��� ����� data ��� �Լ� ����
//QUEUE�� ����
//testTreeWithLevelorder() �Լ��� ȣ���ؼ� �̹� ������� �Ʒ� �׸��� ��� data���� ���ʷ� ���
//��� ��� : + * E * D / A B

//�⺻ ���̵��
//ó�� Queue�� tree->head�� �ִ´�.
//deQueue�� �ϰ� ���� ����� ���� �Ƶ�� ������ �Ƶ��� ������� �ִ´�.
//�Ƶ��� ������ ���� �ʴ´�.
//ť�� ����ϸ� ���� ���� �Ƶ��� ���� ������ ������, 
//�׸��� ���� ����� �Ƶ� ������ ť�� ���ԵǱ� ������,
//���� �ݺ��ϸ� Ʈ���� �ִ� ��� ��忡 ���� ������ üũ�� �� �ִ�.


#include<stdio.h>
#include"tree.h"


int testTreeWithLevelorder(tree_t* tree)
{
	queue_t* treeQ;
	node_t* currentNode;

	if (!tree)
	{
		return -1;
	}

	treeQ = makeQueue();
	currentNode = tree->root;
	printf("\n\nLEVELORDER PRINT\n\n");

	while (currentNode)
	{
		printf("%3c", currentNode->value);

		if (currentNode->leftChild)
		{
			enQueue(treeQ, currentNode->leftChild);
		}

		if (currentNode->rightChild)
		{
			enQueue(treeQ, currentNode->rightChild);
		}

		currentNode = deQueue(treeQ);
	}

	printf("\n");

	return 0;
}


queue_t* makeQueue(void)
{
	queue_t* newQueue = (queue_t*)malloc(sizeof(queue_t));
	memset(newQueue, 0, sizeof(queue_t));
	queNode_t* sentinel = (queNode_t*)malloc(sizeof(queNode_t));
	memset(sentinel, 0, sizeof(queNode_t));

	newQueue->head = sentinel;
	newQueue->tail = sentinel;

	return newQueue;
}


int enQueue(queue_t* queue, node_t* newNode)
{
	queNode_t* newQueNode;
	
	if (!queue || !newNode)
	{
		return -1;
	}

	newQueNode = (queNode_t*)malloc(sizeof(queNode_t));
	memset(newQueNode, 0, sizeof(queNode_t));

	newQueNode->node = newNode;
	queue->tail->next = newQueNode;
	queue->tail = newQueNode;

	return 0;
}


node_t* deQueue(queue_t* queue)
{
	node_t* deNode;
	queNode_t* first;

	if (!queue || !queue->head ) 
	{
		return (node_t*)NULL;
	}
	
	if (queue->head == queue->tail)
	{
		return (node_t*)NULL;
	}

	first = queue->head->next;
	deNode = queue->head->next->node;
	queue->head->next = first->next;

	if (queue->tail == first)
	{
		queue->tail = queue->head;
 	}
	
	free(first);

	return deNode;
}
