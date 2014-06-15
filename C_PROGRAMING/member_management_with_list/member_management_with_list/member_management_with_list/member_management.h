#ifndef __MEMBER_MANAGEMENT_H__
#define __MEMBER_MANAGEMENT_H__


#define CONSOLENUM 20
#define IDSIZE 10
#define PHONESIZE 20
#define NAMESIZE 50
#define ADDRESSSIZE 50
#define BUFFERSIZE 256

typedef struct userinfo{
	int userId;
	char userName[50];
	char userAddress[100];
	char phone[20];
}userInfo_t;

typedef struct node{
	userInfo_t data;
	struct node* next;
}node_t;

typedef struct list{
	struct node* head;
}list_t;

//list용 함수
list_t* makeList(void);
node_t* makeNode(void);
int insertNode(node_t* prevNode, node_t* newNode);
node_t* findMaxInListWithNode(list_t* list);
int deleteNode(list_t* list, node_t* deleteNode);
node_t* findPrevNode(list_t* list, node_t* node);
int clearList(list_t* list);

//초기화
int mainMenu(void);
int initUserInfo(list_t* infoList, FILE* fp);

//출력
int printData(list_t* userInfoList, int top);
node_t* moveNodeByIdx(list_t* list, int idx);

//입력
int insertMember(list_t* userInfoList);
int getUserId(char* subject);
int getUserName(char* subject);
int getUserAddress(char* subject);
int getPhoneNumber(char* subject);
int strcpyWithoutNewline(char* copyer, char* copyee);
int isPhoneNumber(char* str);
int getYesOrNo(char* str);

//찾기
node_t* findMember(list_t* userInfoList, char* str);
void printArrData(node_t* resultNodeArr[BUFFERSIZE], char* Query);
node_t* selectNode(node_t* resultNodeArr[BUFFERSIZE]);

//삭제 수정
int deleteMember(list_t* userInfoList);
int updateMember(list_t* userInfoList);

//저장
int saveData(list_t* userInfoList, FILE* fp);

#endif