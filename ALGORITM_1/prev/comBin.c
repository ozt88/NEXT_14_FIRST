#include<stdio.h>
//주어진 집합에서 가능한 모든 조합의 경우의 수를 출력하는 함수 구현
//input : 조합할 집합(배열), (선택의 갯수)
//output : 집합에서 가능한 모든 조합의 경우의 수
//printCombi 모든 조합을 출력하는 함수
void printCombi(int arr[], int combi[], int start, int choice, int length);
void printArray(int arr[], int length);
int main(void)
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int combi[9] = { 0 };
	int length = sizeof(arr) / sizeof(int);
	for (int i = 1; i <= length; i++){printCombi(arr, combi, 0, i, length);}
	return 0;
}

//출력함수
void printArray(int arr[], int length)
{
	for (int i = 0; i<length; i++) { if (arr[i] != 0)printf("%2d", arr[i]); }
	printf("\n");
}

//printCombi 주어진 배열에서 가능한 조합을 출력
//arr[]=조합할 수들의 배열
//combi[]=조합을 기록할 배열
//start 시작점
//choice 선택의 갯수, length 배열의 길이 
//C(4,3)이면 length 가 4이고 choice가 3이다.
//작동방식: 
//N개에서 R개를 선택할때 start번째 있는 원소를 조합으로 선택하면 남은 원소들에서 R-1개를 선택한다.
//start를 하나 더 늘리고 choice를 하나 줄인다.
//start의 원소를 넣지 않으면 남은 원소들에서 R개를 넣게 한다.
//start는 늘리고 choice는 줄이지 않는다. (이때 선택하지 않는 것을 구분하기 위해서 0을 combi에 넣는다.)
//choice의 갯수가 0인경우 조합이 완료 되었으므로 출력하고 종료한다.
//choice가 줄어들지 않는 두번쨰 재귀함수에 들어가면 choice가 영원히 0이 안되는 경우가 발생하므로
//start가 length와 같아지면, 전부다 체크한 것이므로 그냥 종료한다.

void printCombi(int arr[], int combi[], int start, int choice, int length)
{
	if (choice == 0) {printArray(combi, length); return;}
	if (start == length) return;
	combi[start] = arr[start];
	printCombi(arr, combi, start + 1, choice - 1, length);
	combi[start] = 0;
	printCombi(arr, combi, start + 1, choice, length);
}