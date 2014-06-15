#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

// ȸ���� �˻��ؼ� ������ �� �����ϴ� �Լ�

int deleteMember(list_t* userInfoList)
{
	node_t* delNode;
	if (!userInfoList)
	{
		return -1;
	}

	delNode = findMember(userInfoList, "����");

	if (delNode)
	{
		if (getYesOrNo("�� ȸ���� ������ �����Ͻðڽ��ϱ�?(Y/N): "))
		{
			printf("\n\t%s���� ������ �����Ǿ����ϴ�.\n", delNode->data.userName);
			deleteNode(userInfoList, delNode);
			fflush(stdin);
			getchar();
		}
		else
		{
			printf("\n\t������ ��ҵǾ����ϴ�.\n");
			fflush(stdin);
			getchar();
		}
	}

	return 0;
}