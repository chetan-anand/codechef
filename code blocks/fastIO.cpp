/*

This file contain a struct of fastIO function
*/
#include<bits/stdc++.h>/// tyhis include every possible c++ library in one go

using namespace std;
#define gi(n) n = io.sc()
#define SS 1024*1024*8
char IN[SS],OUT[SS],*iptr,*optr,stk[20];

struct fastIO
{
	fastIO()
	{
		fread(IN,1,SS,stdin);
		iptr=IN;
		optr=OUT;
	}
	void check()
	{
		int size=IN+SS-iptr;
		if(size<200)
		{
			memcpy(IN,iptr,size);
			fread(IN+size,1,SS-size,stdin);
			iptr=IN;
		}
	}
	void check2()
	{
		int size=OUT+SS-optr;
		if(size<200)
		{
			fwrite(OUT,optr-OUT,1,stdout);
			optr=OUT;
		}
	}

	int sc()
	{
		check();
		while(*iptr<=32) iptr++;
		int x=0;
		while(*iptr>32) x= x*10 + *iptr++ -'0';
		return x;
	}

	void pr(int x)
	{
		check2();
		if(x==0)
			*optr++='0';
		else
		{
			int y;
			int top=-1;
			while(x>0)
			{
				y=x/10;
				stk[++top]=x-y*10+'0';
				x=y;
			}
			while(top>=0) *optr++=stk[top--];
		}
		*optr++='\n';
	}
};

fastIO io;

int main()
{
    int t;
    //gi(t);
    t=io.sc();
    printf("%d",t);
    return 0;
}
