
//�ǽ� ���� (4)
//Inorder traveral�� ��� ����� data ��� �Լ� ����
//Recursive function���� ����
//testTreeWithInorder() �Լ��� ȣ���ؼ� �̹� ������� �Ʒ� �׸��� ��� data���� ���ʷ� ���
//��� ��� : A / B * C * D + E


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