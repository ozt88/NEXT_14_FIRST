#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//회원정보를 수정하는 함수

int updateMember(userInfo_t* userInfoArr, int top)
{
	int idx = 0;
	int input = 0;

	idx = findMemberIdx(userInfoArr, top, "수정");

	if (idx == -1) return -1;

	else{

		while (1)
		{
			system("cls");
			printf("=============================================================================\n");
			printf("%40s", "수정할 항목 선택\n");
			printf("=============================================================================\n");
			printf("\n\t%3s", "1. 이름 수정\n");
			printf("\n\t%3s", "2. 주소 수정\n");
			printf("\n\t%3s", "3. 전화 번호 수정\n");
			printf("\n\t%3s", "0. 종료\n");
			printf("\n\t선택할 번호를 입력하세요: ");
			fflush(stdin);
			scanf_s("\n%d", &input);

			switch (input)
			{
			case 1:
				getUserName(userInfoArr[idx].userName);
				break;
			case 2:
				getUserAddress(userInfoArr[idx].userAddress);
				break;
			case 3:
				getPhoneNumber(userInfoArr[idx].phone);
				break;
			case 0:
				return 0;
			default:
				break;
			}
			printf("\n\t%s님의 정보가 수정되었습니다.", userInfoArr[idx].userName);
			fflush(stdin);
			getchar();
		}
	}
}


