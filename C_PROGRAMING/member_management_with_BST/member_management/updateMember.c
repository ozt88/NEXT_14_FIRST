#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

//ȸ�������� �����ϴ� �Լ�
//�˻��ѵ� ��忡 �����ؼ� �ٷ� �����͸� �ٲ��ֱ⸸ �ϸ�ȴ�.
int updateMember(tree_t* userInfoTree)
{
	int input = 0;
	node_t* updateNode;

	if (!userInfoTree)
	{
		return -1;
	}

	updateNode = findMember(userInfoTree, "����");
	if(updateNode)
	{
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
				getUserName(updateNode->data.userName);
				break;
			case 2:
				getUserAddress(updateNode->data.userAddress);
				break;
			case 3:
				getPhoneNumber(updateNode->data.phone);
				break;
			case 0:
				return 0;
			default:
				break;
			}
			printf("\n\t%s���� ������ �����Ǿ����ϴ�.", updateNode->data.userName);
			fflush(stdin);
			getchar();
		}
	}
}


