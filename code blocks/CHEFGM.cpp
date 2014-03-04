#include<stdio.h>
#include<algorithm>
int main()
{
    unsigned long long t,i,j,k,temp,ni,count,flag,prev,x[100];
    bool tick;
    double game;
    scanf("%llu",&t);
    while(t--)
    {
        scanf("%llu",&k);
        game=(double)0;
        //if(k==0){printf("DON'T PLAY\n");continue;}
        for(i=0;i<k;i++)
        {
            scanf("%llu",&ni);
            if(ni==0){continue;}
            for(j=0;j<ni;j++)
            {
                scanf("%llu",&x[j]);
            }
            std::sort(x,x+ni);
            count=0;
            tick=false;
            for(j=0;j<ni;j++)
            {
                temp=x[j];
                if(temp%2==0){flag=0;}
                else{flag=1;}
                if(j==0){prev=flag;}
                else{if(prev!=flag){tick=true;}}
                if(tick){count++;}
                if(flag==0)
                {
                    game=game+(double)1/(double)((unsigned long long)1<<count);
                }
                else{
                    game=game-(double)1/(double)((unsigned long long)1<<count);
                }
            }
        }
        if(game==(double)0){printf("DON'T PLAY\n");}
        else if(game>(double)0){printf("EVEN\n");}
        else{printf("ODD\n");}
    }

	return 0;
}

