#include<stdio.h>
#include<string.h>
#define mod 1000000007
int     fact(int x)
{
    int ans=1,i;
    for(i=1;i<=x;i++)
    {
        ans=ans*i;
    }
    return ans;
}

int main()
{
    int cnt[200],temp,num,den,i;
    char s[100010];
    memset(cnt,0,sizeof(cnt));
    scanf("%s",s);
    int len=strlen(s);
    for(i=0;i<len;i++){cnt[s[i]]++;}
    temp=0;
    for(i=97;i<=122;i++)
    {
        if((cnt[i]%2)!=0)
        {
            temp++;
            if(temp>1){printf("0");return 0;}
        }
    }
    len=len/2;
    num=fact(len);
    den=1;
    for(i=97;i<=122;i++)
    {
        if(cnt[i]!=0)
        {
            cnt[i]=fact(cnt[i]/2);
            den=den*cnt[i];
        }
    }
    printf("%d",num/den);
    return 0;
}
