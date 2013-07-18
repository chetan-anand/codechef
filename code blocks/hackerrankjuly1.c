#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,temp;
    temp=0;
    char s[100009];
    scanf("%s",s);
    //puts(s);
    int cnt[200];
    memset(cnt,0,sizeof(cnt));
    for(i=0;i<strlen(s);i++)
    {
        cnt[s[i]]++;
    }
    for(i=97;i<=122;i++)
    {
        if(cnt[i]%2!=0){temp++;}
    }
    if(strlen(s)%2==0)
    {
        if(temp==0){printf("YES\n");}
        else{printf("NO\n");}
    }
    else
    {
        if(temp==1){printf("YES\n");}
        else{printf("NO\n");}
    }
    return 0;
}
