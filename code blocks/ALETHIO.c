#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int i,j,k,maxv=0,flag;
    char s[1100],ch;
    scanf("%s",s);
    flag=0;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]<=90 && s[i]>=65)
        {
            flag=1;
            ch=s[i];
            s[i]='9';
            //puts(s);
            for(j=0;j<strlen(s);j++)
            {
                if(atoi(s+j)>maxv){maxv=atoi(s+j);}
                //printf("maxv=%d\n",maxv);
            }
            s[i]=ch;
            //puts(s);
        }
    }
    if(flag==1){printf("%d",maxv);}
    else{printf("%d",atoi(s));}
    return 0;
}
