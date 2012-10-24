#include<stdio.h>
#include<string.h>
int main()
{
    int t,n,c,ak,j,cnt;
    char b[50000];
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%d %d",&n,&c);
        getchar();
        gets(b);
        for(j=0;b[j]!='\0';j++)
        {
            if(b[j]==' '||j==0)
            {sscanf(b+j,"%d",&ak);cnt=cnt+ak;}
        }
        if(cnt<=c){printf("Yes\n");}
        else{printf("No\n");}
    }
    return 0;
}
