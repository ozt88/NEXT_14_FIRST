#include<stdio.h>
/*
입력
정수 배열, 찾고자 하는 배열의 범위, 찾고자 하는 key 값
출력
Key 값이 배열에 있으면 key가 있는 위치를 return
Key 값이 배열에 없으면 - 1을 return
*/
// binary search 반복문으로 바이너리서치하는 함수
// recBinarySearch 재귀로 바이너리 서치하는 함수
void printfList(int list[], int size);
int recBinarySearch(int list[], int left, int right, int key);
int binarySearch(int list[], int left, int right, int key);

int main(void)
{
	int  key, left, right;
	int  list[10] = { 1, 3, 4, 5, 6, 7, 8, 9, 12, 20 };
	int  size = sizeof(list) / sizeof(int);
	int  pos;
	int test;
	printfList(list, size);
	printf("TEST CODE (1-8)\n1: left = 0, right = size - 1, key = 20\n2: left = 0, right = 0, key = 1\n3: left = 0, right = 1, key = 1\n4: left = 0, right = 1, key = 3\n5: left = 0, right = 1, key = 0\n6: left = 0, right = 1, key = 4\n7: left = 0, right = 1, key = 2\n8:Quit.\n");
	while (1){
		printf("input number:");
		scanf("%d", &test);
		switch (test)
		{
		case 1: left = 0, right = size - 1, key = 20; break;//기본
		case 2: left = 0, right = 0, key = 1; break;// 길이 1
		case 3: left = 0, right = 1, key = 1; break;// 길이 2, 맨 왼쪽
		case 4: left = 0, right = 1, key = 3; break;// 길이 2, 맨 오른쪽
		case 5: left = 0, right = 1, key = 0; break;// 길이 2, 최소 이하
		case 6: left = 0, right = 1, key = 4; break;// 길이 2, 최대 이상
		case 7: left = 0, right = 1, key = 2; break;// 길이 2, 중간에 없음
		case 8: printf("Bye^^\n"); return 0;
		}
		pos = binarySearch(list, left, right, key);
		if (pos != -1)
			printf("key is at %d.\n", pos);
		else
			printf("key %d not found.\n", key);
	}
}

int recBinarySearch(int list[], int left, int right, int key)
{
	int middle;
	middle = (left + right) / 2;
	if (right - left<0)	 return -1;
	else if (list[middle] == key) return middle;
	else if (list[middle] > key) return  recBinarySearch(list, left, middle - 1, key);
    else if (list[middle] < key) return  recBinarySearch(list, middle + 1, right, key);
	
}


int binarySearch(int list[], int left, int right, int key)
{
	int middle;
	while (left <= right) 
	{
		middle = (left + right)/2;
		if (key < list[middle]) right = middle - 1;
		else if (key == list[middle]) return middle;
		else left = middle + 1;
	}
	return -1;
}





void printfList(int list[], int size)
{
	int id;

	for (id = 0; id < size; id++) printf("%d ", list[id]);
	printf("\n");
}
