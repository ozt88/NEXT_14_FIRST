#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"

//실습 주제 16
//삭제하는 함수 테스트
//트리와 키값을 인자로 받아서 키값을 가진 해당 노드 삭제

int testDeleteInBST(tree_t* tree, int key)
{
	node_t* testNode;
	if (!tree || !key)
	{
		return -1;
	}
	
	testNode = searchBSTbyKey(tree, key);
	deleteInBST(tree, testNode);
	testBSTWithInorder(tree);
	
	return 0;
}

//void  void bstDeleteNode(tree_t * tree, node_t * node) 함수 구현
//직전노드와 직후노드의 공정성을 고려한 내용을 추가

int deleteInBST(tree_t* tree, node_t* delNode)
{
	node_t* successor;

	if (!tree || !delNode)
	{
		return -1;
	}
	//왼쪽자식이 없는 경우, 둘다 없는 경우 모두 포함한다.
	//이식 함수에서 오른쪽 자식이 없는 경우도 예외처리를 해주었기 때문에 무관하다.
	//오른쪽 자식을 삭제 노드에 이식하면 삭제 성공
	if (!delNode->leftChild)
	{
		transplantInBST(tree, delNode, delNode->rightChild);
	}
	//오른쪽 자식만 없는 경우
	//왼쪽 자식을 삭제노드에 이식하면 성공
	else if (!delNode->rightChild)
	{
		transplantInBST(tree, delNode, delNode->leftChild);
	}

	//자식이 둘다 없는경우
	//본래 직후노드만 고려해서 삭제를 했는데
	//직후노드와 직전노드 모두를 고려하면 좀더 효율적인 삭제 함수를 만들 수 있다.
	//연산횟수가 줄어드는 경우는 삭제 노드의 왼쪽, 오른쪽 자식이 그것의 직전, 직후값일때
	//이식되는 노드의 자식을 다시 이식해주는 연산을 줄여줄 수 있다.
	//따라서 왼쪽과 오른쪽중에 자신의 직전, 직후값이 있는 경우를 먼저 탐색한뒤에 
	//삭제를 하는 것이 효과적이다.
	//그렇지 않은 경우 연산횟수가 차이가 없으므로 그냥 오른쪽 자식을 선택한다.
	//이렇게해서 왼쪽 오른쪽 모두에게 공정한 삭제함수를 만들 수 있다.
	else
	{
		//왼쪽 자식이 삭제노드의 직전노드인 경우
		//왼쪽 자식을 삭제노드에 이식하고 오른쪽을 연결해주면 성공.
		if (!delNode->leftChild->rightChild)
		{
			successor = delNode->leftChild;
			transplantInBST(tree, delNode, successor);
			successor->rightChild = delNode->rightChild;
			successor->rightChild->parent = successor;
		}
		//오른쪽 자식이 삭제노드의 직후노드인 경우
		//오른쪽 자식을 삭제노드에 이식하고 왼쪽을 연결해주면 성공.
		else if (!delNode->rightChild->leftChild)
		{
			successor = delNode->rightChild;
			transplantInBST(tree, delNode, successor);
			successor->leftChild = delNode->leftChild;
			successor->leftChild->parent = successor;
		}
		else{
			successor = findMinInBSTWithNode(delNode->rightChild);
			transplantInBST(tree, successor, successor->rightChild);
			successor->rightChild = delNode->rightChild;
			delNode->rightChild->parent = successor;
			transplantInBST(tree, delNode, successor);
			successor->leftChild = delNode->leftChild;
			successor->leftChild->parent = successor;
		}
	}

	
	return 0;
}