#include<stdio.h>
#include<string.h>
int main()
{
    int cnt,i;
    char ch[102],ch1;
    cnt=0;
    //printf("a\n");
    scanf("%s",&ch);
    getchar();
    //printf("b\n");
    scanf("%c",&ch1);
    //printf("c\n");
    for(i=0;ch[i]!='\0';i++)
    {
        if(ch1==ch[i]){cnt++;}
    }
    printf("%d",cnt);
    return 0;
}
