#include<stdio.h>
//hanoi 하노이 순서 출력하는 함수
//인자 설명
//disk 판의 넘버, to 어디로 갈 것인지, from 어디서 부터 가는지, rest to랑 from 을 뺀 나머지
int hanoi(int disk, int to, int from, int rest);
int main(void){
	//64 출력이 너무느려서 바꿧습니다.
	hanoi(6, 1, 2, 3);
	return 0;
}

int hanoi(int disk, int to, int from, int rest)
{
	if (disk == 1) printf("[Disk No.%d] (%d -> %d)\n", disk, to, from);
	
	else 
	{ 
		hanoi(disk - 1, to, rest, from);
		printf("[Disk No.%d] (%d -> %d)\n", disk, to, from);
		hanoi(disk - 1, rest, from, to);
	}
}