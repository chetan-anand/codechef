#include<stdio.h>
int cnt=0,N,M;
void chess(int board[100][100], int x);
bool check(int board[100][100], int x, int col);
int main()
{
    int board[100][100] = {0};
    printf("Eneter the side size of chess board=");
    scanf("%d",&N);
    printf("enter the no of queens=");
    scanf("%d",&M);
    chess (board, 0);
    printf("the total no of accepted configuration is %d\n",cnt);
    return 0;
}
bool check(int board[100][100], int x, int col)
{
    int i,j;
    for (i=0; i<N; ++i)
    {
        if (board[x][i])
        return false;
    }
    for (i=0; i<N; ++i)
    {
        if (board[i][col])
        return false;
    }
    for (i=x,j=col;i>=0&&j>=0;i--, j--)
    {
        if (board[i][j])
        return false;
    }
    for (i = x, j = col; i < N && j >= 0; ++i, --j)
    {
        if (board[i][j])
        return false;
    }
    for (i = x, j = col; i >= 0 && j < N; i--, ++j)
    {
        if (board[i][j])
        return false;
    }
    for (i = x, j = col; i < N && j < N; ++i, ++j)
    {
    if (board[i][j])
        return false;
    }
    return true;
}
void chess(int board[100][100], int x)
{
    int i;
    if (x == M)
    {
        cnt++;//printf("%d\n",cnt);
        return;
    }
    for(i=0; i<N; ++i)
    {
    if(check(board, x, i))
        {
            board[x][i] = 1;
            chess(board, x+1);
        }
        board[x][i] = 0;
    }
}

