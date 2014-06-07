
//EXTRA BONUS

//level traveral로 모든 노드의 data 출력 함수 구현
//QUEUE로 구현
//testTreeWithLevelorder() 함수를 호출해서 이미 만들어진 아래 그림의 노드 data들을 차례로 출력
//출력 결과 : + * E * D / A B

//기본 아이디어
//처음 Queue에 tree->head를 넣는다.
//deQueue를 하고 나온 노드의 왼쪽 아들과 오른쪽 아들을 순서대로 넣는다.
//아들이 없으면 넣지 않는다.
//큐를 사용하면 먼저 넣은 아들이 먼저 나오기 때문에, 
//그리고 나온 노드의 아들 순서로 큐에 삽입되기 때문에,
//위를 반복하면 트리에 있는 모든 노드에 레벨 순으로 체크할 수 있다.


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
