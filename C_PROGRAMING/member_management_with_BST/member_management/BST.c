#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//노드 삽입
int bstInsertNode(tree_t* tree, node_t* givenNode)
{
	node_t* currentNode;
	node_t* parentNode;
	if (!tree || !givenNode)
	{
		return -1;
	}

	currentNode = tree->root;
	parentNode = (node_t*)NULL;

	while (currentNode)
	{
		parentNode = currentNode;
		if (currentNode->data.userId > currentNode->data.userId)
		{
			currentNode = currentNode->leftChild;
		}
		else
		{
			currentNode = currentNode->rightChild;
		}
	}

	givenNode->parent = parentNode;

	if (!parentNode)
	{
		tree->root = givenNode;
	}
	else if (givenNode->data.userId < parentNode->data.userId)
	{
		parentNode->leftChild = givenNode;
	}
	else
	{
		parentNode->rightChild = givenNode;
	}


	return 0;
}

//노드 삭제 - 삭제할때 웬만하면 Free하자.
int deleteInBST(tree_t* tree, node_t* delNode)
{
	node_t* successor;

	if (!tree || !delNode)
	{
		return -1;
	}

	if (!delNode->leftChild)
	{
		transplantInBST(tree, delNode, delNode->rightChild);
	}
	else if (!delNode->rightChild)
	{
		transplantInBST(tree, delNode, delNode->leftChild);
	}
	else
	{
		successor = findMinInBSTWithNode(delNode->rightChild);
		if (successor != delNode->rightChild)
		{
			transplantInBST(tree, successor, successor->rightChild);
			successor->rightChild = delNode->rightChild;
			delNode->rightChild->parent = successor;
		}
		transplantInBST(tree, delNode, successor);
		successor->leftChild = delNode->leftChild;
		successor->leftChild->parent = successor;
	}

	if (delNode)
	{
		free(delNode);
	}
	return 0;
}

//최소값을 찾는 함수
node_t* findMinInBSTWithNode(node_t* currentNode)
{
	if (!currentNode)
	{
		return (node_t*)NULL;
	}

	else if (!currentNode->leftChild)
	{
		return currentNode;
	}

	else
	{
		return findMinInBSTWithNode(currentNode->leftChild);
	}
}

//최대값을 찾는 함수 - 나중에 회원등록시 Id생성할때 쓰인다.
node_t* findMaxInBSTWithNode(node_t* currentNode)
{
	if (!currentNode)
	{
		return (node_t*)NULL;
	}

	else if (!currentNode->rightChild)
	{
		return currentNode;
	}

	else
	{
		return findMaxInBSTWithNode(currentNode->rightChild);
	}
}

//ID를 입력해서 노드를 찾는함수
node_t* searchBSTbyUserIdWithNode(node_t* currentNode, int userId)
{
	if (!currentNode || !userId)
	{
		return (node_t*)NULL;
	}

	if (userId == currentNode->data.userId)
	{
		return currentNode;
	}
	else if (userId < currentNode->data.userId)
	{
		return searchBSTbyUserIdWithNode(currentNode->leftChild, userId);
	}
	else
	{
		return searchBSTbyUserIdWithNode(currentNode->rightChild, userId);
	}
}

//이식하는 함수, 삭제를 편하게!
int transplantInBST(tree_t* tree, node_t* deNode, node_t* newNode)
{
	if (!tree || !deNode)
	{
		return -1;
	}

	if (!deNode->parent)
	{
		tree->root = newNode;
	}
	else if (deNode->parent->leftChild == deNode)
	{
		deNode->parent->leftChild = newNode;
	}
	else
	{
		deNode->parent->rightChild = newNode;
	}

	if (newNode)
	{
		newNode->parent = deNode->parent;
	}

	return 0;
}

//free를 편하게 해주는 함수. 
//루트를 입력하면 그 트리의 노드가 모두 프리
void clearTreeWithNode(node_t* node)
{
	if (!node)
	{
		return;
	}

	if (!node->leftChild && !node->rightChild)
	{
		free(node);
		return;
	}
	clearTreeWithNode(node->rightChild);
	clearTreeWithNode(node->leftChild);

	return;
}

node_t* makeNode(void)
{
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	memset(newNode, 0, sizeof(node_t));
	return newNode;
}

tree_t* makeTree(void)
{
	tree_t* newTree = (tree_t*)malloc(sizeof(tree_t));
	memset(newTree, 0, sizeof(tree_t));
	return newTree;
}