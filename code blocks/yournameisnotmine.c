#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,t,cnt,temp,flag;
    char m[270000],w[270000],ch;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %s",m,w);
        temp=0;
        cnt=0;
        flag=0;
        for(i=0;m[i]!='\0';i++)
        {
            for(j=temp;w[j]!='\0';j++)
            {
                if(m[i]==w[j])
                {
                    temp++;
                    cnt++;
                    break;
                }
            }
        }
        if(cnt==i)
        {
            printf("YES\n");
        }
        else
        {
            temp=0;
            cnt=0;
            for(i=0;w[i]!='\0';i++)
            {
                for(j=temp;m[j]!='\0';j++)
                {
                    if(w[i]==m[j])
                    {
                        temp++;
                        cnt++;
                        break;
                    }
                }
            }
            if(cnt==i)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}
