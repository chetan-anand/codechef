#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j,k;
    char sdna[100],tdna[100];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",sdna);
        scanf("%s",tdna);
        scanf("%d",&k);
        int cnt=0;
        for(i=0;sdna[i]!='\0';i++)
        {
            if(sdna[i]!=tdna[i]){cnt++;}
            if(cnt>k){break;}
        }
        if(cnt>k){printf("IMPOSSIBLE\n");}
        else{printf("POSSIBLE\n");}
    }
    return 0;
}
