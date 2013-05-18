#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j,flag1,flag2;
    char r[1002],s[1002],ch;
    long long int cnt1,cnt2,cnt1b,cnt2b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %s",r,s);
        cnt1=cnt2=cnt1b=cnt2b=0;
        /*puts(r);
        puts(s);*/
        for(i=0;r[i]!='\0';i++)
        {
            cnt1=cnt1+r[i]*r[i];
        }

        for(i=0;s[i]!='\0';i++)
        {
            cnt2=cnt2+s[i]*s[i];
        }

        for(i=0;r[i]!='\0';i++)
        {
            if(r[i]=='-'){continue;}
            else
            {
                cnt1b=cnt1b+r[i]*r[i];
                for(j=i+1;r[j]!='\0';j++)
                {
                    if(r[i]==r[j]){r[j]='-';}
                }
            }
        }

        for(i=0;s[i]!='\0';i++)
        {
            if(s[i]=='-'){continue;}
            else
            {
                cnt2b=cnt2b+s[i]*s[i];
                for(j=i+1;s[j]!='\0';j++)
                {
                    if(s[i]==s[j]){s[j]='-';}
                }
            }
        }

        if(cnt1b==cnt2b){flag1=1;}
        else{flag1=0;}
        if(cnt1==cnt2){flag2=1;}
        else{flag2=0;}

        if(flag1==1 && flag2==1){printf("YES\n");}
        else if(flag1==1&&flag2==0){printf("NO\n");}
        else if(flag1==0){printf("YES\n");}

        /*printf("flag1=%d\n",flag1);
        printf("flag2=%d\n",flag2);
        printf("cnt1=%lld\n",cnt1);
        printf("cnt2=%lld\n",cnt2);
        printf("cnt1b=%lld\n",cnt1b);
        printf("cnt2b=%lld\n",cnt2b);*/
    }
    return 0;
}
