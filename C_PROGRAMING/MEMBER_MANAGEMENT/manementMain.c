#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//ȸ������ ���α׷��� �����Լ�.

int main(void)
{
	FILE* readfile;
	FILE* writefile;
	int top = 0; //������ top�� ����
	int capacity = 100; //��ü ����ü�� ũ��
	int input = 0; //�Է� ��

	userInfo_t* userInfoArr;

	fopen_s(&readfile, "data.txt", "rt");
	userInfoArr = initUserinfo(readfile, &top, &capacity);
	fclose(readfile);

	//���θ޴� ����
	while (1)
	{
		input = mainManu();
		switch (input)
		{
		case 1:
			//���
			printData(userInfoArr, top);
			break;
		case 2:
			//���
			insertMember(&userInfoArr, &top, &capacity);
			userInfoArr = arrangeStructData(userInfoArr, top);
			break;
		case 3:
			//����
			deleteMember(userInfoArr, &top);
			break;
		case 4:
			//����
			updateMember(userInfoArr, top);
			break;
		case 5:
			//����
			fopen_s(&writefile, "data.txt", "wt");
			saveData(userInfoArr, writefile, top);
			fclose(writefile);
			break;

		case 0:
			//����
			if (userInfoArr) free(userInfoArr);
			system("cls");
			printf("\n\t");
			return 0;

		default:
			break;
		}
	}
}
