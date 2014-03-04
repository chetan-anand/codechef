#include<bits/stdc++.h>
using namespace std;

int mat[1100][1100];
int c[1100][1100];
int n,m,k,xi,yi;
//////////////////////////////////
/**
n= number of column
m= number of rows

**/

int findMax(int* height)
{

}

int maximalRectangle()
{
    int i,j,k;
    int maxRect=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(mat[i][j]==0)
            {
                c[i][j]=0;
            }
            else
            {
                if(i>0)
                {
                    cache[i][j]=cache[i-1][j]+1;
                }
                else
                {
                    cache[i][j]=1;
                }
            }
        }
        int rowMax=findMax(c[i]);
        if(rowMax>maxRect)
        {
            maxRect=rowMax;
        }
    }
    return maxRect;
}


///////////////////////////////////
int main()
{
    freopen("i.txt","r",stdin);
    cin>>n>>m>>k;
    memset(mat,0,sizeof(mat));
    memset(c,0,sizeof(c));
    while(k--)
    {
        cin>>xi>>yi;
        mat[xi][yi]=1;
    }




    fclose(stdin);
    return 0;
}
