#include <stdio.h>
#include <stdlib.h>
#include "board.h"

#define N_BOARD				15
#define N_COINPOS			12
#define MAX_COIN			4
#define MAX_SHARKSTEP		6
#define SHARK_INITPOS		-4


static int board_status[N_BOARD];
static int board_coin[N_BOARD];

static int board_sharkPosition;

int board_initBoard(void)
{
	int i;
	for (i=0;i<N_BOARD;i++)
	{

		board_status[i] = BOARDSTATUS_OK;
		board_coin[i] = 0;
	}
	
	board_sharkPosition = SHARK_INITPOS;
	
	// coin 할당
	for (i=0;i<N_COINPOS;i++)
	{
		int flag = 0;
		while (flag == 0)
		{
			int allocPos = rand()%N_BOARD;
			if (board_coin[allocPos] == 0)
			{
				board_coin[allocPos] = rand()%MAX_COIN+1;
				flag = 1;
			} 
		}
	} 
}


int board_initboard(void);

// 현재 보드판의 상태를 출력 
int board_printBoardStatus(void)
{
	int i;
	printf("-------------------------- BOARD STATUS --------------------------\n");
	for (i=0;i<N_BOARD;i++)
	{
		printf("|");
		if (board_status[i] == BOARDSTATUS_NOK)
			printf("X");
		else
			printf("O");
	}
	printf("|\n");
	printf("------------------------------------------------------------------\n");
}

// 파손이 되었는지의 여부를 출력 
int board_getBoardStatus(int pos)
{
	return board_status[pos];
}

// 보드칸에 있는 동전을 줍는 동작 
int board_getBoardCoin(int pos)
{
	int coin = board_coin[pos];
	board_coin[pos] = 0; 
	return coin;
}

// int board_getSharkPosition(void);
int board_stepShark(void)
{
	int step = rand()%MAX_SHARKSTEP +1;
	int i;
	for (i=board_sharkPosition+1;i<=board_sharkPosition+step;i++)
	{
		if (i >=0 && i < N_BOARD)
			board_status[i] = BOARDSTATUS_NOK;
	}
	board_sharkPosition += step;
	return board_sharkPosition;
}


// int board_stepShark(void);
