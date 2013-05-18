#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
    char a[10],b[6],c[8],d,ch,ctemp[100];
    int i,j,k,temp,e;
    int cnt=0,total;
    float cons=64;
    float f1,f2,f3,ftemp,fx[100],fy[100],fz[100];
    FILE *ptr;
    ptr=fopen("file1.txt","r");
    while(cnt<272)
    {
            ch=fgetc(ptr);
            if(ch=='\n'){cnt++;}
    }
    ///fscanf(ptr,"%s %d %s %s %c %d %f %f %f",a,&temp,a,b,&d,&e,&f1,&f2,&f3);
    ///printf("%s %d %s %s %c %d %.3f %.3f %0.3f",a,temp,a,b,d,e,f1,f2,f3);
    cnt=0;
    for(i=273;i<=708;i++)
    {
        fscanf(ptr,"%s %d %s %s %c %d %f %f %f %f %f %c",a,&temp,b,c,&d,&e,&f1,&f2,&f3,&ftemp,&ftemp,&ch);
        if(strcmp(b,"CA")==0)
        {
            cnt++;
            //printf("%s %d %s %s %c %d %.3f %.3f %.3f\n\n",a,temp,b,c,d,e,f1,f2,f3);
            fx[cnt]=f1;fy[cnt]=f2;fz[cnt]=f3;
            //printf("%f %f %f\n",fx[cnt],fy[cnt],fz[cnt]);
        }
        //printf("%s %d %s %s %c %d %.3f %.3f %.3f\n\n",a,temp,b,c,d,e,f1,f2,f3);
    }
    total=0;
    for(i=1;i<=cnt;i++)
    {

        for(j=i+3;j<=cnt;j++)
        {
            ftemp=(fx[i]-fx[j])*(fx[i]-fx[j])+(fy[i]-fy[j])*(fy[i]-fy[j])+(fz[i]-fz[j])*(fz[i]-fz[j]);
            printf("Distance between CA of %d and CA of %d = %f\n",i,j,ftemp);
            if(ftemp<cons){total++;}
        }
    }

    printf("\n\n\nTotal number of CA in protien = %d\n",cnt);
    printf("Total no of pair of atom with required maximum edge length 8A = %d\n",total);
    printf("Therefore, the contact density = %f\n",((float)total)/((float)cnt));
    return 0;
}
