#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//����ü�� ������ �ٽ� ���Ͽ� �����ϴ� �Լ�

int saveData(userInfo_t* userinfoArr, FILE* fp, int top)
{
	if (fp == NULL)
	{
		puts("data.txt file write open error!\n");
		if (userinfoArr) free(userinfoArr);
		return -1;
	}

	fputs("�л���ȣ\t�л��̸�\t�л��ּ�\t�л���ȣ\n", fp);
	for (int idx = 1; idx < top; idx++)
	{
		fprintf(fp, "%d\t%s\t%s\t%s\n", userinfoArr[idx].userId, userinfoArr[idx].userName, userinfoArr[idx].userAddress, userinfoArr[idx].phone);
	}
	printf("\n\t���� �Ϸ�\n");
	fflush(stdin);
	getchar();

	return 0;
}

