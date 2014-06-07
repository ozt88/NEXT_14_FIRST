
//실습 주제 (4)
//Inorder traveral로 모든 노드의 data 출력 함수 구현
//Recursive function으로 구현
//testTreeWithInorder() 함수를 호출해서 이미 만들어진 아래 그림의 노드 data들을 차례로 출력
//출력 결과 : A / B * C * D + E


#include<stdio.h>
#include"tree.h"


int testTreeWithInorder(tree_t* tree)
{
	if (!tree)
	{
		return -1;
	}

	printf("\n\nINORDER PRINT\n\n");
	inorderPrint(tree->root);

	return 0;
}


int inorderPrint(node_t* node)
{
	if (!node)
	{
		return -1;
	}

	inorderPrint(node->leftChild);
	printf("%3c", node->value);
	inorderPrint(node->rightChild);

	return 0;
}