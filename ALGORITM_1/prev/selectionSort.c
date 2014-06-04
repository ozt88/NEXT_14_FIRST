//구현해야하는 함수 
//7.1 minValuePosIn = 최소값의 위치를 리턴한다.
//input 정수 배열과 배열의 크기, 
//output 제일 작은 값이 있는 위치,

//7.2. selectionSort = 주어진 리스트를 크기순으로 정렬한다.
//input 정수 배열과 배열의 크기
//output non - decreasing order로 정렬된 list


//7.P 증명
//n개의 숫자중에 최소값을 찾기 위해서 n-1번 미만으로 비교해서 찾을 수 있는 방법은 없다.
//크기 비교는 두 개 단위로만 시행할 수 있다.
//최소값 후보에서 원소를 탈락 시키기 위해서는 반드시 한번 비교해야만 한다.
//n개에서 최소값을 찾기 위해서는 반드시 n-1개의 후보를 탈락시켜야한다.
//따라서 n개의 숫자중에 최소값을 찾기 위해서는 n-1미만의 비교로는 불가능하다.
//+@ 모순에 의한 증명
//가정 : n-2번 비교해서 최소값을 찾을 수 있다.
//가정으로부터 2개의 정수사이의 최소값을 0번 비교해서 찾을 수 있다.
//2개 정수사이의 최소값을 비교안하고 찾을 수 있는 방법은 없으므로 가정에 모순이다.
//따라서 n-1번 미만의 비교로는 최소값을 찾을 수 없다.

#include<stdio.h>
int minValuePosIn(int, int);
int selectionSort(int, int);
void printList(int, int);
void swap(int *x, int *y);

int main(void)
{
	
	int  list[] = { 10, 3, 4, 1, 6, 9, 8, 2, 5, 7 };//원소 10개
	//TEST용
	//int list[] = { 10 }; // 원소 1개
	//int list[] = { 10, 3 }; // 원소 2개, 내림 차순
	//int list[] = { 20, 3, 1 }; // 원소 3개, 내림 차순
	//int list[] = { 3, 10 }; // 원소 2개, 올림 차순
	//int list[] = { 3, 10, 20 }; // 원소 3개, 올림 차순

	int  size = sizeof(list) / sizeof(int);

	printf("최솟값 위치 : %d\n", minValuePosIn(list, size));

	printList(list, size);

	selectionSort(list, size);

	printList(list, size);

	return 0;
}
//7.1
//주어진 리스트에서 가장 작은 값의 위치를 출력하는 함수.
//min : 최소의 위치를 찾는 변수, 
//idx : for문에서 돌면서 배열의 원소들을 하나씩 확인하는 변수
//0부터 리스트의 size까지, 즉 리스트의 처음부터 끝에 있는 위치까지 idx를 한개씩 증가시키면서
//가장 작은 원소의 위치값을 min에 저장하고 더 작은 원소의 위치값이 나오면 min을 갱신한다.

int minValuePosIn(int list[], int size){
	int min = 0;
	int idx = 0;
	if (list == NULL || size == 0) return -1;
	for (; idx < size; idx++){
		if (list[min] > list[idx]){
			min = idx;
		}
	}
	return min;
}

//7.2
//주어진 리스트를 크기순으로 정렬하는 함수
//먼저 list[0]을 전체에서 가장 작은 원소와 교환한다.
//idx가 0일때 idx2가 0~size까지 증가하면서 최소값을 확인한 뒤에 그것과 list[0]을 swap함수로 교환
//그다음 list[1]을 list[0]을 제외한 가장 작은 원소와 교환한다.
//idx가 1일때 idx2는 1~size까지 증가하면서 최소값을 확인한 뒤에 그것과 list[0]을 swap함수로 교환
//위와 같은 과정을 idx가 size까지 증가하면서 반복하기때문에 앞에서부터 한자리씩 비감소수열로 정렬시킨다.

int selectionSort(int list[], int size){
	int min;
	int idx = 0;
	int idx2 = 0;
	//size-1 마지막 하나에 대해서 연산해줄 필요가 없다. 
	//Boundary Condition 에 대한 고민이 필요하다.
	for (; idx < size-1; idx++){
		for (idx2 = idx, min = idx; idx2 < size; idx2++){
			if (list[min] > list[idx2]){
				min = idx2;
			}
		}
		swap(&list[idx], &list[min]);
	}

}

void printList(int list[], int size)
{
	int id;

	for (id = 0; id < size; id++) printf("%d ", list[id]);
	printf("\n");
}

void swap(int *x, int *y)
{
	int temp = *x; 
	*x = *y;          
	*y = temp;      
}
