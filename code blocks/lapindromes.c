#include<stdio.h>
#include<string.h>
#define fill(a, val) memset(a, val, sizeof(a))
int main()
{
    int i,t,temp,cnt;
    int k[1100];
    char s[1100];
    scanf("%d",&t);
    while(t--)
    {
        fill(k,0);
        scanf("%s",&s);
        temp=strlen(s)/2;
        for(i=0;i<temp;i++)
        {
            k[s[i]]++;
        }
        /*for(i=96;i<=123;i++)
        {
            printf("%d\n",k[i]);
        }*/
        for(i=strlen(s)-1;i>strlen(s)-1-temp;i--)
        {
            if(k[s[i]]>0){k[s[i]]--;}
        }

        /*printf("--------------------\n");
        for(i=96;i<=123;i++)
        {
            printf("%d\n",k[i]);
        }*/
        cnt=0;
        for(i=96;i<=123;i++)
        {
            cnt=cnt+k[i];
        }
        if(cnt==0){printf("YES\n");}
        else{printf("NO\n");}
    }
    return 0;
}
