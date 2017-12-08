#include<stdio.h>

#define min(a,b) return

int issafe(int row,int col,int **board,int size);
void search(int i,int size);

int main()
{

}

int issafe(int row,int col,int **board,int size)
{
    for(int i=0;i<size;i++)
    {
        if(board[row][i]==1||board[i][col]==1)return 0;
    }

    int reset = 

    return 1;
}

void search(int i,int size)
{

}