#include<bits/stdc++.h>
using namespace std;
int mat[1000][1000];
int visited[1000]={0};
int min1=10000000;
struct node
{
    int u;
    int wt;
    int s1;
    node(int x,int wgt,int s)
    {
         u=x;
         wt=wgt;
         s1=s;
    }
};
int bfs(int s,int n)
{
     int sum,i;
     queue<node>q;
     q.push(node(s,0,0));
     visited[s]=1;
     while(!q.empty())
     {
          node p=q.front();
          q.pop();
          for(i=0;i<n;i++)
          {
             if(mat[p.u][i] && i==s)
             {
                 sum=p.s1+mat[p.u][i];
                 if(min1>sum)
                    min1=sum;
             }
             else if(visited[i]==0 && mat[p.u][i])
             {
                 sum=p.s1+mat[p.u][i];
                 q.push(node(i,mat[p.u][i],sum));
                 visited[i]=1;
             }
          }
     }
     return min1;
}
int gcd(int a,int b)
{
    if(b==0)
      return a;
    return gcd(b,a%b);
}
int main()
{
    int n,i,j,cnt,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
                        scanf("%d",&mat[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        cnt=bfs(i,n);
        if(cnt<min1)
          min1=cnt;
        for(j=0;j<n;j++)
         visited[j]=0;
    }
    x=gcd(min1,n);
    min1=min1/x;
    n=n/x;
    printf("%d/%d\n",min1,n);
    return 0;
}

