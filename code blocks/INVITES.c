#include<stdio.h>
#include<string.h>


int main()
{
    char p[5000006];
    int i,j,k,t,day,cnt,maxv;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",p);
        day=maxv=0;j=0;
        for(i=0;p[i]!='\0';i++)
        {
            cnt=0;
            if(p[i]=='.')
            {
                cnt++;
                for(j=i+1;p[j]!='#';j++)
                {
                    cnt++;

                }
                //printf("j=%d\n",j);
                i=j;
                //printf("cnt=%d\n",cnt);
                if(cnt>maxv){maxv=cnt;day++;}
            }
            //printf("j=%d\n",j);
            //printf("i=%d\n",i);
        }
        printf("%d\n",day);
    }
    return 0;
}
