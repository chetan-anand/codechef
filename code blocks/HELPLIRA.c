#include<stdio.h>
#include<math.h>

int main()
{
    int n,i,j,k;
    int a,b,c,d,e,f,min,max,area,mini,maxi;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
        area=abs(a*(d-f)-(b*(c-e))+(c*f)-(e*d));
        if(i==1)
        {
            min=area;mini=1;
            max=area;maxi=1;
        }
        if(area<min){min=area;mini=i;}
        if(area>max){max=area;maxi=i;}
    }
    printf("%d %d\n",mini,maxi);
    return 0;
}

