#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

// ȸ���� �˻��ؼ� ������ �� �����ϴ� �Լ�

int deleteMember(tree_t* userInfoTree)
{
	node_t* delNode;
	if (!userInfoTree)
	{
		return -1;
	}

	delNode = findMember(userInfoTree, "����");
	
	if (delNode)
	{
		if (getYesOrNo("�� ȸ���� ������ �����Ͻðڽ��ϱ�?(Y/N): "))
		{
			printf("\n\t%s���� ������ �����Ǿ����ϴ�.\n", delNode->data.userName);
			deleteInBST(userInfoTree, delNode);
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