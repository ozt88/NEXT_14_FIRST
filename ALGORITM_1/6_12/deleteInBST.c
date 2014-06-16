#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"

//�ǽ� ���� 16
//�����ϴ� �Լ� �׽�Ʈ
//Ʈ���� Ű���� ���ڷ� �޾Ƽ� Ű���� ���� �ش� ��� ����

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

//void  void bstDeleteNode(tree_t * tree, node_t * node) �Լ� ����
//�������� ���ĳ���� �������� ����� ������ �߰�

int deleteInBST(tree_t* tree, node_t* delNode)
{
	node_t* successor;

	if (!tree || !delNode)
	{
		return -1;
	}
	//�����ڽ��� ���� ���, �Ѵ� ���� ��� ��� �����Ѵ�.
	//�̽� �Լ����� ������ �ڽ��� ���� ��쵵 ����ó���� ���־��� ������ �����ϴ�.
	//������ �ڽ��� ���� ��忡 �̽��ϸ� ���� ����
	if (!delNode->leftChild)
	{
		transplantInBST(tree, delNode, delNode->rightChild);
	}
	//������ �ڽĸ� ���� ���
	//���� �ڽ��� ������忡 �̽��ϸ� ����
	else if (!delNode->rightChild)
	{
		transplantInBST(tree, delNode, delNode->leftChild);
	}

	//�ڽ��� �Ѵ� ���°��
	//���� ���ĳ�常 ����ؼ� ������ �ߴµ�
	//���ĳ��� ������� ��θ� ����ϸ� ���� ȿ������ ���� �Լ��� ���� �� �ִ�.
	//����Ƚ���� �پ��� ���� ���� ����� ����, ������ �ڽ��� �װ��� ����, ���İ��϶�
	//�̽ĵǴ� ����� �ڽ��� �ٽ� �̽����ִ� ������ �ٿ��� �� �ִ�.
	//���� ���ʰ� �������߿� �ڽ��� ����, ���İ��� �ִ� ��츦 ���� Ž���ѵڿ� 
	//������ �ϴ� ���� ȿ�����̴�.
	//�׷��� ���� ��� ����Ƚ���� ���̰� �����Ƿ� �׳� ������ �ڽ��� �����Ѵ�.
	//�̷����ؼ� ���� ������ ��ο��� ������ �����Լ��� ���� �� �ִ�.
	else
	{
		//���� �ڽ��� ��������� ��������� ���
		//���� �ڽ��� ������忡 �̽��ϰ� �������� �������ָ� ����.
		if (!delNode->leftChild->rightChild)
		{
			successor = delNode->leftChild;
			transplantInBST(tree, delNode, successor);
			successor->rightChild = delNode->rightChild;
			successor->rightChild->parent = successor;
		}
		//������ �ڽ��� ��������� ���ĳ���� ���
		//������ �ڽ��� ������忡 �̽��ϰ� ������ �������ָ� ����.
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