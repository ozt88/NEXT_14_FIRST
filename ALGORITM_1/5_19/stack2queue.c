#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 2

typedef struct Stack{
	int top;
	int* value;
	int capacity;
}stack;

//���� �ΰ��� ť�� ����� �⺻ ���̵��
//1.���Լ��� ��Ű�� ������ �����ϳ��� �Է� �޴ٰ� ������� �ٸ� �������� �ű�� ������ �ǹǷ�
//�ű⼭ �ٽ� pop��Ű�� deQueue�� ������ ����� �Ѵ�.
//2.�޴� ������ ���� ��� ������ �����̹Ƿ� 
//�޴� ������ �ϴ� ���ð� ��� ������ �ϴ� ������ ����� 
//enQueue�ÿ��� enQ�� ���ÿ� ���빰�� ��� 
//deQueue�ÿ��� ������ �ǰ� deQ�� ���ÿ� �Ű� ������ pop�Ѵ�.
//3.FULL�� �Ǹ� �ι�� �ø��� �۾��� �׳� push�Ҷ� ��ã�� ������ 
//���ÿ뷮�� �ι����ָ� �ȴ�.
//������ ž�� �Ű澲�� �ϴ� ���� �Ȱ��� �����̴�.

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

//�� ���� enQ�� �����Ҷ� stack2Stack �ѹ� stackPush �ѹ�
//stackPush �ѹ��Ҷ� �ð� ���⵵ 1
//stack2Stack�ϸ� from�� �ִ� ���� ������ŭ pop�ϰ� push�ϹǷ� 
//�־��� ���(from�� full�� ���) �ð����⵵ n
//��ü �ð� ���⵵ O(n)
int enQueue(stack* inputStackPtr, stack* outputStackPtr, int input)
{
	stack2Stack(outputStackPtr, inputStackPtr);
	return stackPush(inputStackPtr, input);
}

//�ѹ��� deQ�� �����Ҷ� stack2Stack �ѹ� stackPop �ѹ�
//stackPop �ѹ��Ҷ� �ð� ���⵵ 1
//stack2Stack�ϸ� from�� �ִ� ���� ������ŭ pop�ϰ� push�ϹǷ� 
//�־��� ���(from�� full�� ���) �ð����⵵ n
//��ü �ð� ���⵵ O(n)
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
		printf("���� �Է� (0�̸� deQueue): ");
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
