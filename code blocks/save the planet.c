#include<stdio.h>
int main()
{
    int n,i,j,num1,num2,num3,len,a,rdr,b[32];
    char sg[200000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a=0;
        //printf("a\n");
        if(i==0){getchar();}
        scanf("%s",sg);
        //printf("b\n");
        //puts(sg);
        //len=strlen(sg);
        for(j=0;j<32;j++)
        {
            if(sg[j]=='0')
            {
                a=a+pow(2,31-j);
            }
        }
        num1=a;
        a=0;
        for(j=0;j<16;j++)
        {
            if(sg[j+32]=='0')
            {
                a=a+pow(2,15-j);
            }
        }
        num2=a;
        a=0;
        for(j=0;j<num2;j++)
        {
            if(sg[j+48]=='0')
            {
                a=a+pow(2,num2-1-j);
            }
        }
        num3=a;
        rdr=num3%num1;
        for(j=0;j<32;j++)
        {
            b[j]=rdr%2;
            rdr=rdr/2;
        }
        for(j=0;j<32;j++)
        {
            if(b[j]==1){b[j]=0;}
            else{b[j]=1;}
        }
        for(j=31;j>=0;j--)
        {
            printf("%d",b[j]);
        }
        printf("\n");


    }


    return 0;
}
