#include<stdio.h>
#include<stdlib.h>

typedef enum{
	left, right, plus, minus, multi, divide, modulo, eos, number
}precedence;

typedef struct Stack{
	int top;
	int* value;
}stack;

#define MAX_STR_NUM 100
#define MAX_STACK_SIZE 4


stack createStack(void)
{
	stack newStack;
	newStack.top = -1;
	newStack.value = (int*)malloc(sizeof(int)*MAX_STACK_SIZE);
	memset(newStack.value, 0, sizeof(int)*MAX_STACK_SIZE);
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

int isEmpty(stack stack)
{
	return (stack.top == -1);
}

int isFull(stack stack)
{
	return (stack.top >= MAX_STACK_SIZE - 1);
}

int push(stack* stackPtr, int value)
{
	if (isFull(*stackPtr)) {
		printf("FULL!\n");
		return 0;
	}
	else stackPtr->value[++(stackPtr->top)] = value; return 1;
}

int pop(stack* stackPtr)
{
	int pop;
	if (isEmpty(*stackPtr))
	{
		printf("EMPTY!\n");
		return 0;
	}
	else {
		pop = stackPtr->value[stackPtr->top];
		stackPtr->value[stackPtr->top--] = 0;
		return pop;
	}
}

precedence getToken(char* str, int* idx)
{
	switch (str[(*idx)++])
	{
	case '(':
		return left;
	case ')':
		return right;
	case '+':
		return plus;
	case '-':
		return minus;
	case '*':
		return multi;
	case '/':
		return divide;
	case '%':
		return modulo;
	case '\0':
		return eos;
	default:
		return number;
	}

}

int main(void)
{
	precedence token;
	stack operateStack = createStack();
	char str[MAX_STR_NUM];
	int strIdx = 0;
	int num1, num2;
	gets(str);
	
	while (1)
	{
		token = getToken(str, &strIdx);
		if (token == number) push(&operateStack, (str[strIdx-1] - '0'));

		else if (token != eos)
		{
			num2 = pop(&operateStack);
			num1 = pop(&operateStack);
			switch (token)
			{
			case plus:
				push(&operateStack, num1 + num2);
				break;
			case minus:
				push(&operateStack, num1 - num2);
				break;
			case multi:
				push(&operateStack, num1 * num2);
				break;
			case divide:
				push(&operateStack, num1 / num2);
				break;
			case modulo:
				push(&operateStack, num1 % num2);
				break;
			default:
				printf("ERROR!\n");
				return -1;
			}
		}

		else
		{
			num1 = pop(&operateStack);
			printf("%d", num1);
			return num1;
		}
	}
}

