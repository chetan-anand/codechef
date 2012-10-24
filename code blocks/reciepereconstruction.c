#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,t,flag,len,len1;
    long long int cnt;
    char a[1000002],ch;
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        cnt=1;
        scanf("%s",a);
        len=strlen(a);
        for(i=0;i<=len/2;i++)
        {
            if(a[i]!='?'&&a[len-1-i]!='?')
            {
                if(a[i]!=a[len-1-i])
                {
                    flag=1;
                }
            }
        }
        if(len%2==0){len1=len/2;}
        else{len1=(len/2)+1;}
        if(flag==0)
        {
            for(i=0;i<len1;i++)
            {
                if(a[i]=='?'&&a[len-1-i]=='?'){cnt=cnt*26;}
                if(a[i]=='?'&&a[len-1-i]!='?'){cnt=cnt*1;}
                if(a[len-i-1]=='?'&&a[i]!='?'){cnt=cnt*1;}
            }
            printf("%d\n",cnt%10000009);
        }
        else{printf("0\n");}
    }

    return 0;
}
