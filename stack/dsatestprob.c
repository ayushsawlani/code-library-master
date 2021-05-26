//find the sum of maximums of all the subarrays of an array A.
//for this we will just find how many times a particular number will be a maximum of a subarray.For this we will find the previous least and previous greatest element of the array and apply simple PnC to get the number of times it will occur.
#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d", a+i);
	//next greatest element
	int stack[n][2];
	int stack_count=0;
	stack[0][0]=0;
	stack[0][1]=a[0];
	stack_count++;
	int b[n];
	for(int i=0;i<n;i++)
		b[i]=n;
	for(int i=1;i<n;i++)
	{
		if(a[i]>stack[stack_count-1][1])
		{
			while(stack_count>0)
			{
				if(a[i]<=stack[stack_count-1][1])
					break;
				b[stack[stack_count-1][0]]=i;
				stack_count--;
			}
		}
		stack[stack_count][0]=i;		
		stack[stack_count][1]=a[i];
		stack_count++;
	}
	for(int i=0;i<n;i++)
		printf("%d ",b[i]);
	printf("\n");
	stack[0][0]=n-1;
	stack[0][1]=a[n-1];
	stack_count++;
	int c[n];
	for(int i=0;i<n;i++)
		c[i]=-1;
	for(int i=n-2;i>=0;i--)
	{
		if(a[i]>=stack[stack_count-1][1])
		{
			while(stack_count>0)
			{
				if(a[i]<stack[stack_count-1][1])
					break;
				c[stack[stack_count-1][0]]=i;
				stack_count--;
			}
		}
		stack[stack_count][0]=i;		
		stack[stack_count][1]=a[i];
		stack_count++;
	}
	for(int i=0;i<n;i++)
		printf("%d ",c[i]);
	printf("\n");
	int sum=0;
	for(int i=0;i<n;i++)
		sum=sum+a[i]*(b[i]-i)*(i-c[i]);
	printf("%d\n",sum);
}
