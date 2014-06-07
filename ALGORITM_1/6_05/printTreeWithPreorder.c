
//�ǽ� ���� (5)
//Preorder traveral�� ��� ����� data ��� �Լ� ����
//Recursive function���� ����
//testTreeWithPreorder() �Լ��� ȣ���ؼ� �̹� ������� �Ʒ� �׸��� ��� data���� ���ʷ� ���
//��� ��� : +** / A B C D E


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