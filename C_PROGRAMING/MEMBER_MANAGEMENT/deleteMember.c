#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

// 회원을 검색해서 선택한 후 삭제하는 함수

int deleteMember(userInfo_t* userInfoArr, int* top)
{
	int idx = 0;
	char empty[1] = "";
	idx = findMemberIdx(userInfoArr, *top, "삭제");
	if (idx == -1) return -1;
	else{
		printf("\n\tID No.%d  %s님이 삭제되었습니다.\n", userInfoArr[idx].userId, userInfoArr[idx].userName);
		userInfoArr[idx].userId = userInfoArr[*top].userId + 1;
		strcpy_s(userInfoArr[idx].userName, sizeof(char)*NAMESIZE, empty);
		strcpy_s(userInfoArr[idx].userAddress, sizeof(char)*ADDRESSSIZE, empty);
		strcpy_s(userInfoArr[idx].phone, sizeof(char)*PHONESIZE, empty);
		userInfoArr = arrangeStructData(userInfoArr, *top);
		userInfoArr[(*top)--].userId = 0;
		userInfoArr[*top].userId = (userInfoArr[*top - 1].userId) + 1;

		fflush(stdin);
		getchar();
	}
	return 0;
}