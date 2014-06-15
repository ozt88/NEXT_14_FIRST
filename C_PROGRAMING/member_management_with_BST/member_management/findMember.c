#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member_management.h"

// 회원을 아이디, 이름, 주소 , 전화번호로 검색하는 함수
// 회원 아이디를 리턴

node_t* findMember(tree_t* userInfoTree, char* str)
{
	char inputStr[BUFFERSIZE] = { 0, };
	int idx = 0;
	int input = 0;
	node_t* resultNodeArr[BUFFERSIZE] = { 0, };
	
	if (!userInfoTree)
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

		switch (input)
		{
		case 1:
			getUserId(inputStr);
			//ID는 한개만 있으므로 바로 키값처럼 검색해서 리턴
			resultNodeArr[idx] = searchBSTbyUserIdWithNode(userInfoTree->root, atoi(inputStr));
			break;
		case 2:
			getUserName(inputStr);
			searchBSTbyNameWithNode(userInfoTree->root, inputStr, resultNodeArr, &idx);
			break;
		case 3:
			getUserAddress(inputStr);
			searchBSTbyAddressWithNode(userInfoTree->root, inputStr, resultNodeArr, &idx);
			break;
		case 4:
			getPhoneNumber(inputStr);
			searchBSTbyPhoneWithNode(userInfoTree->root, inputStr, resultNodeArr, &idx);
			break;
		case 0:
			return (node_t*)NULL;
		default:
			break;
		}
		printArrData(resultNodeArr, inputStr);
		return selectNode(resultNodeArr);
	}
}

//이름으로 검색 inorder로 노드들을 체크하면서 일치하는지 확인
void searchBSTbyNameWithNode(node_t* node, char* str, node_t* resultNodeArr[BUFFERSIZE], int* idx)
{
	if (!node)
	{
		return;
	}

	searchBSTbyNameWithNode(node->leftChild, str, resultNodeArr, idx);
	if (!strcmp(node->data.userName, str))
	{
		resultNodeArr[(*idx)++] = node;
	}
	searchBSTbyNameWithNode(node->rightChild, str, resultNodeArr, idx);
	
	return;
}

//주소로 검색
void searchBSTbyAddressWithNode(node_t* node, char* str, node_t* resultNodeArr[BUFFERSIZE], int* idx)
{
	if (!node)
	{
		return;
	}

	searchBSTbyAddressWithNode(node->leftChild, str, resultNodeArr, idx);
	if (!strcmp(node->data.userAddress, str))
	{
		resultNodeArr[(*idx)++] = node;
	}
	searchBSTbyAddressWithNode(node->rightChild, str, resultNodeArr, idx);

	return;
}

//핸드폰 번호로 검색
void searchBSTbyPhoneWithNode(node_t* node, char* str, node_t* resultNodeArr[BUFFERSIZE], int* idx)
{
	if (!node)
	{
		return;
	}

	searchBSTbyPhoneWithNode(node->leftChild, str, resultNodeArr, idx);
	if (!strcmp(node->data.phone, str))
	{
		resultNodeArr[(*idx)++] = node;
	}
	searchBSTbyPhoneWithNode(node->rightChild, str, resultNodeArr, idx);

	return;
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