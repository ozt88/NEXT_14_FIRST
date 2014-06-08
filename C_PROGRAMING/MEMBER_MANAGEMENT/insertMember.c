#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//���ο� ȸ���� �߰��ϴ� �Լ�

int insertMember(userInfo_t** userInfoArr, int* top, int* capacity)
{
	char buffer[BUFFERSIZE] = { 0, };

	if (!userInfoArr) return -1;

	*userInfoArr = checkCapacity(*userInfoArr, *top, capacity);

	system("cls");
	printf("=============================================================================\n");
	printf("%40s\n", "ȸ�� ���");
	printf("=============================================================================\n");

	printf("\tȸ�� ID: %d\n", ((*userInfoArr)[*top - 1].userId) + 1);
	(*userInfoArr)[*top].userId = ((*userInfoArr)[*top - 1].userId) + 1;

	getUserName((*userInfoArr)[*top].userName);
	getUserAddress((*userInfoArr)[*top].userAddress);
	getPhoneNumber((*userInfoArr)[*top].phone);

	printf("\t��� �Ϸ�");
	fflush(stdin);
	getchar();

	(*userInfoArr)[++*top].userId = (*userInfoArr)[*top - 1].userId + 1;

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

//����ü �迭�� �޸� �뷮�� Ȯ���غ��� �뷮�� �����ϸ� 2�����ִ� �Լ�

userInfo_t* checkCapacity(userInfo_t* userInfoArr, int top, int* capacity)
{
	if (top + 1 >= *capacity)
	{
		while (top + 1 >= *capacity){ *capacity *= 2; }
		userInfoArr = realloc(userInfoArr, sizeof(userInfo_t)*(*capacity));
	}

	return userInfoArr;
}

//��Ʈ������ �������� ���� ���縦 �ϴ� �Լ�

int strcpyWithoutNewline(char* copyer, char* copyee)
{


	if (!copyee||!copyer)
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
