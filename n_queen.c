#include <stdio.h>

#define N 3
int count = 0;
void display(int board[N][N]);
int solveNQ(int board[N][N], int col);
int isSafePos(int board[N][N], int row, int col);

void display(int board[N][N]) 
{
	int r, c;
	for(r = 0; r < N; r++) 
    {
		for(c = 0; c < N; c++) 
        {
			printf("%d ", board[r][c]);
		}
		printf("\n");
	}
}

int solveNQ(int board[N][N], int col) 
{
	//variables
	int i;
	
	if(col >= N)
    {
		return 1;
	}

	for(i = 0; i < N; i++) 
    {
        if(isSafePos(board, i, col))
        {
            board[i][col] = 1;

			if(solveNQ(board, col+1) == 1) 
            {
				count++;
                for(int a=0;a<N;a++)
                {
                    for(int b=0;b<N;b++)
                    {
                        printf("%d ",board[a][b]);
                    }
                     printf("\n");
                }
               
			}

			board[i][col] = 0;
		}
	}
}

int isSafePos(int board[N][N], int row, int col)
{
	int r, c;

	for(c = 0; c < col; c++) 
    {
		if(board[row][c] == 1) 
        {
			return 0;
		}
	}


	for(r = row, c = col; r >= 0 && c >= 0; r--, c--) 
    {
		if(board[r][c] == 1) 
        {
			return 0;
		}
	}


	for (r = row, c = col; c >= 0 && r < N; r++, c--) 
    {
		if (board[r][c] == 1) 
        {
			return 0;
		}
	}

	return 1;
}

int main(void) 
{

	int board[N][N] = {0};

    solveNQ(board, 0);

	printf("%d\n",count);

	return 0;
}