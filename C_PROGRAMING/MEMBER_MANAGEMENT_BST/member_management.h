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

typedef struct node
{
	userInfo_t data;
	struct node* parent;
	struct node* leftChild;
	struct node* rightChild;
}node_t;

typedef struct tree
{
	node_t* root;
}tree_t;


//bst용함수
int bstInsertNode(tree_t* tree, node_t* givenNode);
int deleteInBST(tree_t* tree, node_t* delNode);
node_t* findMinInBSTWithNode(node_t* currentNode);
node_t* findMaxInBSTWithNode(node_t* currentNode);
node_t* searchBSTbyUserIdWithNode(node_t* currentNode, int userId);
int transplantInBST(tree_t* tree, node_t* deNode, node_t* newNode);
void clearTreeWithNode(node_t* node);
node_t* makeNode(void);
tree_t* makeTree(void);

//초기화
int mainMenu(void);
int initUserInfo(tree_t* infoTree, FILE* fp);

//출력
int printData(tree_t* infoTree, int nodeNum);
int inorderPrint(node_t* node);

//입력
int insertMember(tree_t* userInfoTree);
int getUserId(char* subject);
int getUserName(char* subject);
int getUserAddress(char* subject);
int getPhoneNumber(char* subject);
int strcpyWithoutNewline(char* copyer, char* copyee);
int isPhoneNumber(char* str);
int getYesOrNo(char* str);

//찾기
node_t* findMember(tree_t* userInfoTree, char* str);
void searchBSTbyNameWithNode(node_t* node, char* str, node_t* resultNodeArr[BUFFERSIZE], int* idx);
void searchBSTbyAddressWithNode(node_t* node, char* str, node_t* resultNodeArr[BUFFERSIZE], int* idx);
void searchBSTbyPhoneWithNode(node_t* node, char* str, node_t* resultNodeArr[BUFFERSIZE], int* idx);
void printArrData(node_t* resultNodeArr[BUFFERSIZE]);
node_t* selectNode(node_t* resultNodeArr[BUFFERSIZE]);

//삭제 수정
int deleteMember(tree_t* userInfoTree);
int updateMember(tree_t* userInfoTree);

//저장
int saveData(tree_t* userInfoTree, FILE* fp);
void saveDataWithNode(node_t* node, FILE* fp);




#endif