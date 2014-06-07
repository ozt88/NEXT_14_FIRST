
//실습 주제 (3)
//생성한 트리를 테스트하는 함수
//main()에서 makeSampleTree() 함수 호출해서 트리 생성
//Root로부터 링크를 따라서 각 노드를 접근
//각 노드에 대해서
//저장한 data, parent의 주소, parent에 저장된 data, leftChild의 주소, left child에 저장된 data, right child의 주소, right child에 저장된 data 출력

#include<stdio.h>
#include"tree.h"

int testSampleTree(tree_t* testTree)
{
	if (!testTree)
	{
		return -1;
	}
	printf("\n\nTEST TREE\n\n");
	printNode(testTree->root);

	return 0;
}

int printNode(node_t* node)
{
	if (!node)
	{
		return -1;
	}

	printf("%3c,\t", node->value);

	if (node->parent)
	{
		printf("%7p, %3c,\t", node->parent, node->parent->value);
	}
	else
	{
		printf("%7s, %3s,\t", "NULL", "없음");
	}

	if (node->leftChild)
	{
		printf("%7p, %3c,\t", node->leftChild, node->leftChild->value);
	}
	else
	{
		printf("%7s, %3s,\t", "NULL", "없음");
	}

	if (node->rightChild)
	{
		printf("%7p, %3c", node->rightChild, node->rightChild->value);
	}
	else
	{
		printf("%7s, %3s", "NULL", "없음");
	}
	printf("\n");

	printNode(node->leftChild);
	printNode(node->rightChild);

	return 0;
}