#include<stdio.h>
#include<stdlib.h>

//기본 아이디어
//스택을 활용한 미로찾기
//현 위치에서 이동가능한 유효한 길을 확인하면 
//현 위치를 스택에 저장하고 그 이동한다.
//위와 같은 이동을 반복하다가 유효한 길이 없는경우
//스택을 팝하면서 뒤로 이동하고 다시 유효한 길을 체크한다.

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

//루트를 저장하는 스택 구조체
//탑값과 루트의 배열이 포함된다.

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

//현 위치에서 8방향의 가능한 길중 유효한것을 체크하기 위한
//Dir(방향)과  그에 맞는 좌표이동을 마련한다.

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

//미로를 시각적으로 표현한다.
//현 위치에 & 를 놓고
//벽(maze에서 1)에는 블럭을
//지나온 길에는 발자국을 찍었다.

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
			else if (maze[i][j]) printf("%3s", "ㅁ");
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
	//초기화
	move dirMove[MAX_DIR_NUM] = { 0, };
	rStack mazeRoute = createStack();
	route current;
	int nextRow = 1, nextCol = 1;

	//기본 알고리즘
	/*
	1.스택 엠티인가 ? (노 웨이 투 아웃)
	2.종점에 도달했는가 ? (ㅇㅋ 끝)
	ㅡㅡㅡ종료ㅡㅡㅡㅡ
		3.dir이 8인가 ?(갈 수 있는 방향이 없는가?)
		ㅡㅡㅡpopㅡㅡㅡㅡ
			4.maze(newrow, newcol)이 1인가 ?
			  mark(newrow, newcol)이 1인가 ?(현재 방향에서 갈 수 없는가?)
			ㅡㅡㅡdir++ㅡㅡㅡ
			5.둘다 0인가?(가도되는가?)
			ㅡㅡcurrent를 스택에 저장하고 newrow newcol 0으로 변경ㅡㅡ
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

