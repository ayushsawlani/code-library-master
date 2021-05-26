#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int p[n][2];
	int ht[n];
	for(int i=0;i<n;i++)
		ht[i]=0;
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(j>0)
		{
			if(p[j-1][1]>arr[i])
			{
				while(j>0)
				{
					if(p[j-1][1]<=arr[i])
						break;
					ht[p[j-1][0]]=i;
					j=j-1;
				}
			}
		}
		j=j+1;
		p[j-1][0]=i;
		p[j-1][1]=arr[i];
	}
	for(int i=0;i<n;i++)
		printf("%d %d\n",arr[i],ht[i]);
}
				

