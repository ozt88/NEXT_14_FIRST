#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

// 회원을 아이디, 이름, 주소 , 전화번호로 검색하는 함수
// 회원 아이디를 리턴

int findMemberIdx(userInfo_t* userInfoArr, int top, char* str)
{
	int idx = -1;
	int input = 0;

	while (1)
	{
		system("cls");
		printf("=============================================================================\n");
		printf("%34s할 %s\t\n", str, "회원 검색");
		printf("=============================================================================\n");
		printf("\n\t%3s", "1. ID로 검색\n");
		printf("\n\t%3s", "2. 이름으로 검색\n");
		printf("\n\t%3s", "3. 주소로 검색\n");
		printf("\n\t%3s", "4. 전화 번호로 검색\n");
		printf("\n\t%3s", "0. 종료\n");
		printf("\n\t실행할 번호를 입력하세요: ");
		scanf_s("\n%d", &input);

		switch (input)
		{
		case 1:
		case 2:
		case 3:
		case 4:
			idx = findMemberbyStr(userInfoArr, input, top);
			return idx;
		case 0:
			return idx;
		default:
			break;
		}
	}

}

//입력된 스트링과 비교하여 일치하는 정보를 가진 회원을 찾는 함수

int findMemberbyStr(userInfo_t* userInfoArr, int caseNum, int top)
{
	int idx = 0;
	char inputstr[BUFFERSIZE] = { 0, };
	char temp[BUFFERSIZE] = { 0, };
	char inputc = 0;

	do{
		system("cls");
		printf("\n\t검색할 회원 정보를 입력하세요. 종료는 q를 입력하세요.\n\n\t입력:");
		fflush(stdin);
		gets_s(inputstr, sizeof(char)*BUFFERSIZE);
		idx = 1;

		while (idx < top)
		{
			switch (caseNum)
			{
			case 1:
				_itoa_s(userInfoArr[idx].userId, temp, sizeof(char)*IDSIZE, 10);
				break;
			case 2:
				strcpy_s(temp, sizeof(char)*NAMESIZE, userInfoArr[idx].userName);
				break;
			case 3:
				strcpy_s(temp, sizeof(char)*ADDRESSSIZE, userInfoArr[idx].userAddress);
				break;
			case 4:
				strcpy_s(temp, sizeof(char)*PHONESIZE, userInfoArr[idx].phone);
				break;
			}

			if (!strcmp(temp, inputstr))
			{
				printf("\n\t%d  %s  %10s  %10s\n", userInfoArr[idx].userId, userInfoArr[idx].userName, userInfoArr[idx].userAddress, userInfoArr[idx].phone);
				do{
					printf("\n\t%s님을 선택하시겠습니까?(Y/N): ", userInfoArr[idx].userName);
					fflush(stdin);
					scanf_s("%c", &inputc);
					if (inputc == 'Y' || inputc == 'y')
					{
						return idx;
					}
					else if (inputc == 'N' || inputc == 'n') break;
				} while (inputc != 'Y' && inputc != 'y' && inputc != 'N' && inputc != 'n');

			}
			idx++;
		}
		printf("\n\t검색 실패!");
		fflush(stdin);
		getchar();
	} while (strcmp(inputstr, "q") != 0);

	return -1;
}
