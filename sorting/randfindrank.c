#include <stdio.h>
#include <stdlib.h>
int partition(int *a,int i,int j)
{
	int l=i+1;
	int r=j;
	while((l<=j)&&(a[l]<=a[i]))
		l++;
	while((l<=j)&&(a[r]>a[i]))
		r--;
	if(l<=r)
	{
		int temp=a[l];
		a[l]=a[r];
		a[r]=temp;
		l++;
		r--;
	}
	int temp=a[l-1];
	a[l-1]=a[i];
	a[i]=temp;
	return l-1;
}

int rfindrank(int *a,int i,int j,int r)
{
	int n=partition(a,i,j);
	if(j-n+1==r)
		return a[n];
	else if (j-n+1>r)
		return rfindrank(a,n+1,j,r);
	else
		return rfindrank(a,i,n-1,r-j+n-1);
}
int main()
{
	int n,r;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	scanf("%d",&r);
	//printf("%d\n",partition(a,0,n-1));
	printf("%d\n",rfindrank(a,0,n-1,r));
}
