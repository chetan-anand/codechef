#include<stdio.h>
int main()
{
    int t,i,len,cnt;
    char ch[1002];
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%d",&len);
        scanf("%s",&ch);
        for(i=0;i<len;i++)
        {
            if(i==0){if(ch[i]=='1'){cnt++;}else{if(ch[i+1]=='1'){cnt++;}}}
            else
            {
                if(ch[i]=='1'){cnt++;}
                else
                {
                    if(ch[i-1]=='1'||ch[i+1]=='1'){cnt++;}
                }
            }
        }
        printf("%d\n",len-cnt);
    }

    return 0;
}
