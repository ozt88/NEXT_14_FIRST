#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Queue{

	int front;
	int rear;
	int capacity;
	int* value;

}queue;

queue createQueue(void)
{
	queue newQueue;
	
	newQueue.front = 0;
	newQueue.rear = 0;
	newQueue.capacity = 2;
	newQueue.value = (int*)malloc(sizeof(int)*(newQueue.capacity));
	memset(newQueue.value, NULL , sizeof(int)*(newQueue.capacity));

	return newQueue;
}

int freeQueue(queue* queuePtr)
{
	if (queuePtr->value)
	{
		free(queuePtr->value);
		queuePtr->front = 0;
		queuePtr->rear = 0;
		return 0;
	}
	else return -1;
}

int isFull(queue que)
{
	if (que.front == (que.rear + 1) % que.capacity) return 1;
	else return 0;
}

int isEmpty(queue que)
{
	if (que.front == que.rear) return 1;
	else return 0;
}

//주소끼리 비교할 수 없으므로 srcBegin >srcEnd 인 경우 조심할 것
int copyBlock(int* srcBegin, int* srcEnd, int* dst)
{
	if (srcBegin >= srcEnd) return -1;
	while(srcBegin != srcEnd)
	{
		*(dst++) = *(srcBegin++);
	}
	return 0;
}

//
//int copyBlock(int* from, int* to, int idxBegin, int idxEnd )
//{
//	if (idxBegin >= idxEnd) return -1;
//	for (int i = 0; idxBegin + i < idxEnd; i++)
//	{
//		*(to + i) = *(from + idxBegin + i);
//	}
//	return 0;
//}

int queueExtension(queue* queuePtr)
{
	int start = 0;
	queue newQue;
	newQue.value = (queue*)malloc(sizeof(queue)*(queuePtr->capacity) * 2);
	memset(newQue.value, 0, sizeof(queue)*(queuePtr->capacity) * 2);
	start = (queuePtr->front + 1) % (queuePtr->capacity);

	if (start < 2)
	{
		copyBlock(queuePtr->value + start, queuePtr->value + start + (queuePtr->capacity) - 1, newQue.value);
	}
	else
	{
		copyBlock(queuePtr->value + start, queuePtr->value + queuePtr->capacity, newQue.value);
		copyBlock(queuePtr->value, queuePtr->value + queuePtr->rear, (newQue.value) + queuePtr->capacity - start);
	}

	queuePtr->front = ((queuePtr->capacity) * 2) - 1;
	queuePtr->rear = queuePtr->capacity - 2;
	queuePtr->capacity = (queuePtr->capacity) * 2;
	free(queuePtr->value);
	queuePtr->value = newQue.value;

	return 0;
}

int enQueue(queue* queuePtr, int value)
{
	queuePtr->rear = (queuePtr->rear + 1) % queuePtr->capacity;
	if (isFull(*queuePtr)) 
	{
		queueExtension(queuePtr);
	}
	queuePtr->value[queuePtr->rear] = value;

	return 0;
}


int deQueue(queue* queuePtr)
{
	int deQueueValue = NULL;
	if (isEmpty(*queuePtr))
	{
		puts("\nError! No more item.\n");
		getchar();
		getchar();
		return -1;
	}
	else
	{
		queuePtr->front = ((queuePtr->front) + 1) % queuePtr->capacity;
		deQueueValue = queuePtr->value[queuePtr->front];
		queuePtr->value[queuePtr->front] = NULL;
		return deQueueValue;
	}
}

void testQueue(queue que)
{
	printf("\nTEST QUE\n");
	for (int i = 0; i < que.capacity; i++)
	{
		printf("%2d", que.value[i]);
	}
	printf(" \n");

	return;
}

int main(void){

	queue que = createQueue();
	int input = 0;
	int output = 0;

	for (int i = 0; !isFull(que) ; i++)
	{
		system("cls");
		testQueue(que);
		printf("숫자 입력 (0이면 deQueue): ");
		scanf("%d", &input);
		if (input) enQueue(&que, input);
		else 
		{
			output = deQueue(&que);
			if (output != -1)
			{
				printf("\nOUT QUE : %d\n", output);
				getchar();
				getchar();
			}
		}
	}
	
	
	return 0;
}