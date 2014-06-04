#include<stdio.h>

//1) ���� key�� �־����� �־��� key�� �� �迭�� �ִ��� �������� �˻��ϰ� �ִٸ� ���� �� �� ���� ���ʿ� �ִ� ���� ��ġ�� ��ȯ�ϴ� �Լ�
//�Լ� �̸� : searchLeftmost()
//2) ���� �� �� ���� �����ʿ� �ִ� ���� ��ġ�� ��ȯ�ϴ� �Լ� 
//�Լ� �̸� : searchRightmost()
//3) key�� ���� ���� ������ ������ ��ȯ�ϴ� �Լ�
//�Լ� �̸� : getNumOf()
//testMain ���� 3���� �Լ��� ����� �۵��ϴ��� Ȯ���ϴ� �Լ�

int searchLeftMost(int list[], int size, int key);
int searchRightMost(int list[], int size, int key);
int getNumOf(int list[], int size, int key);
void testMain(int list[], int size, int key);

int main(void)
{
	int list[10] = { 1, 3, 8, 8, 8, 8, 8, 10, 25, 30 };
	int left, right;
	int key = 8;
	int size = sizeof(list) / sizeof(int);
	int test = 0;
	testMain(list, size, key);
	return 0;
}

int searchLeftMost(int list[], int size, int key)
{
	int middle = 0;
	int left = 0;
	int right = size - 1;
	for (int i = 0;; i++)
	{
		middle = (left + right) / 2;
		if (list[middle] == key)
		{
			right = middle;
			if (list[middle - 1] != key) return middle;
			else continue;
		}
		else if (list[middle] < key) left = middle + 1;
		else if (list[middle]>key) right = middle - 1;
	}
	return -1;
}

int searchRightMost(int list[], int size, int key)
{
	int middle = 0;
	int left = 0;
	int right = size - 1;
	for (int i = 0;; i++)
	{
		middle = (left + right) / 2;
		if (list[middle] == key)
		{
			left = middle;
			if (list[middle + 1] != key) return middle;
			else continue;
		}
		else if (list[middle] < key)
		{
			left = middle + 1;
		}
		else if (list[middle]>key)
		{
			right = middle - 1;
		}
	}
	return -1;
}

int getNumOf(int list[], int size, int key){
	if (searchRightMost(list, size, key) != -1){
		return searchRightMost(list, size, key) - searchLeftMost(list, size, key)+1;
	}
	else{
		return 0;
	}
}

void testMain(int list[], int size, int key){
	if (searchLeftMost(list, size, key) == 2 && searchRightMost(list, size, key) == 6 && getNumOf(list, size, key) == 5){
		printf("CORRECT!\nexpected={2,6,5},test={%d,%d,%d}\n", searchLeftMost(list, size, key), searchRightMost(list, size, key), getNumOf(list, size, key));
	}
	else{
		printf("WRONG!\nexpected={2,6,5},test={%d,%d,%d}\n", searchLeftMost(list, size, key), searchRightMost(list, size, key), getNumOf(list, size, key));
	}
	return 0;
}
