#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"

//#실습주제 9


//샘플 BST를 inorder로 출력하는 테스트
int testSampleBST(void)
{
	tree_t* sampleBST = makeSampleBST();
	testBSTWithInorder(sampleBST);
	return 0;
}

//노드 생성
node_t* makeNode(void)
{
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	memset(newNode, 0, sizeof(node_t));
	return newNode;
}

//트리 생성
tree_t* makeTree(void)
{
	tree_t* newTree = (tree_t*)malloc(sizeof(tree_t));
	memset(newTree, 0, sizeof(tree_t));
	return newTree;
}

//tree_t * makeSampleBST(void) 함수 구현
//tree 구조체 포인터 변수 1개 선언
//node 구조체 포인터 변수 9개 선언
//각 포인터 변수에 메모리 동적 할당
//그림의 연결 형태가 되도록 leftChild, rightChild, parent 값 등을 지정
//동적 할당한 tree_t 포인터 변수 return
tree_t* makeSampleBST(void)
{
	tree_t* sampleBST = makeTree();
	node_t* nodeArr[NODE_NUM];
	
	for (int i = 0; i < NODE_NUM; i++)
	{
		nodeArr[i] = makeNode();
	}

	sampleBST->root = nodeArr[0];


	nodeArr[0]->data = 12;
	nodeArr[0]->leftChild = nodeArr[1];
	nodeArr[0]->rightChild = nodeArr[2];
	nodeArr[0]->parent = (node_t*)NULL;

	nodeArr[1]->data = 5;
	nodeArr[1]->leftChild = nodeArr[3];
	nodeArr[1]->rightChild = nodeArr[4];
	nodeArr[1]->parent = nodeArr[0];

	nodeArr[2]->data = 18;
	nodeArr[2]->leftChild = nodeArr[5];
	nodeArr[2]->rightChild = nodeArr[6];
	nodeArr[2]->parent = nodeArr[0];

	nodeArr[3]->data = 2;
	nodeArr[3]->leftChild = (node_t*)NULL;
	nodeArr[3]->rightChild = (node_t*)NULL;
	nodeArr[3]->parent = nodeArr[1];

	nodeArr[4]->data = 9;
	nodeArr[4]->leftChild = (node_t*)NULL;
	nodeArr[4]->rightChild = (node_t*)NULL;
	nodeArr[4]->parent = nodeArr[1];

	nodeArr[5]->data = 15;
	nodeArr[5]->leftChild = nodeArr[7];
	nodeArr[5]->rightChild = nodeArr[8];
	nodeArr[5]->parent = nodeArr[2];

	nodeArr[6]->data = 19;
	nodeArr[6]->leftChild = (node_t*)NULL;
	nodeArr[6]->rightChild = (node_t*)NULL;
	nodeArr[6]->parent = nodeArr[2];

	nodeArr[7]->data = 13;
	nodeArr[7]->leftChild = (node_t*)NULL;
	nodeArr[7]->rightChild = (node_t*)NULL;
	nodeArr[7]->parent = nodeArr[5];

	nodeArr[8]->data = 17;
	nodeArr[8]->leftChild = (node_t*)NULL;
	nodeArr[8]->rightChild = (node_t*)NULL;
	nodeArr[8]->parent = nodeArr[5];

	return sampleBST;
}