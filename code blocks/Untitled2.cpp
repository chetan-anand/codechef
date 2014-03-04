#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int mat[10][10];
long long int colors,row,col,ans;


bool lok(long long int r, long long int c, long long int n)
{
    if(c == 0){return true;}
    if(mat[r][c - 1] != n){return true;}
    return false;
}

bool rok(long long int r, long long int c, long long int n)
{
    if(c == col - 1){return true;}
    if(mat[r][c + 1] != n){return true;}
    return false;
}

bool tok(long long int r, long long int c, long long int n)
{
    if(r == 0){return true;}
    if(mat[r - 1][c] != n){return true;}
    return false;
}

bool bok(long long int r, long long int c, long long int n)
{
    if(r == row - 1){return true;}
    if(mat[r + 1][c] != n){return true;}
    return false;
}




bool valid(long long int r, long long int c, long long int n)
{
    return(lok(r, c, n) && rok(r, c, n) &&  tok(r, c, n) &&  bok(r, c, n));
}



void solve(long long int r,long long int c)
{
    for(long long int i=1;i<=colors;i++)
    {
        if(valid(r,c,i))
        {
            mat[r][c]=i;
            if(r== row-1 && c == col-1)
            {
                if(ans>=mod){ans=ans%mod;}
                ans=ans+1;
            }
            else if(r==row-1){solve(0,c+1);}
            else{solve(r+1,c);}
        }
    }
    mat[r][c]=0;
}




int main()
{
    long long int t,i,j,k;

    scanf("%lld",&t);
    while(t--)
    {
        ans=0;
        memset(mat,0,sizeof(mat));
        scanf("%lld %lld %lld",&row,&col,&colors);
        solve(0,0);
        printf("%lld\n",ans);
    }

    return 0;
}
