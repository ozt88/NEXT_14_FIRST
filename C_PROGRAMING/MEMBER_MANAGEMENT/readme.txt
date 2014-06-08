회원관리 프로그램 ver1.1
	by-141019김연우

바뀐점 

1.전화번호 입력형식 제한(한글, 영어입력불가)

//int getPhoneNumber(char* input, char* message)

2.검색, 수정 함수 단순화

//int modifyMember(Userinfo* userInfoArr, int top)
//int findMemberIdx(Userinfo* userInfoArr, int top, char* str)


3.warning 제거 (fscanf 딱 한개... 제외)

