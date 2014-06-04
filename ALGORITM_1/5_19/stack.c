#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct Stack{
	int top;
	char* value;
}stack;

stack createStack(void)
{
	stack newStack;
	newStack.top = -1;
	newStack.value = (char*)malloc(sizeof(char)*MAX_STACK_SIZE);

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
	if (stack.top + 1) return 0;
	else return 1;
}

int isFull(stack stack)
{
	if (stack.top < MAX_STACK_SIZE - 1) return 0;
	else return 1;
}

int push(stack* stackPtr, char ch)
{
	if (isFull(*stackPtr)) return 0;
	else stackPtr->value[++(stackPtr->top)] = ch; return 1;
}

char pop(stack* stackPtr)
{
	char popch;
	if (isEmpty(*stackPtr)) return NULL;
	else {
		popch = stackPtr->value[stackPtr->top];
		stackPtr->value[stackPtr->top--] = NULL;
		return popch;
	}
}

int main(void)
{
	int idx = 0;
	stack stack = createStack();
	char str[MAX_STACK_SIZE];

	printf("문자열 입력(영어만 치세요): ");
	gets(str);
	printf("\n거꾸로 문자열 출력: ");
	while (str[idx] && push(&stack, str[idx++]));
	while (isEmpty(stack) == 0){printf("%c", pop(&stack));}
	printf("\n\n");

	return 0;
}