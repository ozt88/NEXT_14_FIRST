#include<stdio.h>
//hanoi �ϳ��� ���� ����ϴ� �Լ�
//���� ����
//disk ���� �ѹ�, to ���� �� ������, from ��� ���� ������, rest to�� from �� �� ������
int hanoi(int disk, int to, int from, int rest);
int main(void){
	//64 ����� �ʹ������� �مf���ϴ�.
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