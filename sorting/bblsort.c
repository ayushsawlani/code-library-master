#include <stdio.h>
void bblsort(int *a,int n)
{
	while(1)
	{
		int flag=0;
		for(int i=0;i<n-1;i++)
		{
			if(a[i]>a[i+1])
			{
				int temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	bblsort(a,n);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
