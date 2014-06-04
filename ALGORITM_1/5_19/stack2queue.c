#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 2

typedef struct Stack{
	int top;
	int* value;
	int capacity;
}stack;

//스택 두개로 큐를 만드는 기본 아이디어
//1.선입선출 시키고 싶으면 스택하나에 입력 받다가 순서대로 다른 스택으로 옮기면 역순이 되므로
//거기서 다시 pop시키면 deQueue랑 동일한 기능을 한다.
//2.받는 순서는 같고 뱉는 순서만 역순이므로 
//받는 역할을 하는 스택과 뱉는 역할을 하는 스택을 나누어서 
//enQueue시에는 enQ용 스택에 내용물을 담고 
//deQueue시에는 역순이 되게 deQ용 스택에 옮겨 담은후 pop한다.
//3.FULL이 되면 두배로 늘리는 작업은 그냥 push할때 꽉찾다 싶으면 
//스택용량만 두배해주면 된다.
//스택은 탑만 신경쓰면 하는 일은 똑같기 때문이다.

stack createStack(void)
{
	stack newStack;

	newStack.top = -1;
	newStack.capacity = MAX_STACK_SIZE;
	newStack.value = (int*)malloc(sizeof(int)*newStack.capacity);
	memset(newStack.value, 0, sizeof(int)*newStack.capacity);

	return newStack;
}

int freeStack(stack *stackPtr)
{
	if (stackPtr->value)
	{
		free(stackPtr->value);
		stackPtr->top = -1;
		return 0;
	}
	else return -1;
}

int stackIsEmpty(stack stack)
{
	return (stack.top + 1 <= 0);
}

int stackIsFull(stack stack)
{
	return (stack.top >= stack.capacity - 1);
}

void stackExtension(stack* stackPtr)
{
	int* newValue = (int*)malloc(sizeof(int)*(stackPtr->capacity)* 2);
	
	memset(newValue, 0, sizeof(int)*(stackPtr->capacity) * 2);
	for (int i = 0; i < stackPtr->capacity; i++)
	{
		newValue[i] = stackPtr->value[i];
	}
	free(stackPtr->value);
	stackPtr->value = newValue;
	stackPtr->capacity *= 2;
}

int stackPush(stack* stackPtr, int input)
{
	if (stackIsFull(*stackPtr))
	{
		stackExtension(stackPtr);
	}
		stackPtr->value[++(stackPtr->top)] = input;
		return 0;
}

int stackPop(stack* stackPtr)
{
	int pop;
	if (stackIsEmpty(*stackPtr)) { 
		printf("IS EMPTY ERROR!!\n"); 
		return -1; 
	}
	else {
		pop = stackPtr->value[stackPtr->top];
		stackPtr->value[stackPtr->top--] = 0;
		return pop;
	}
}

int stack2Stack(stack* fromPtr, stack* toPtr)
{
	while (!stackIsEmpty(*fromPtr))
	{
		stackPush(toPtr, stackPop(fromPtr)); 
	}
	return 0;
}

//한 번의 enQ를 실행할때 stack2Stack 한번 stackPush 한번
//stackPush 한번할때 시간 복잡도 1
//stack2Stack하면 from에 있는 원소 개수만큼 pop하고 push하므로 
//최악의 경우(from이 full인 경우) 시간복잡도 n
//전체 시간 복잡도 O(n)
int enQueue(stack* inputStackPtr, stack* outputStackPtr, int input)
{
	stack2Stack(outputStackPtr, inputStackPtr);
	return stackPush(inputStackPtr, input);
}

//한번의 deQ를 실행할때 stack2Stack 한번 stackPop 한번
//stackPop 한번할때 시간 복잡도 1
//stack2Stack하면 from에 있는 원소 개수만큼 pop하고 push하므로 
//최악의 경우(from이 full인 경우) 시간복잡도 n
//전체 시간 복잡도 O(n)
int deQueue(stack* inputStackPtr, stack* outputStackPtr)
{
	stack2Stack(inputStackPtr, outputStackPtr);
	return stackPop(outputStackPtr);
}

void testQueue(stack inputStack, stack outputStack)
{
	printf("\nTEST INPUTSTACK\n");
	for (int i = 0; i < inputStack.capacity; i++)
	{
		printf("%2d", inputStack.value[i]);
	}
	printf(" \n");
	printf("\nTEST OUTPUTSTACK\n");
	for (int i = 0; i < outputStack.capacity; i++)
	{
		printf("%2d", outputStack.value[i]);
	}
	printf(" \n");

	return;
}
int main(void)
{
	int idx = 0;
	int input = 0;
	int output = 0;
	stack inputStack = createStack();
	stack outputStack = createStack();
	
	while (1)
	{
		system("cls");
		testQueue(inputStack, outputStack);
		printf("숫자 입력 (0이면 deQueue): ");
		scanf("%d", &input);
		if (input) enQueue(&inputStack, &outputStack, input);
		else
		{
			output = deQueue(&inputStack, &outputStack);
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
