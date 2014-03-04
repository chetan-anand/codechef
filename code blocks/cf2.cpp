#include<stdio.h>
#include<string.h>
int main()
{
    int a[100100],p[100100],freq[100100],path[100100];
	int n,i,temp,cnt,hot,c=0,max;
	max=0;
	scanf("%d",&n);

	memset(freq,0,sizeof(freq));

	for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

	for(i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}

	for(i=1;i<=n;i++)
	{
		freq[p[i]]++;
	}

	for(i=1;i<=n;i++)
	{
		if(a[i])
		{
			temp=p[i];

			cnt=1;

			while(temp && freq[temp]==1 && !a[temp])
			{
				temp=p[temp];
				cnt++;
			}
			if(temp && freq[temp]==0)
            {
                cnt++;
            }

			if(cnt>max)
			{
				max=cnt;
				hot=i;
			}
		}
	}
	printf("%d\n",max);
	while(max--)
	{
		path[c++]=hot;
		//printf("%d ",hot);
		hot=p[hot];
	}
	for(i=c-1;i>=0;i--) printf("%d ",path[i]);
	printf("\n");
	return 0;
}
