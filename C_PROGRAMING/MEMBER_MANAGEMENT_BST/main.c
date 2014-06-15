#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

int main(void)
{
	FILE* readfile;
	FILE* writefile;
	int input = 0; //�Է� ��
	int nodeNum = 0; //��� ����
	tree_t* userInfoTree = makeTree();

	//���Ͽ��� ����ü�� ������.
	fopen_s(&readfile, "data.txt", "rt");
	nodeNum = initUserInfo(userInfoTree, readfile);
	fclose(readfile);

	
	//���θ޴� ����
	while (1)
	{
		input = mainMenu();
		switch (input)
		{
		case 1:
			//���
			printData(userInfoTree, nodeNum);
			break;
		case 2:
			//���
			insertMember(userInfoTree);
			break;
		case 3:
			//����
			deleteMember(userInfoTree);
			break;
		case 4:
			//����
			updateMember(userInfoTree);
			break;
		case 5:
			//����
			fopen_s(&writefile, "data.txt", "wt");
			saveData(userInfoTree, writefile);
			fclose(writefile);
			break;

		case 0:
			//����
			system("cls");
			input = getYesOrNo("\n\t���� �� �����Ͻðڽ��ϱ�?(Y/N): ");
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