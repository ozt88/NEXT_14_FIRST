#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"

//#15.C4 5.4 2번문제
//트리를 입력받아서 모든 노드의 왼쪽 자식과 오른쪽 자식을 교환하는 함수

//왼쪽 오른쪽 교환하는 함수 테스트
//트리를 인자로 받아서 스왑을 실행하고 출력

int testSwapTree(tree_t* tree)
{
	if (!tree)
	{
		return -1;
	}

	printf("Before Swap\n");
	testBSTWithInorder(tree);
	swapTreeWithNode(tree->root);
	printf("After Swap\n");
	testBSTWithInorder(tree);

	return 0;
}
int swapTreeWithNode(node_t* node)
{
	node_t* temp;
	if (!node)
	{
		return 0;
	}

	temp = node->rightChild;
	node->rightChild = node->leftChild;
	node->leftChild = temp;
	
	swapTreeWithNode(node->leftChild);
	swapTreeWithNode(node->rightChild);

	return 0;
}