#include<stdio.h>
#include<stdlib.h>

int** make2darray(int m, int n){
	int** rows;
	rows = (int**)malloc(sizeof(int*)*m);
	for (int i = 0; i < m; i++){
		rows[i] = (int*)malloc(sizeof(int)*n);
	}
	return rows;
}

void print2dArray(int** arr, int rowNum, int colNum){
	for (int i = 0; i < rowNum; i++){
		for (int j = 0; j < colNum; j++){
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	int m, n;
	int** arr;
	printf("input m, n: ");
	scanf("%d %d", &m, &n);
	arr = make2darray(m, n);
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			arr[i][j] = i*n + j;
		}
	}
	print2dArray(arr, m, n);

	return 0;
}