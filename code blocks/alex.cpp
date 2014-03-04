#include<iostream>
#include<stdio.h>
using namespace std;
int ch[101][101];
int n;
int m;
int ans;
int dfs(int i,int j,int dir,int k)
{
    if(ch[i][j] || i>=n || i<0 || j<0 || j>=m) return 0;
    ch[i][j]=k;
    if(dir==0)
    {
            if(dfs(i,j+1,1,k+1))return 1;
          if(dfs(i+1,j,2,k+1))return 1;
          if(dfs(i,j-1,3,k+1))return 1;
          if(dfs(i-1,j,4,k+1))return 1;
    }
    if(dir==4)
    {
          if(dfs(i,j+1,1,k+1))return 1;
          if(dfs(i+1,j,2,k+1))return 1;
          if(dfs(i,j-1,3,k+1))return 1;
          if(dfs(i-1,j,4,k+1))return 1;
    }
    if(dir==1)
    {
          if(dfs(i+1,j,2,k+1))return 1;
          if(dfs(i,j-1,3,k+1))return 1;
          if(dfs(i-1,j,4,k+1))return 1;
          if(dfs(i,j+1,1,k+1))return 1;
    }
    if(dir==2)
    {
          if(dfs(i,j-1,3,k+1))return 1;
          if(dfs(i-1,j,4,k+1))return 1;
          if(dfs(i,j+1,1,k+1))return 1;
          if(dfs(i+1,j,2,k+1))return 1;
    }
    if(dir==3)
    {
          if(dfs(i-1,j,4,k+1))return 1;
          if(dfs(i,j+1,1,k+1))return 1;
          if(dfs(i+1,j,2,k+1))return 1;
          if(dfs(i,j-1,3,k+1))return 1;
    }
    return 1;
}
int main()
{
    int ans1;
    //cin>>n>>m;
    for(n=2;n<=20;n++)
    {
        for(m=2;m<=20;m++)
        {
        ans=-1;
    dfs(0,0,0,1);
    for(int i=0;i<n;i++)
    {
                    for(int j=0;j<m;j++)
                    {
                                    ans=max(ans,ch[i][j]);
                    }
    }
    cout<<ans<<endl;
    if(n==1 || m==1) {
            //printf("n=%d m=%d  %d\n",n,m,n+m-1);
      //cout<<(n+m-1) ;
      ans1=n+m-1;
   }
   else if((n%2)&&(m%2)) {
        //printf("n=%d m=%d  %d\n",n,m,n+m-1);
    //cout<<(n*m);
    ans1=n*m;
   }
   else if(n%2) {
       //printf("n=%d m=%d  %d\n",n,m,n+m-1);
       //cout<<((n*m)-((n-2)*(m-2)));
       ans1=((n*m)-((n-2)*(m-2)));
    }
   else {
       //printf("n=%d m=%d  %d\n",n,m,n*2);
     //cout<<(n*2);
     ans1=(n*2);
   }
   if(ans!=ans1){printf("n=%d m=%d ans=%d ans1=%d\n",n,m,ans,ans1);}
        }
    }
}
