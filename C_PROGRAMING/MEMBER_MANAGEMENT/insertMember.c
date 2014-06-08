#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//새로운 회원을 추가하는 함수

int insertMember(userInfo_t** userInfoArr, int* top, int* capacity)
{
	char buffer[BUFFERSIZE] = { 0, };

	if (!userInfoArr) return -1;

	*userInfoArr = checkCapacity(*userInfoArr, *top, capacity);

	system("cls");
	printf("=============================================================================\n");
	printf("%40s\n", "회원 등록");
	printf("=============================================================================\n");

	printf("\t회원 ID: %d\n", ((*userInfoArr)[*top - 1].userId) + 1);
	(*userInfoArr)[*top].userId = ((*userInfoArr)[*top - 1].userId) + 1;

	getUserName((*userInfoArr)[*top].userName);
	getUserAddress((*userInfoArr)[*top].userAddress);
	getPhoneNumber((*userInfoArr)[*top].phone);

	printf("\t등록 완료");
	fflush(stdin);
	getchar();

	(*userInfoArr)[++*top].userId = (*userInfoArr)[*top - 1].userId + 1;

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

//구조체 배열의 메모리 용량을 확인해보고 용량이 부족하면 2배해주는 함수

userInfo_t* checkCapacity(userInfo_t* userInfoArr, int top, int* capacity)
{
	if (top + 1 >= *capacity)
	{
		while (top + 1 >= *capacity){ *capacity *= 2; }
		userInfoArr = realloc(userInfoArr, sizeof(userInfo_t)*(*capacity));
	}

	return userInfoArr;
}

//스트링에서 뉴라인을 빼고 복사를 하는 함수

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
