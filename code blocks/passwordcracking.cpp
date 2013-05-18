#include<stdio.h>
#include<string.h>
int main()
{
    char pass[400][15]={"cherrypie","mangopie","codechef","password","challenge"},ch;
    //puts(pass);
    int i,j,k,t,n,h,s[10000],maxv,temp;
    scanf("%d %d %d",&t,&n,&h);
    maxv=0;
    //ch='a';
    for(i=0;i<t;i++)
    {

        for(j=0;j<n;j++)
        {
            /*for(k=0;k<10;k++)
            {
                pass[k]=ch;
            }*/
            temp=j%5;
            printf("%s\n",pass[temp]);

        }
        ch++;
        fflush(stdout);
        scanf("%d",&temp);
        /*if(temp>maxv){maxv=temp;}
        if(i!=0)
        {
            if(s[i]<s[i-1])
            {

            }
        }*/
    }
    return 0;
}

