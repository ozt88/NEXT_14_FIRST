#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

// 회원을 검색해서 선택한 후 삭제하는 함수

int deleteMember(tree_t* userInfoTree)
{
	node_t* delNode;
	if (!userInfoTree)
	{
		return -1;
	}

	delNode = findMember(userInfoTree, "삭제");
	
	if (delNode)
	{
		if (getYesOrNo("이 회원의 정보를 삭제하시겠습니까?(Y/N): "))
		{
			printf("\n\t%s님의 정보가 삭제되었습니다.\n", delNode->data.userName);
			deleteInBST(userInfoTree, delNode);
			fflush(stdin);
			getchar();
		}
		else
		{
			printf("\n\t삭제가 취소되었습니다.\n");
			fflush(stdin);
			getchar();
		}
	}
	
	return 0;
}