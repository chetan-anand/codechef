#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,cnt;
    char str[1000],ch;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%s",str);
        for(i=0;str[i]!='\0';i++)
        {
            cnt=cnt+str[i];
        }
        ch=cnt/i;
        printf("%c\n",ch);
    }
    return 0;
}
