#include<stdio.h>

int calc(int row,int col)
{
    static int ans=0;
    if(row==1){return col;}
    if(col==1){return row;}
    if(row%2==0)
    {
        ans=ans+2*row;
        return ans;
    }
    if(row%2!=0)
    {
        ans=ans+2*row+calc(col-2,row);
        return ans;
    }
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    printf("%d\n",calc(n,m));
    return 0;
}
