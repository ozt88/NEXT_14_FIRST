
//실습 주제 (6)
//Postorder traveral로 모든 노드의 data 출력 함수 구현
//Recursive function으로 구현
//testTreeWithPostorder() 함수를 호출해서 이미 만들어진 아래 그림의 노드 data들을 차례로 출력
//출력 결과 : A B / C * D * E +

#include<stdio.h>
#include"tree.h"

int testTreeWithPostorder(tree_t* tree)
{
	if (!tree)
	{
		return -1;
	}

	printf("\n\nPOSTORDER PRINT\n\n");
	postorderPrint(tree->root);

	return 0;
}


int postorderPrint(node_t* node)
{
	if (!node)
	{
		return -1;
	}

	postorderPrint(node->leftChild);
	postorderPrint(node->rightChild);
	printf("%3c", node->value);

	return 0;
}