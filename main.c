#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))

int issafe(int row, int col, int **board, int size);
int search(int row, int size,int **board);

//var
int count = 0;

int main(int argc,char* argv[])
{
    int **board;
    int size = 13;
    board = (int **)malloc(sizeof(int *)*size);
    for(int i=0;i<size;i++)
    {
        board[i] = (int *)malloc(sizeof(int)*size);
    }
    
    search(0,size,board);
    printf("%d\n",count);

}

int issafe(int row, int col, int **board, int size)
{
   
        for(int i = 0;i<row;i++)
        {
            if(board[i][col] == 1)return 0;
        }

        for(int i = row,j = col;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j] == 1)return 0;
        }

        for(int i = row,j = col;i>=0&&j<size;i--,j++)
        {
            if(board[i][j] == 1)return 0;
        }
    return 1;

}

int search(int row, int size, int **board)
{
    if(row >=size)return 1;
    
        for(int k = 0;k< size;k++)
        {
            //在这里可以剪枝，不过if好像不太好
            /*
            if(row>0)
            {
                if(board[row-1][k] == 1) continue;
                if(k>0)
                {
                    if(board[row-1][k-1] == 1)continue;
                }
                if(k+1<size)
                {
                    if(board[row-1][k+1] == 1)continue;
                }
                
            }
            */
            
        
            if(issafe(row,k,board,size))
            {
                board[row][k] = 1;
                if(search(row+1,size,board)==1)
                {
                    
                        count++;
                }
                board[row][k] = 0;
            }
        }
}