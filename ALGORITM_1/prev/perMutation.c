#include<stdio.h>
// printPerm 테스트 용도의 호출 코드
// swapChar 문자 교체 함수
// printArray 배열 출력 함수
#include <string.h>
void swapChar(char *ch1, char *ch2);
void printPerm(char *list, int startId, int endId);
void printArray(char list[], int length);
int main(void)
{
	char list[] = { 'a', 'b', 'c' , 'd', 'e' };
	//char list[]={'a'};
	//char list[]="";
	int length = sizeof(list) / sizeof(char);
	printPerm(list, 0, length); // 최초 호출하는 곳

	return 0;
}

void swapChar(char *ch1, char *ch2)
{
	char tmp;

	tmp = *ch1;
	*ch1 = *ch2;
	*ch2 = tmp;
}

void printPerm(char list[], int startId, int endId)
{
	if (startId == endId)
	{
		printArray(list, endId);
	}
	else
	{
		for (int i = startId; i < endId; i++)
		{
			swapChar(&list[startId], &list[i]);
			printPerm(list, startId + 1, endId);
			swapChar(&list[startId], &list[i]);
		}
	}
}

void printArray(char list[], int length)
{
	int i = 0;
	while (i < length)
	{
		printf("%2c", list[i]);
		i++;
	}
	printf("\n");
}
