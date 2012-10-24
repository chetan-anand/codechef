#include<stdio.h>
int main()
{
    int i,n,cnt,t,a,b,sum,j;
    char ch[11];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        sum=0;
        for(j=a;j<=b;j++){
        cnt=0;
        for(i=0;ch[i]!='\0';i++)
        {
            n=ch[i]-48;
            if(n%2==0){n*=2;}
            cnt+=n;
        }
        printf("%d\n",cnt);
        cnt%=10;
        sum+=cnt;
        }
        printf("%d\n",sum);

    }
    return 0;
}
