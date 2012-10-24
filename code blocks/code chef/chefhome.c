#include<stdio.h>
int main()
{
    int t,i,j,pc,qc,p;
    float x,y,xc,yc,xcm,ycm,n;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        xc=0;  yc=0;  p=0;
        scanf("%f",&n);
        for(j=0;j<n;j++)
        {
            scanf("%f %f",&x,&y);
            xc=xc+x;  yc=yc+y;
            //printf("%f %f\n",xc,yc);
        }
        xc=xc/n;  yc=yc/n;
        //printf("%f %f\n",xc,yc);
        pc=xc;    qc=yc;
        //printf("%d %d\n",pc,qc);
        xcm=pc+0.5;  ycm=pc+0.5;
        //printf("%f %f\n",xcm,ycm);
        if(xc!=xcm&&yc!=ycm){p++;}
        if(xc==xcm){if(yc==ycm){p=p+4;}else{p=p+2;}}
        if(yc==ycm){if(xc!=xcm)p=p+2;}
        printf("%d\n",p);
    }
    return 0;
}
