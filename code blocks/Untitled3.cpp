#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namepsace std;


int up(int b[1100][1100],int i,int j,int k) // maximum vertical submatrix of 1 ending at i,j.
{
    int n,count=1;
    if(i-1>=k-1 && i-1>=0)
    {
        if(b[i-1][j]!=0)
        {
            for(n=0;n<b[i-1][j];n++)
            {
                if(n<=i-k)
                    if(b[i-n-1][j]!=0)
                        count++;
                    else break;
            }
        }
    }
    return count;
}

int left(int b[1100][1100],int i,int j) // maximum horizontal submatrix of with 1 ending at i'j
{
int n,count=1;
if(j-1>=0)
{
if(b[i][j-1]!=0)
{
for(n=0;n<b[i][j-1];n++)
{
if(b[i][j-n-1]!=0)
count++;
else break;
}
}
}
return count;
}

int rect(int b[1100][1100],int i,int j,int n1,int n2,int top) // finding maximum rectangular submatrix ending at i,j if such exists
{
int num1,num2,c1=0,c2=0;
int x,y;
for(y=j;y>=0;y--)
for(x=i;x>i-n1;x--)
{
if(b[x][y]!=0)
c1++;
else break;
}
num1=c1/n1;
for(x=i;x>=top-1;x--)
for(y=j;y>j-n2;y--)
{
if(b[x][y]!=0)
c2++;
else break;
}
num2=c2/n1;
if(num1>=num2)
return num1;
else return num2;
}

int max(int p,int q,int r)
{
if(p>=q && p>=r)
return p;
else if(q>=r && q>=p)
return q;
else if(r>=p && r>=q)
return r;
}

main()
{
int N=4,M=5,K=5,Q=4;
int i,j,k,n,count,c1,c2,c3,pr;
int X[5]={2,3,1,2,1};
int Y[5]={1,2,3,4,4};
int Qi[4]={1,3,2,1};
int Qj[4]={1,4,3,4};

/**printf(" enter the numbers \n");
scanf("%d %d %d", &N, &M,&K);
printf("%d %d %d\n", N,M,K);
printf("enter the values of xi and yi \n");
for(i=0;i<K;i++)
scanf("%d %d\n", X[i], Y[i]);
for(i=0;i<K;i++)
printf("%d %d\n", X[i], Y[i]);
scanf("%d\n", &Q);
for(i=0;i<Q;i++)
scanf("%d %d\n",Qi[i],Qj[i]);**/

int A[1100][1100], B[1100][1100];
for(i=0;i<N;i++)
for(j=0;j<M;j++)
A[i][j]=1;
for(i=0;i<K;i++)
A[X[i]-1][Y[i]-1]=0;

/*
for(i=0;i<N;i++)
{
for(j=0;j<M;j++)
printf("%d ",A[i][j]);
printf("\n");
}
*/

for(k=0;k<Q;k++)
{
    pr=0;
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            B[i][j]=A[i][j];
    for(i=Qi[k]-1;i<=Qj[k]-1;i++)
    {
        for(j=0;j<M;j++)
        {
            c1=0;
            c2=0;
            c3=0;
            if(B[i][j]!=0)
        {
            c1=up(B,i,j,Qi[k]);
            c2=left(B,i,j);
            if(j-1>=0 && i-1>=Qi[k]-1 && i-1>=0)
            {
                if(B[i-1][j-1]!=0 && B[i-1][j]!=0 && B[i][j-1]!=0)
                c3=rect(B,i,j,c1,c2,Qi[k]);
                else c3=0;
            }
        }
        B[i][j]= max(c1,c2,c3);
        }
}
for(i=Qi[k]-1;i<=Qj[k]-1;i++)
    for(j=0;j<M;j++)
        if(B[i][j]>pr)
            pr=B[i][j];
            printf("%d\n",pr);
        }
        return 0;
}
