#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//새로운 회원을 추가하는 함수

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
	printf("%40s\n", "회원 등록");
	printf("=============================================================================\n");

	printf("\t회원 ID: %d\n", findMaxInBSTWithNode(userInfoTree->root)->data.userId + 1);
	newMember->data.userId = findMaxInBSTWithNode(userInfoTree->root)->data.userId + 1;
	getUserName(newMember->data.userName);
	getUserAddress(newMember->data.userAddress);
	getPhoneNumber(newMember->data.phone);

	input = getYesOrNo("이대로 등록하시겠습니까?(Y/N): ");
	if (input)
	{
		bstInsertNode(userInfoTree, newMember);
		printf("\t등록 완료");
		fflush(stdin);
		getchar();
	}
	else
	{
		free(newMember);
		printf("\t취소되었습니다.");
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
	printf("\t회원 ID 입력: ");
	fflush(stdin);
	fgets(buffer, sizeof(char)*IDSIZE, stdin);
	strcpyWithoutNewline(subject, buffer);

	return 0;
}
//이름을 입력받는 함수

int getUserName(char* subject)
{
	char buffer[BUFFERSIZE] = { 0, };
	if (!subject)
	{
		return -1;
	}
	printf("\t회원 이름 입력: ");
	fflush(stdin);
	fgets(buffer, sizeof(char)*NAMESIZE, stdin);
	strcpyWithoutNewline(subject, buffer);

	return 0;
}

//주소를 입력받는 함수

int getUserAddress(char* subject)
{
	char buffer[BUFFERSIZE] = { 0, };
	if (!subject)
	{
		return -1;
	}
	printf("\t회원 주소 입력: ");
	fflush(stdin);
	fgets(buffer, sizeof(char)*ADDRESSSIZE, stdin);
	strcpyWithoutNewline(subject, buffer);

	return 0;
}

//전화번호를 입력받는 함수

int getPhoneNumber(char* subject)
{
	char buffer[BUFFERSIZE] = { 0, };

	while (1)
	{
		printf("\t회원 연락처 입력: ");
		fflush(stdin);
		gets(buffer);
		if (!isPhoneNumber(buffer) || strlen(buffer) != 13)
		{
			printf("\n\t형식에 맞춰 숫자를 입력해주세요!\n\t예시)010-1234-1234\n\n");
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

//스트링에서 뉴라인을 빼고 복사를 하는 함수

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

//전화번호가 맞는지 확인하는 함수

int isPhoneNumber(char* str)
{
	while (*str != '\0')
	{
		if (('0' > *str || *str > '9') && *str != '-') return 0;
		str++;
	}
	return 1;
}

//YES or No 입력받는 함수

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