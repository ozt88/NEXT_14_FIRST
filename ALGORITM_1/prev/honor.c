#include<stdio.h>
//honor honor����� �����ϴ� �Լ�. a[n]�� �迭�� arr[n] ǥ��
int honor(int arr[], int x, int start, int size);
int main(void)
{
	int input;
	int arr[] = { 1, 1, 1, 1, 1};
	int size = sizeof(arr) / sizeof(int);
	printf("input X:");
	scanf("%d", &input);
	printf("%d\n",honor(arr, input, 0, size));
	return 0;
}
int honor(int arr[], int x, int start, int size)
{
	if (size-1 == start) return arr[start];
	return arr[start] + honor(arr, x, start + 1, size)*x;
}