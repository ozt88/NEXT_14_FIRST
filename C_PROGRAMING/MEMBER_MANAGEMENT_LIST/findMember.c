#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

// 회원을 아이디, 이름, 주소 , 전화번호로 검색하는 함수
// 회원 아이디를 리턴

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
		printf("%34s할 %s\t\n", str, "회원 검색");
		printf("=============================================================================\n");
		printf("\n\t%3s", "1. ID로 검색\n");
		printf("\n\t%3s", "2. 이름으로 검색\n");
		printf("\n\t%3s", "3. 주소로 검색\n");
		printf("\n\t%3s", "4. 전화 번호로 검색\n");
		printf("\n\t%3s", "0. 종료\n");
		printf("\n\t실행할 번호를 입력하세요: ");
		scanf_s("\n%d", &input);
		if (!input)
		{
			return (node_t*)NULL;
		}
		currentNode = userInfoList->head->next;

		do{
			system("cls");
			printf("\n\t검색할 회원 정보를 입력하세요. 종료는 q를 입력하세요.\n\n\t입력:");
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


//검색된 결과를 배열에 저장하고 그것들을 출력함.
void printArrData(node_t* resultNodeArr[BUFFERSIZE], char* Query)
{
	system("cls");
	printf("검색어 : %s\n", Query);
	printf("[No.]%10s\t%10s\t%-30s\t%-10s\n", "회원ID", "회원이름", "회원주소", "연락처");
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

//배열에 저장된 노드들중에 하나를 선택
node_t* selectNode(node_t* resultNodeArr[BUFFERSIZE])
{
	int input = 0;

	if (!resultNodeArr[0])
	{
		printf("\n\t검색 실패!\n");
		fflush(stdin);
		getchar();
		return (node_t*)NULL;

	}

	do
	{
		printf("\n\t원하는 회원정보의 번호[No.]를 입력하세요 :");
		fflush(stdin);
		scanf("%d", &input);
	} while (!resultNodeArr[input]);
	return resultNodeArr[input];
}