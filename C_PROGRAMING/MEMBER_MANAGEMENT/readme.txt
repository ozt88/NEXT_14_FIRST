회원관리 프로그램 ver1.2
	by-141019김연우

ver 1.2 바뀐점

1.가독성을 위한 노력

2.전화번호가 형식 이상으로 입력되던 버그 픽스

3.이름 주소가 지나치게 길게 입력되면 오류가 나는 버그 픽스




ver 1.1 바뀐점 

1.전화번호 입력형식 제한(한글, 영어입력불가)

//int getPhoneNumber(char* input, char* message)

2.검색, 수정 함수 단순화

//int modifyMember(Userinfo* userInfoArr, int top)
//int findMemberIdx(Userinfo* userInfoArr, int top, char* str)


3.warning 제거 (fscanf 딱 한개... 제외)


