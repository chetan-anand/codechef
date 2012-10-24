#include<stdio.h>
long int rev(long int x)
{
    int i,j;
    long int ans=0;
    for(i=0;x!=0;i++)
    {
        j=x%10;
        ans=10*ans+j;
        x=x/10;
    }
    return ans;
}
int main()
{
    int i,t,j;
    long int n,s,r;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%ld",&n);
        for(j=1;;j++)
        {
            r=rev(n);
            s=r+n;
            if(rev(s)==s){break;}
            else{n=s;}
        }
        printf("%d %ld\n",j,s);
    }
    return 0;
}
