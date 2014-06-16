#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"

//inorder, preorder, postorder�� ���ͷ���Ƽ���ϰ�; ������ ����ؼ� �����ϴ� �Լ���
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
		//�������� ���
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

		//������ �ö� ���1 ->���� ��尡 Ŀ��Ʈ�� ���� �ڽ�
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

		//������ �ö� ���2 ->���� ��尡 Ŀ��Ʈ�� ������ �ڽ�
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