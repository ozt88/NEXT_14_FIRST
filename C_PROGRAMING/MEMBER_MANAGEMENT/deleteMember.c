#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

// ȸ���� �˻��ؼ� ������ �� �����ϴ� �Լ�

int deleteMember(userInfo_t* userInfoArr, int* top)
{
	int idx = 0;
	char empty[1] = "";
	idx = findMemberIdx(userInfoArr, *top, "����");
	if (idx == -1) return -1;
	else{
		printf("\n\tID No.%d  %s���� �����Ǿ����ϴ�.\n", userInfoArr[idx].userId, userInfoArr[idx].userName);
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