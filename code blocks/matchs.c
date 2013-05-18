#include<stdio.h>
#include<string.h>
#define max 100009
void process(int **m,int *a,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        m[i][i]=i;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[m[i][j-1]]<a[j]){m[i][j]=m[i][j-1];}
            else{m[i][j]=j;}
        }
    }
}

int main()
{
    int i,j,k;
    int m[max][max]
    reuturn 0;
}
