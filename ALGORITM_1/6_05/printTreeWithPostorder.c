
//�ǽ� ���� (6)
//Postorder traveral�� ��� ����� data ��� �Լ� ����
//Recursive function���� ����
//testTreeWithPostorder() �Լ��� ȣ���ؼ� �̹� ������� �Ʒ� �׸��� ��� data���� ���ʷ� ���
//��� ��� : A B / C * D * E +

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