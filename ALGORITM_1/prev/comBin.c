#include<stdio.h>
//�־��� ���տ��� ������ ��� ������ ����� ���� ����ϴ� �Լ� ����
//input : ������ ����(�迭), (������ ����)
//output : ���տ��� ������ ��� ������ ����� ��
//printCombi ��� ������ ����ϴ� �Լ�
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

//����Լ�
void printArray(int arr[], int length)
{
	for (int i = 0; i<length; i++) { if (arr[i] != 0)printf("%2d", arr[i]); }
	printf("\n");
}

//printCombi �־��� �迭���� ������ ������ ���
//arr[]=������ ������ �迭
//combi[]=������ ����� �迭
//start ������
//choice ������ ����, length �迭�� ���� 
//C(4,3)�̸� length �� 4�̰� choice�� 3�̴�.
//�۵����: 
//N������ R���� �����Ҷ� start��° �ִ� ���Ҹ� �������� �����ϸ� ���� ���ҵ鿡�� R-1���� �����Ѵ�.
//start�� �ϳ� �� �ø��� choice�� �ϳ� ���δ�.
//start�� ���Ҹ� ���� ������ ���� ���ҵ鿡�� R���� �ְ� �Ѵ�.
//start�� �ø��� choice�� ������ �ʴ´�. (�̶� �������� �ʴ� ���� �����ϱ� ���ؼ� 0�� combi�� �ִ´�.)
//choice�� ������ 0�ΰ�� ������ �Ϸ� �Ǿ����Ƿ� ����ϰ� �����Ѵ�.
//choice�� �پ���� �ʴ� �ι��� ����Լ��� ���� choice�� ������ 0�� �ȵǴ� ��찡 �߻��ϹǷ�
//start�� length�� ��������, ���δ� üũ�� ���̹Ƿ� �׳� �����Ѵ�.

void printCombi(int arr[], int combi[], int start, int choice, int length)
{
	if (choice == 0) {printArray(combi, length); return;}
	if (start == length) return;
	combi[start] = arr[start];
	printCombi(arr, combi, start + 1, choice - 1, length);
	combi[start] = 0;
	printCombi(arr, combi, start + 1, choice, length);
}