#include<stdio.h>
#include<stdlib.h>

//�⺻ ���̵��
//������ Ȱ���� �̷�ã��
//�� ��ġ���� �̵������� ��ȿ�� ���� Ȯ���ϸ� 
//�� ��ġ�� ���ÿ� �����ϰ� �� �̵��Ѵ�.
//���� ���� �̵��� �ݺ��ϴٰ� ��ȿ�� ���� ���°��
//������ ���ϸ鼭 �ڷ� �̵��ϰ� �ٽ� ��ȿ�� ���� üũ�Ѵ�.

#define MAX_ROUTE_NUM 144
#define MAX_DIR_NUM 8
#define ROW_NUM 12
#define COL_NUM 12
#define EXIT_ROW 10
#define EXIT_COL 10

typedef struct Route{
	int row;
	int col;
	int dir;
}route;

//��Ʈ�� �����ϴ� ���� ����ü
//ž���� ��Ʈ�� �迭�� ���Եȴ�.

typedef struct RouteStack{
	int top;
	route Arr[MAX_ROUTE_NUM];
}rStack;

typedef struct Move{
	int rowMove;
	int colMove;
}move;

char maze[ROW_NUM][COL_NUM] = 
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1 },
	{ 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
	{ 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1 },
	{ 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1 },
	{ 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

char mark[ROW_NUM][COL_NUM] = { 0, };

rStack createStack()
{
	rStack newStack;
	newStack.top = -1;
	memset(newStack.Arr, 0, sizeof(route)*MAX_ROUTE_NUM); 
	return newStack;
}
int isFull(rStack stack)
{
	return(stack.top >= MAX_ROUTE_NUM - 1);
}

int isEmpty(rStack stack)
{
	return(stack.top == -1);
}

int push(rStack* stackPtr, int rowNum, int colNum, int dirNum)
{
	if (isFull(*stackPtr))
	{
		printf("STACK OVER FLOW!!\n");
		return -1;
	}
	else
	{
		stackPtr->top++;
		stackPtr->Arr[(stackPtr->top)].row = rowNum;
		stackPtr->Arr[(stackPtr->top)].col = colNum;
		stackPtr->Arr[(stackPtr->top)].dir = dirNum;
	}
}

route pop(rStack* stackPtr)
{
	route pop;

	if (isEmpty(*stackPtr))
	{
		printf("STACK EMPTY ERROR!!\n");
		return pop;
	}
	else
	{
		pop.row = stackPtr->Arr[stackPtr->top].row;
		stackPtr->Arr[stackPtr->top].row = 0;
		pop.col = stackPtr->Arr[stackPtr->top].col;
		stackPtr->Arr[stackPtr->top].col = 0;
		pop.dir = stackPtr->Arr[stackPtr->top].dir;
		stackPtr->Arr[stackPtr->top].dir = 0;
		stackPtr->top--;

		return pop;
	}
}

//�� ��ġ���� 8������ ������ ���� ��ȿ�Ѱ��� üũ�ϱ� ����
//Dir(����)��  �׿� �´� ��ǥ�̵��� �����Ѵ�.

int createDirMove(move* dirMove)
{

	dirMove[0].rowMove = -1;
	dirMove[0].colMove = 0;

	dirMove[1].rowMove = -1;
	dirMove[1].colMove = 1;

	dirMove[2].rowMove = 0;
	dirMove[2].colMove = 1;

	dirMove[3].rowMove = 1;
	dirMove[3].colMove = 1;

	dirMove[4].rowMove = 1;
	dirMove[4].colMove = 0;

	dirMove[5].rowMove = 1;
	dirMove[5].colMove = -1;

	dirMove[6].rowMove = 0;
	dirMove[6].colMove = -1;

	dirMove[7].rowMove = -1;
	dirMove[7].colMove = -1;

	return 0;
}

//�̷θ� �ð������� ǥ���Ѵ�.
//�� ��ġ�� & �� ����
//��(maze���� 1)���� ����
//������ �濡�� ���ڱ��� �����.

void printMaze(char maze[][COL_NUM], char mark[][COL_NUM], route current)
{
	system("cls");
	printf("\n\t\tMAZE\n");
	for (int i = 0; i < ROW_NUM; i++)
	{
		for (int j = 0; j < COL_NUM; j++)
		{
			if (i == current.row && j == current.col) printf("%3c", '&');
			else if (i == EXIT_ROW && j == EXIT_COL) printf("%3s", "EX");
			else if (maze[i][j]) printf("%3s", "��");
			else if (mark[i][j]) printf("%3s", "..");
			else printf("%3c", ' ');
		}
		printf("\n");
	}
	fflush(stdin);
	getchar();
	return;
}

int main(void)
{
	//�ʱ�ȭ
	move dirMove[MAX_DIR_NUM] = { 0, };
	rStack mazeRoute = createStack();
	route current;
	int nextRow = 1, nextCol = 1;

	//�⺻ �˰���
	/*
	1.���� ��Ƽ�ΰ� ? (�� ���� �� �ƿ�)
	2.������ �����ߴ°� ? (���� ��)
	�ѤѤ�����ѤѤѤ�
		3.dir�� 8�ΰ� ?(�� �� �ִ� ������ ���°�?)
		�ѤѤ�pop�ѤѤѤ�
			4.maze(newrow, newcol)�� 1�ΰ� ?
			  mark(newrow, newcol)�� 1�ΰ� ?(���� ���⿡�� �� �� ���°�?)
			�ѤѤ�dir++�ѤѤ�
			5.�Ѵ� 0�ΰ�?(�����Ǵ°�?)
			�Ѥ�current�� ���ÿ� �����ϰ� newrow newcol 0���� ����Ѥ�
	*/
	createDirMove(dirMove);
	push(&mazeRoute, nextRow, nextCol, 0);

	while(!isEmpty(mazeRoute))
	{	
		current = pop(&mazeRoute);
		printMaze(maze, mark, current);
		mark[current.row][current.col] = 1;
		while (current.dir < 8)
		{
			nextRow = current.row + dirMove[current.dir].rowMove;
			nextCol = current.col + dirMove[current.dir].colMove;

			if (nextRow == EXIT_ROW && nextCol == EXIT_ROW)
			{
				printMaze(maze, mark, current);
				printf("Find it!\n");
				return 0;
			}
			else if (maze[nextRow][nextCol] || mark[nextRow][nextCol]) current.dir++;
			else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol])
			{
				push(&mazeRoute, current.row, current.col, current.dir + 1);
				current.row = nextRow;
				current.col = nextCol;
				current.dir = 0;
				mark[current.row][current.col] = 1;
				printMaze(maze, mark, current);

			}
			else
			{
				printf("ERROR!!\n"); 
				return -1;
			}
		}
	}

	printf("No way to OUT...\n");
	return 0;

}

