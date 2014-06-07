
//실습 주제 (5)
//Preorder traveral로 모든 노드의 data 출력 함수 구현
//Recursive function으로 구현
//testTreeWithPreorder() 함수를 호출해서 이미 만들어진 아래 그림의 노드 data들을 차례로 출력
//출력 결과 : +** / A B C D E


#include<stdio.h>
#include"tree.h"


int testTreeWithPreorder(tree_t* tree)
{
	if (!tree)
	{
		return -1;
	}

	printf("\n\nPREORDER PRINT\n\n");
	preorderPrint(tree->root);

	return 0;
}


int preorderPrint(node_t* node)
{
	if (!node)
	{
		return -1;
	}

	printf("%3c", node->value);
	preorderPrint(node->leftChild);
	preorderPrint(node->rightChild);

	return 0;
}