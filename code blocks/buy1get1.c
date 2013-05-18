#include<stdio.h>
int main()
{
    int t,i,j,temp,cnt;
    char s[205],ch;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        //puts(s);
        cnt=0;
        for(i=0;s[i]!='\0';i++)
        {
            if(s[i]=='-'){continue;}
            temp=1;
            ch=s[i];
            s[i]='-';
            for(j=i+1;s[j]!='\0';j++)
            {
                if(ch==s[j]){s[j]='-';temp++;}
            }
            if(temp%2==0){temp=temp/2;}
            else{temp=(temp/2)+1;}
            cnt=cnt+temp;
            //puts(s);
        }
        printf("%d\n",cnt);
    }
    return 0;
}
