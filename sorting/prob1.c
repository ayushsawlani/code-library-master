//given x and an array find if there exists i and j such that ai+aj==ak
#include <stdio.h>
#include "merge_sort.h"
int main()
{
	int n,x;
	scanf("%d",&n);
	scanf("%d",&x);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	ms(a,0,n-1);
	int l=0,r=n-1;
	int flag=0;
	while(l<=r)
	{
		if(a[l]+a[r]==x)
		{
			flag=1;
			break;
		}
		else if(a[l]+a[r]>x)
			r--;
		else
			l++;
	}
	if(flag==1)
		printf("1\n");
	else
		printf("0\n");

}
