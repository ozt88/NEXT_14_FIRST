#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

// ȸ���� ���̵�, �̸�, �ּ� , ��ȭ��ȣ�� �˻��ϴ� �Լ�
// ȸ�� ���̵� ����

node_t* findMember(list_t* userInfoList, char* str)
{
	int idx = 0;
	int input = 0;
	char inputStr[BUFFERSIZE] = { 0, };
	char temp[BUFFERSIZE] = { 0, };
	node_t* resultNodeArr[BUFFERSIZE] = { 0, };
	node_t* currentNode;
	if (!userInfoList)
	{
		return -1;
	}

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
		if (!input)
		{
			return (node_t*)NULL;
		}
		currentNode = userInfoList->head->next;

		do{
			system("cls");
			printf("\n\t�˻��� ȸ�� ������ �Է��ϼ���. ����� q�� �Է��ϼ���.\n\n\t�Է�:");
			fflush(stdin);
			gets_s(inputStr, sizeof(char)*BUFFERSIZE);
			idx = 0;
			while (currentNode)
			{
				switch (input)
				{
				case 1:
					_itoa_s(currentNode->data.userId, temp, sizeof(char)*IDSIZE, 10);
					break;
				case 2:
					strcpy_s(temp, sizeof(char)*NAMESIZE, currentNode->data.userName);
					break;
				case 3:
					strcpy_s(temp, sizeof(char)*ADDRESSSIZE, currentNode->data.userAddress);
					break;
				case 4:
					strcpy_s(temp, sizeof(char)*PHONESIZE, currentNode->data.phone);
					break;
				default:
					break;
				}

				if (!strcmp(temp, inputStr))
				{
					resultNodeArr[idx++] = currentNode;
				}
				currentNode = currentNode->next;
			}
			printArrData(resultNodeArr, inputStr);
			return selectNode(resultNodeArr);
		} while (strcmp(inputStr, "q") != 0);
	} 
}


//�˻��� ����� �迭�� �����ϰ� �װ͵��� �����.
void printArrData(node_t* resultNodeArr[BUFFERSIZE], char* Query)
{
	system("cls");
	printf("�˻��� : %s\n", Query);
	printf("[No.]%10s\t%10s\t%-30s\t%-10s\n", "ȸ��ID", "ȸ���̸�", "ȸ���ּ�", "����ó");
	printf("=============================================================================\n");
	for (int i = 0; i < BUFFERSIZE; i++)
	{
		if (!resultNodeArr[i])
		{
			break;
		}
		printf("[%d]%12d\t%8s\t%-30s\t%10s\n", i, resultNodeArr[i]->data.userId, resultNodeArr[i]->data.userName, resultNodeArr[i]->data.userAddress, resultNodeArr[i]->data.phone);
	}
	printf("=============================================================================\n");
	return;
}

//�迭�� ����� �����߿� �ϳ��� ����
node_t* selectNode(node_t* resultNodeArr[BUFFERSIZE])
{
	int input = 0;

	if (!resultNodeArr[0])
	{
		printf("\n\t�˻� ����!\n");
		fflush(stdin);
		getchar();
		return (node_t*)NULL;

	}

	do
	{
		printf("\n\t���ϴ� ȸ�������� ��ȣ[No.]�� �Է��ϼ��� :");
		fflush(stdin);
		scanf("%d", &input);
	} while (!resultNodeArr[input]);
	return resultNodeArr[input];
}