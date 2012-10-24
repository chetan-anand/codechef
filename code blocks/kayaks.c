#include<stdio.h>
int main()
{
    int n,i,j,k;
    float p[100000],s[100000],s1[100000],s2[100000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%f %f",&p[i],&s[i]);
        s1[i]=s[i]/p[i];
        sort(s1);
        for(j=0;j<n/2;j++)
        {
            s2[j]=s1[j]+s1[n-j-1];
        }
    }


    return 0;
}
