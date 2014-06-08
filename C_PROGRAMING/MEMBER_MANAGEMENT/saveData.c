#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//구조체의 정보를 다시 파일에 저장하는 함수

int saveData(userInfo_t* userinfoArr, FILE* fp, int top)
{
	if (fp == NULL)
	{
		puts("data.txt file write open error!\n");
		if (userinfoArr) free(userinfoArr);
		return -1;
	}

	fputs("학생번호\t학생이름\t학생주소\t학생번호\n", fp);
	for (int idx = 1; idx < top; idx++)
	{
		fprintf(fp, "%d\t%s\t%s\t%s\n", userinfoArr[idx].userId, userinfoArr[idx].userName, userinfoArr[idx].userAddress, userinfoArr[idx].phone);
	}
	printf("\n\t저장 완료\n");
	fflush(stdin);
	getchar();

	return 0;
}

