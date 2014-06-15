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
	list_t* userInfoList = makeList();

	//���Ͽ��� ����ü�� ������.
	fopen_s(&readfile, "data.txt", "rt");
	nodeNum = initUserInfo(userInfoList, readfile);
	fclose(readfile);


	//���θ޴� ����
	while (1)
	{
		input = mainMenu();
		switch (input)
		{
		case 1:
			//���
			printData(userInfoList, nodeNum);
			break;
		case 2:
			//���
			insertMember(userInfoList);
			break;
		case 3:
			//����
			deleteMember(userInfoList);
			break;
		case 4:
			//����
			updateMember(userInfoList);
			break;
		case 5:
			//����
			fopen_s(&writefile, "data.txt", "wt");
			saveData(userInfoList, writefile);
			fclose(writefile);
			break;

		case 0:
			//����
			system("cls");
			input = getYesOrNo("\n\t���� �� �����Ͻðڽ��ϱ�?(Y/N): ");
			if (input)
			{
				fopen_s(&writefile, "data.txt", "wt");
				saveData(userInfoList, writefile);
				fclose(writefile);
			}
			system("cls");
			printf("\n\t");
			if (userInfoList)
			{
				clearList(userInfoList);
			}
			return 0;

		default:
			break;
		}
	}
}