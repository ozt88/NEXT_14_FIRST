#ifndef __MEMBER_MANAGEMENT_H__
#define __MEMBER_MANAGEMENT_H__


typedef struct userinfo{
	int userId;
	char userName[50];
	char userAddress[100];
	char phone[20];
}userInfo_t;

#define CONSOLENUM 20
#define IDSIZE 10
#define PHONESIZE 20
#define NAMESIZE 50
#define ADDRESSSIZE 50
#define BUFFERSIZE 256

int mainManu(void);

userInfo_t* initUserinfo(FILE* fp, int* top, int* capacity);

int inputStructData(userInfo_t* userInfoArr, FILE* fp);

userInfo_t* arrangeStructData(userInfo_t* userInfoArr, int rowNum);

userInfo_t* checkCapacity(userInfo_t* userInfoArr, int rowNum, int* capacity);

int findMinIdx(userInfo_t* userInfo_t, int startId, int rowNum);

int saveData(userInfo_t* userinfoArr, FILE* fp, int rowNum);

int printData(userInfo_t* userInfoArr, int rowNum);

int insertMember(userInfo_t** userInfoArr, int* rowNum, int* capacity);

int getUserName(char* subject);

int getUserAddress(char* subject);

int getPhoneNumber(char* subject);

int strcpyWithoutNewline(char* copyer, char* copyee);

int deleteMember(userInfo_t* userInfoArr, int* rowNum);

int updateMember(userInfo_t* userInfoArr, int rowNum);

int findMemberIdx(userInfo_t* userInfoArr, int rowNum, char* str);

int findMemberbyStr(userInfo_t* userInfoArr, int caseNum, int top);

int findMemberbyName(userInfo_t* userInfoArr, int rowNum);

int findMemberbyAddress(userInfo_t* userInfoArr, int rowNum);

int findMemberbyPhone(userInfo_t* userInfoArr, int rowNum);

int exitSave(userInfo_t* userInfoArr, FILE* fp, int rowNum);

int isPhoneNumber(char* str);


#endif