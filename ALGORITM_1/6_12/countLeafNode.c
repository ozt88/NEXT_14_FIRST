#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"BST.h"

//#15.C2 �������� 5.4 1��
//��带 �Է��ϸ� �� ��带 ��Ʈ�� �ϴ� ����Ʈ���� ���� ����� ������ �����ϴ� �Լ�
//������ ����ϴ��� ���� ���� ���ؼ� ���� Ŀ�ٶ� BST ����� �Լ�
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

//������� ���� ���� �Լ��� ���Ŀ� �°� �׽�Ʈ 
//�ð��������� �߰�

int testCountLeafNode(tree_t* tree)
{
	double runTime;
	time_t startTime = 0, endTime = 0;
	if (!tree)
	{
		return -1;
	}

	startTime = clock();
	printf("��������� ������ %d�� �Դϴ�.\n", countLeafNode(tree->root));
	endTime = clock();
	runTime = (double)(endTime - startTime)/(CLOCKS_PER_SEC);
	printf("�ɸ� �ð� : %g ��\n", runTime);

	return 0;
}

//��带 ���ڷ� �޾Ƽ� ���ýú��ϰ� ������� ������ Ȯ��
//���� ����Ʈ���� ������� ���� + ������ ����Ʈ���� ������� ����

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