#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

// ȸ���� ���̵�, �̸�, �ּ� , ��ȭ��ȣ�� �˻��ϴ� �Լ�
// ȸ�� ���̵� ����

node_t* findMember(tree_t* userInfoTree, char* str)
{
	char inputStr[BUFFERSIZE] = { 0, };
	int idx = 0;
	int input = 0;
	node_t* resultNodeArr[BUFFERSIZE] = { 0, };
	
	if (!userInfoTree)
	{
		return -1;
	}

	while (1)
	{
		system("cls");
		printf("=============================================================================\n");
		printf("%34s�� %s\t\n", str, "ȸ�� �˻�");
		printf("=============================================================================\n");
		printf("\n\t%3s", "1. ID�� �˻�\n");
		printf("\n\t%3s", "2. �̸����� �˻�\n");
		printf("\n\t%3s", "3. �ּҷ� �˻�\n");
		printf("\n\t%3s", "4. ��ȭ ��ȣ�� �˻�\n");
		printf("\n\t%3s", "0. ����\n");
		printf("\n\t������ ��ȣ�� �Է��ϼ���: ");
		scanf_s("\n%d", &input);

		switch (input)
		{
		case 1:
			getUserId(inputStr);
			//ID�� �Ѱ��� �����Ƿ� �ٷ� Ű��ó�� �˻��ؼ� ����
			resultNodeArr[idx] = searchBSTbyUserIdWithNode(userInfoTree->root, atoi(inputStr));
			break;
		case 2:
			getUserName(inputStr);
			searchBSTbyNameWithNode(userInfoTree->root, inputStr, resultNodeArr, &idx);
			break;
		case 3:
			getUserAddress(inputStr);
			searchBSTbyAddressWithNode(userInfoTree->root, inputStr, resultNodeArr, &idx);
			break;
		case 4:
			getPhoneNumber(inputStr);
			searchBSTbyPhoneWithNode(userInfoTree->root, inputStr, resultNodeArr, &idx);
			break;
		case 0:
			return (node_t*)NULL;
		default:
			break;
		}
		printArrData(resultNodeArr, inputStr);
		return selectNode(resultNodeArr);
	}
}

//�̸����� �˻� inorder�� ������ üũ�ϸ鼭 ��ġ�ϴ��� Ȯ��
void searchBSTbyNameWithNode(node_t* node, char* str, node_t* resultNodeArr[BUFFERSIZE], int* idx)
{
	if (!node)
	{
		return;
	}

	searchBSTbyNameWithNode(node->leftChild, str, resultNodeArr, idx);
	if (!strcmp(node->data.userName, str))
	{
		resultNodeArr[(*idx)++] = node;
	}
	searchBSTbyNameWithNode(node->rightChild, str, resultNodeArr, idx);
	
	return;
}

//�ּҷ� �˻�
void searchBSTbyAddressWithNode(node_t* node, char* str, node_t* resultNodeArr[BUFFERSIZE], int* idx)
{
	if (!node)
	{
		return;
	}

	searchBSTbyAddressWithNode(node->leftChild, str, resultNodeArr, idx);
	if (!strcmp(node->data.userAddress, str))
	{
		resultNodeArr[(*idx)++] = node;
	}
	searchBSTbyAddressWithNode(node->rightChild, str, resultNodeArr, idx);

	return;
}

//�ڵ��� ��ȣ�� �˻�
void searchBSTbyPhoneWithNode(node_t* node, char* str, node_t* resultNodeArr[BUFFERSIZE], int* idx)
{
	if (!node)
	{
		return;
	}

	searchBSTbyPhoneWithNode(node->leftChild, str, resultNodeArr, idx);
	if (!strcmp(node->data.phone, str))
	{
		resultNodeArr[(*idx)++] = node;
	}
	searchBSTbyPhoneWithNode(node->rightChild, str, resultNodeArr, idx);

	return;
}

//�˻��� ����� �迭�� �����ϰ� �װ͵��� �����.
void printArrData(node_t* resultNodeArr[BUFFERSIZE], char* Query)
{
	system("cls");
	printf("�˻��� : %s\n", Query);
	printf("[No.]%10s\t%10s\t%-30s\t%-10s\n", "ȸ��ID", "ȸ���̸�", "ȸ���ּ�", "����ó");
	printf("=============================================================================\n");
	for (int i = 0; i < BUFFERSIZE; i++)
	{
		if (!resultNodeArr[i])
		{
			break;
		}
		printf("[%d]%12d\t%8s\t%-30s\t%10s\n", i, resultNodeArr[i]->data.userId, resultNodeArr[i]->data.userName, resultNodeArr[i]->data.userAddress, resultNodeArr[i]->data.phone);
	}
	printf("=============================================================================\n");
	return;
}

//�迭�� ����� �����߿� �ϳ��� ����
node_t* selectNode(node_t* resultNodeArr[BUFFERSIZE])
{
	int input = 0;

	if (!resultNodeArr[0])
	{
		printf("\n\t�˻� ����!\n");
		fflush(stdin);
		getchar();
		return (node_t*)NULL;

	}

	do
	{
		printf("\n\t���ϴ� ȸ�������� ��ȣ[No.]�� �Է��ϼ��� :");
		fflush(stdin);
		scanf("%d", &input);
	} while (!resultNodeArr[input]);
	return resultNodeArr[input];
}