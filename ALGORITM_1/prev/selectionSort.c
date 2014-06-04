//�����ؾ��ϴ� �Լ� 
//7.1 minValuePosIn = �ּҰ��� ��ġ�� �����Ѵ�.
//input ���� �迭�� �迭�� ũ��, 
//output ���� ���� ���� �ִ� ��ġ,

//7.2. selectionSort = �־��� ����Ʈ�� ũ������� �����Ѵ�.
//input ���� �迭�� �迭�� ũ��
//output non - decreasing order�� ���ĵ� list


//7.P ����
//n���� �����߿� �ּҰ��� ã�� ���ؼ� n-1�� �̸����� ���ؼ� ã�� �� �ִ� ����� ����.
//ũ�� �񱳴� �� �� �����θ� ������ �� �ִ�.
//�ּҰ� �ĺ����� ���Ҹ� Ż�� ��Ű�� ���ؼ��� �ݵ�� �ѹ� ���ؾ߸� �Ѵ�.
//n������ �ּҰ��� ã�� ���ؼ��� �ݵ�� n-1���� �ĺ��� Ż�����Ѿ��Ѵ�.
//���� n���� �����߿� �ּҰ��� ã�� ���ؼ��� n-1�̸��� �񱳷δ� �Ұ����ϴ�.
//+@ ����� ���� ����
//���� : n-2�� ���ؼ� �ּҰ��� ã�� �� �ִ�.
//�������κ��� 2���� ���������� �ּҰ��� 0�� ���ؼ� ã�� �� �ִ�.
//2�� ���������� �ּҰ��� �񱳾��ϰ� ã�� �� �ִ� ����� �����Ƿ� ������ ����̴�.
//���� n-1�� �̸��� �񱳷δ� �ּҰ��� ã�� �� ����.

#include<stdio.h>
int minValuePosIn(int, int);
int selectionSort(int, int);
void printList(int, int);
void swap(int *x, int *y);

int main(void)
{
	
	int  list[] = { 10, 3, 4, 1, 6, 9, 8, 2, 5, 7 };//���� 10��
	//TEST��
	//int list[] = { 10 }; // ���� 1��
	//int list[] = { 10, 3 }; // ���� 2��, ���� ����
	//int list[] = { 20, 3, 1 }; // ���� 3��, ���� ����
	//int list[] = { 3, 10 }; // ���� 2��, �ø� ����
	//int list[] = { 3, 10, 20 }; // ���� 3��, �ø� ����

	int  size = sizeof(list) / sizeof(int);

	printf("�ּڰ� ��ġ : %d\n", minValuePosIn(list, size));

	printList(list, size);

	selectionSort(list, size);

	printList(list, size);

	return 0;
}
//7.1
//�־��� ����Ʈ���� ���� ���� ���� ��ġ�� ����ϴ� �Լ�.
//min : �ּ��� ��ġ�� ã�� ����, 
//idx : for������ ���鼭 �迭�� ���ҵ��� �ϳ��� Ȯ���ϴ� ����
//0���� ����Ʈ�� size����, �� ����Ʈ�� ó������ ���� �ִ� ��ġ���� idx�� �Ѱ��� ������Ű�鼭
//���� ���� ������ ��ġ���� min�� �����ϰ� �� ���� ������ ��ġ���� ������ min�� �����Ѵ�.

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
//�־��� ����Ʈ�� ũ������� �����ϴ� �Լ�
//���� list[0]�� ��ü���� ���� ���� ���ҿ� ��ȯ�Ѵ�.
//idx�� 0�϶� idx2�� 0~size���� �����ϸ鼭 �ּҰ��� Ȯ���� �ڿ� �װͰ� list[0]�� swap�Լ��� ��ȯ
//�״��� list[1]�� list[0]�� ������ ���� ���� ���ҿ� ��ȯ�Ѵ�.
//idx�� 1�϶� idx2�� 1~size���� �����ϸ鼭 �ּҰ��� Ȯ���� �ڿ� �װͰ� list[0]�� swap�Լ��� ��ȯ
//���� ���� ������ idx�� size���� �����ϸ鼭 �ݺ��ϱ⶧���� �տ������� ���ڸ��� �񰨼Ҽ����� ���Ľ�Ų��.

int selectionSort(int list[], int size){
	int min;
	int idx = 0;
	int idx2 = 0;
	//size-1 ������ �ϳ��� ���ؼ� �������� �ʿ䰡 ����. 
	//Boundary Condition �� ���� ����� �ʿ��ϴ�.
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
