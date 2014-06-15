#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//메인메뉴를 출력하고 선택지를 입력받는 함수

int mainMenu(void)
{
	int input;
	system("cls");
	printf("=============================================================================\n");
	printf("%40s\n", "MENU");
	printf("=============================================================================\n");
	printf("\n\t%3s", "1. 회원 출력\n");
	printf("\n\t%3s", "2. 회원 등록\n");
	printf("\n\t%3s", "3. 회원 삭제\n");
	printf("\n\t%3s", "4. 회원 수정\n");
	printf("\n\t%3s", "5. 데이터 저장\n");
	printf("\n\t%3s", "0. 종료\n");
	printf("\n\t실행할 메뉴 번호를 입력하세요: ");
	fflush(stdin);
	scanf_s("\n%d", &input);

	return input;
}