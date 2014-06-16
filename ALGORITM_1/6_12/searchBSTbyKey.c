#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"



//실습주제 10


//아래의 함수를 테스트
//3번처럼 출력
int testSearchBSTbyKey(tree_t* BST, int key)
{
	node_t* resultNode;

	if (!BST)
	{
		return -1;
	}

	resultNode = searchBSTbyKey(BST, key);
	testBSTlikeNo3(resultNode);

	return 0;
}


//node_t * bstSearch(node_t *node, int key) 함수 구현
//저장한 data, parent의 주소, parent에 저장된 data, 
//leftChild의 주소, left child에 저장된 data, 
//right child의 주소, right child에 저장된 data 출력

node_t* searchBSTbyKey(tree_t* BST, int key)
{
	if (!BST || !key)
	{
		return (node_t*)NULL;
	}

	return searchBSTbyKeyWithNode(BST->root, key);
}

node_t* searchBSTbyKeyWithNode(node_t* currentNode, int key)
{
	if (!currentNode || !key)
	{
		return (node_t*)NULL;
	}

	if (key == currentNode->data)
	{
		return currentNode;
	}
	else if (key < currentNode->data)
	{
		return searchBSTbyKeyWithNode(currentNode->leftChild, key);
	}
	else
	{
		return searchBSTbyKeyWithNode(currentNode->rightChild, key);
	}
}