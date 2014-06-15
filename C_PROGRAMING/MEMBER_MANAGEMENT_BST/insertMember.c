#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//���ο� ȸ���� �߰��ϴ� �Լ�

int insertMember(tree_t* userInfoTree)
{
	char buffer[BUFFERSIZE] = { 0, };
	node_t* newMember;
	int input = 0;
	if (!userInfoTree)
	{
		return -1;
	}
	newMember = makeNode();

	system("cls");
	printf("=============================================================================\n");
	printf("%40s\n", "ȸ�� ���");
	printf("=============================================================================\n");

	printf("\tȸ�� ID: %d\n", findMaxInBSTWithNode(userInfoTree->root)->data.userId + 1);
	newMember->data.userId = findMaxInBSTWithNode(userInfoTree->root)->data.userId + 1;
	getUserName(newMember->data.userName);
	getUserAddress(newMember->data.userAddress);
	getPhoneNumber(newMember->data.phone);

	input = getYesOrNo("�̴�� ����Ͻðڽ��ϱ�?(Y/N): ");
	if (input)
	{
		bstInsertNode(userInfoTree, newMember);
		printf("\t��� �Ϸ�");
		fflush(stdin);
		getchar();
	}
	else
	{
		free(newMember);
		printf("\t��ҵǾ����ϴ�.");
		fflush(stdin);
		getchar();
	}
	return 0;
}

int getUserId(char* subject)
{
	char buffer[BUFFERSIZE] = { 0, };
	if (!subject)
	{
		return -1;
	}
	printf("\tȸ�� ID �Է�: ");
	fflush(stdin);
	fgets(buffer, sizeof(char)*IDSIZE, stdin);
	strcpyWithoutNewline(subject, buffer);

	return 0;
}
//�̸��� �Է¹޴� �Լ�

int getUserName(char* subject)
{
	char buffer[BUFFERSIZE] = { 0, };
	if (!subject)
	{
		return -1;
	}
	printf("\tȸ�� �̸� �Է�: ");
	fflush(stdin);
	fgets(buffer, sizeof(char)*NAMESIZE, stdin);
	strcpyWithoutNewline(subject, buffer);

	return 0;
}

//�ּҸ� �Է¹޴� �Լ�

int getUserAddress(char* subject)
{
	char buffer[BUFFERSIZE] = { 0, };
	if (!subject)
	{
		return -1;
	}
	printf("\tȸ�� �ּ� �Է�: ");
	fflush(stdin);
	fgets(buffer, sizeof(char)*ADDRESSSIZE, stdin);
	strcpyWithoutNewline(subject, buffer);

	return 0;
}

//��ȭ��ȣ�� �Է¹޴� �Լ�

int getPhoneNumber(char* subject)
{
	char buffer[BUFFERSIZE] = { 0, };

	while (1)
	{
		printf("\tȸ�� ����ó �Է�: ");
		fflush(stdin);
		gets(buffer);
		if (!isPhoneNumber(buffer) || strlen(buffer) != 13)
		{
			printf("\n\t���Ŀ� ���� ���ڸ� �Է����ּ���!\n\t����)010-1234-1234\n\n");
			continue;
		}
		else
		{
			break;
		}
	}

	strcpyWithoutNewline(subject, buffer);
	return 0;
}

//��Ʈ������ �������� ���� ���縦 �ϴ� �Լ�

int strcpyWithoutNewline(char* copyer, char* copyee)
{
	if (!copyee || !copyer)
	{
		return -1;
	}

	while (*copyee != '\n' && *copyee != '\0')
	{
		*(copyer++) = *(copyee++);
	}

	*copyer = '\0';

	return 0;
}

//��ȭ��ȣ�� �´��� Ȯ���ϴ� �Լ�

int isPhoneNumber(char* str)
{
	while (*str != '\0')
	{
		if (('0' > *str || *str > '9') && *str != '-') return 0;
		str++;
	}
	return 1;
}

//YES or No �Է¹޴� �Լ�

int getYesOrNo(char* str)
{
	char inputc = 0;
	int result;
	while (1)
	{
		printf("\n\t%s", str);
		fflush(stdin);
		scanf_s("%c", &inputc);
		if (inputc == 'Y' || inputc == 'y')
		{
			result = 1;
			break;
		}
		else if (inputc == 'N' || inputc == 'n')
		{
			result = 0;
			break;
		}
	}
	return result;
}