#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"

//inorder, preorder, postorder를 이터레이티브하게; 스택을 사용해서 구현하는 함수들
//#15.C6
int inorderPrintWithStack(tree_t* tree)
{
	stack_t* stack;
	node_t* currentNode;
	if (!tree)
	{
		return -1;
	}
	stack = makeStack();
	currentNode = tree->root;

	while (1)
	{
		while(currentNode)
		{
			stackPush(stack, currentNode);
			currentNode = currentNode->leftChild;
		}
		currentNode = stackPop(stack);
		if (!currentNode)
		{
			break;
		}
		printf("%3d", currentNode->data);
		currentNode = currentNode->rightChild;
	}
	printf("\n");
	return 0;
}

//#15.C7
int preorderPrintWithStack(tree_t* tree)
{
	stack_t* stack;
	node_t* currentNode;
	if (!tree)
	{
		return -1;
	}
	stack = makeStack();
	currentNode = tree->root;

	while (1)
	{
		while (currentNode)
		{
			printf("%3d", currentNode->data);
			stackPush(stack, currentNode);
			currentNode = currentNode->leftChild;
		}
		currentNode = stackPop(stack);
		if (!currentNode)
		{
			break;
		}
		currentNode = currentNode->rightChild;
	}
	printf("\n");

	return 0;
}

//#15.C8
int postorderPrintWithStack(tree_t* tree)
{
	stack_t* stack;
	stack_t* subStack;
	node_t* currentNode;
	node_t* prevNode;
	if (!tree)
	{
		return -1;
	}
	stack = makeStack();
	currentNode = tree->root;
	prevNode = (node_t*)NULL;
	stackPush(stack, currentNode);
	while (stack->top)
	{
		//내려가는 경우
		if (!prevNode || currentNode->parent == prevNode)
		{
			if (currentNode->leftChild)
			{
				prevNode = currentNode;
				currentNode = currentNode->leftChild;
				stackPush(stack, currentNode);
			}
			else if (currentNode->rightChild)
			{
				prevNode = currentNode;
				currentNode = currentNode->rightChild;
				stackPush(stack, currentNode);
			}
			else
			{
				printf("%3d", currentNode->data);
				prevNode = currentNode;
				stackPop(stack);
				currentNode = stack->top->data;
			}
		}

		//이전에 올라간 경우1 ->이전 노드가 커런트의 왼쪽 자식
		else if (currentNode->leftChild == prevNode)
		{
			if (currentNode->rightChild)
			{
				prevNode = currentNode;
				currentNode = currentNode->rightChild;
				stackPush(stack, currentNode);
			}
			else
			{
				printf("%3d", currentNode->data);
				prevNode = currentNode;
				stackPop(stack);
				currentNode = stack->top->data;
			}
		}

		//이전에 올라간 경우2 ->이전 노드가 커런트의 오른쪽 자식
		else if (currentNode->rightChild == prevNode)
		{
			printf("%3d", currentNode->data);
			prevNode = currentNode;
			stackPop(stack);
			if (stack->top)
			{
				currentNode = stack->top->data;
			}
		}
	}
	printf("\n");

	return 0;
}