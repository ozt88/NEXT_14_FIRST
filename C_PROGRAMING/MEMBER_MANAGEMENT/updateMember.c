#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//ȸ�������� �����ϴ� �Լ�

int updateMember(userInfo_t* userInfoArr, int top)
{
	int idx = 0;
	int input = 0;

	idx = findMemberIdx(userInfoArr, top, "����");

	if (idx == -1) return -1;

	else{

		while (1)
		{
			system("cls");
			printf("=============================================================================\n");
			printf("%40s", "������ �׸� ����\n");
			printf("=============================================================================\n");
			printf("\n\t%3s", "1. �̸� ����\n");
			printf("\n\t%3s", "2. �ּ� ����\n");
			printf("\n\t%3s", "3. ��ȭ ��ȣ ����\n");
			printf("\n\t%3s", "0. ����\n");
			printf("\n\t������ ��ȣ�� �Է��ϼ���: ");
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
			printf("\n\t%s���� ������ �����Ǿ����ϴ�.", userInfoArr[idx].userName);
			fflush(stdin);
			getchar();
		}
	}
}


