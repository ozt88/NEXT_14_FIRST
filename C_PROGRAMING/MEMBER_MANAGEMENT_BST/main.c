#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

int main(void)
{
	FILE* readfile;
	FILE* writefile;
	int input = 0; //입력 값
	int nodeNum = 0; //노드 갯수
	tree_t* userInfoTree = makeTree();

	//파일에서 구조체로 삽입함.
	fopen_s(&readfile, "data.txt", "rt");
	nodeNum = initUserInfo(userInfoTree, readfile);
	fclose(readfile);

	
	//메인메뉴 띄우기
	while (1)
	{
		input = mainMenu();
		switch (input)
		{
		case 1:
			//출력
			printData(userInfoTree, nodeNum);
			break;
		case 2:
			//등록
			insertMember(userInfoTree);
			break;
		case 3:
			//삭제
			deleteMember(userInfoTree);
			break;
		case 4:
			//수정
			updateMember(userInfoTree);
			break;
		case 5:
			//저장
			fopen_s(&writefile, "data.txt", "wt");
			saveData(userInfoTree, writefile);
			fclose(writefile);
			break;

		case 0:
			//종료
			system("cls");
			input = getYesOrNo("\n\t저장 후 종료하시겠습니까?(Y/N): ");
			if (input)
			{
				fopen_s(&writefile, "data.txt", "wt");
				saveData(userInfoTree, writefile);
				fclose(writefile);
			}
			clearTreeWithNode(userInfoTree->root);
			system("cls");
			printf("\n\t");
			return 0;

		default:
			break;
		}
	}
}