#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

// ȸ���� ���̵�, �̸�, �ּ� , ��ȭ��ȣ�� �˻��ϴ� �Լ�
// ȸ�� ���̵� ����

int findMemberIdx(userInfo_t* userInfoArr, int top, char* str)
{
	int idx = -1;
	int input = 0;

	while (1)
	{
		system("cls");
		printf("=============================================================================\n");
		printf("%34s�� %s\t\n", str, "ȸ�� �˻�");
		printf("=============================================================================\n");
		printf("\n\t%3s", "1. ID�� �˻�\n");
		printf("\n\t%3s", "2. �̸����� �˻�\n");
		printf("\n\t%3s", "3. �ּҷ� �˻�\n");
		printf("\n\t%3s", "4. ��ȭ ��ȣ�� �˻�\n");
		printf("\n\t%3s", "0. ����\n");
		printf("\n\t������ ��ȣ�� �Է��ϼ���: ");
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

//�Էµ� ��Ʈ���� ���Ͽ� ��ġ�ϴ� ������ ���� ȸ���� ã�� �Լ�

int findMemberbyStr(userInfo_t* userInfoArr, int caseNum, int top)
{
	int idx = 0;
	char inputstr[BUFFERSIZE] = { 0, };
	char temp[BUFFERSIZE] = { 0, };
	char inputc = 0;

	do{
		system("cls");
		printf("\n\t�˻��� ȸ�� ������ �Է��ϼ���. ����� q�� �Է��ϼ���.\n\n\t�Է�:");
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
					printf("\n\t%s���� �����Ͻðڽ��ϱ�?(Y/N): ", userInfoArr[idx].userName);
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
		printf("\n\t�˻� ����!");
		fflush(stdin);
		getchar();
	} while (strcmp(inputstr, "q") != 0);

	return -1;
}
