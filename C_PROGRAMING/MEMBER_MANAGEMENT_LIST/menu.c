#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//���θ޴��� ����ϰ� �������� �Է¹޴� �Լ�

int mainMenu(void)
{
	int input;
	system("cls");
	printf("=============================================================================\n");
	printf("%40s\n", "MENU");
	printf("=============================================================================\n");
	printf("\n\t%3s", "1. ȸ�� ���\n");
	printf("\n\t%3s", "2. ȸ�� ���\n");
	printf("\n\t%3s", "3. ȸ�� ����\n");
	printf("\n\t%3s", "4. ȸ�� ����\n");
	printf("\n\t%3s", "5. ������ ����\n");
	printf("\n\t%3s", "0. ����\n");
	printf("\n\t������ �޴� ��ȣ�� �Է��ϼ���: ");
	fflush(stdin);
	scanf_s("\n%d", &input);

	return input;
}