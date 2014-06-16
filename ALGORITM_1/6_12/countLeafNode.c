#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"BST.h"

//#15.C2 연습문제 5.4 1번
//노드를 입력하면 그 노드를 루트로 하는 서브트리의 리프 노드의 갯수를 리턴하는 함수
//리프를 출력하는지 재대로 보기 위해서 만든 커다란 BST 만드는 함수
tree_t* makeBigBST(void)
{
	tree_t* newTree = makeTree();
	node_t* nodeArr[BIG_NUM];
	srand(time(NULL));

	for (int i = 0; i < BIG_NUM; i++)
	{
		nodeArr[i] = makeNode();
		nodeArr[i]->data = rand() % BIG_NUM;
		bstInsertNode(newTree, nodeArr[i]);
	}

	return newTree;
}

//리프노드 갯수 새는 함수를 형식에 맞게 테스트 
//시간측정까지 추가

int testCountLeafNode(tree_t* tree)
{
	double runTime;
	time_t startTime = 0, endTime = 0;
	if (!tree)
	{
		return -1;
	}

	startTime = clock();
	printf("리프노드의 갯수는 %d개 입니다.\n", countLeafNode(tree->root));
	endTime = clock();
	runTime = (double)(endTime - startTime)/(CLOCKS_PER_SEC);
	printf("걸린 시간 : %g 초\n", runTime);

	return 0;
}

//노드를 인자로 받아서 리컬시브하게 리프노드 갯수를 확인
//왼쪽 서브트리의 리프노드 갯수 + 오른쪽 서브트리의 리프노드 갯수

int countLeafNode(node_t* node)
{
	int count;

	if (!node)
	{
		count = 0;
	}
	else if (!node->leftChild && !node->rightChild)
	{
		count = 1;
	}
	else
	{
		count =  countLeafNode(node->leftChild) + countLeafNode(node->rightChild);
	}

	return count;
}