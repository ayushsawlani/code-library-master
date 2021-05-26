#include <stdio.h>
#include "merge_sort.h"
int sum_check(int *a,int i,int j,int x)
{
	int l=i,r=j;
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
                return 1;
        else
                return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	ms(a,0,n-1);
	int flag=0;
	for(int i=0;i<n-1;i++)
	{
		if(sum_check(a,0,n-1,a[i]))
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		printf("1\n");
	else
		printf("0\n");
}

