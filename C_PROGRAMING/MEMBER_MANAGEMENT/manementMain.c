#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//회원관리 프로그램의 메인함수.

int main(void)
{
	FILE* readfile;
	FILE* writefile;
	int top = 0; //스택의 top와 유사
	int capacity = 100; //전체 구조체의 크기
	int input = 0; //입력 값

	userInfo_t* userInfoArr;

	fopen_s(&readfile, "data.txt", "rt");
	userInfoArr = initUserinfo(readfile, &top, &capacity);
	fclose(readfile);

	//메인메뉴 띄우기
	while (1)
	{
		input = mainManu();
		switch (input)
		{
		case 1:
			//출력
			printData(userInfoArr, top);
			break;
		case 2:
			//등록
			insertMember(&userInfoArr, &top, &capacity);
			userInfoArr = arrangeStructData(userInfoArr, top);
			break;
		case 3:
			//삭제
			deleteMember(userInfoArr, &top);
			break;
		case 4:
			//수정
			updateMember(userInfoArr, top);
			break;
		case 5:
			//저장
			fopen_s(&writefile, "data.txt", "wt");
			saveData(userInfoArr, writefile, top);
			fclose(writefile);
			break;

		case 0:
			//종료
			if (userInfoArr) free(userInfoArr);
			system("cls");
			printf("\n\t");
			return 0;

		default:
			break;
		}
	}
}
