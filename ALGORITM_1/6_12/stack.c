#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"

//스택에 사용되는 함수들

stack_t* makeStack(void)
{
	stack_t* newStack = (stack_t*)malloc(sizeof(stack_t));
	memset(newStack, 0, sizeof(stack_t));
	return newStack;
}

stackNode_t* makeStackNode(void)
{
	stackNode_t* newStackNode = (stackNode_t*)malloc(sizeof(stackNode_t));
	memset(newStackNode, 0, sizeof(stackNode_t));
	return newStackNode;
}

int stackPush(stack_t* stack, node_t* node)
{
	stackNode_t* newStackNode;

	if (!stack || !node)
	{
		return -1;
	}
	newStackNode = makeStackNode();
	newStackNode->data = node;
	if (stack->top)
	{
		newStackNode->next = stack->top;
	}
	stack->top = newStackNode;

	return 0;
}

node_t* stackPop(stack_t* stack)
{
	node_t* popNode;
	stackNode_t* delStackNode;

	if(!stack || !stack->top)
	{
		return (node_t*)NULL;
	}
	delStackNode = stack->top;
	stack->top = delStackNode->next;
	popNode = delStackNode->data;
	free(delStackNode);

	return popNode;
}