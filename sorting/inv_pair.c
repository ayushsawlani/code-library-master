//the total number of inversion pairs are also equal to the number of shifts insertion sort will take to sort the array
#include <stdio.h>
long int merge(int *a,int i,int j,int k)
{
	long int ans=0;
        int a_i=i,b_i=k+1,c_i=0;
        int c[j-i+1];
        while((a_i<=k)&&(b_i<=j))
        {
                if(a[a_i]>a[b_i])
		{
			ans=ans+k-a_i+1;
                        c[c_i++]=a[b_i++];
		}
                else
                        c[c_i++]=a[a_i++];
        }
        while(a_i<=k)
                c[c_i++]=a[a_i++];
        while(b_i<=j)
                c[c_i++]=a[b_i++];
        for(int p=0;p<c_i;p++)
                a[i+p]=c[p];
	return ans;
}
long int ms(int *a, int i, int j)
{
        if(j>i)
        {
                int m=(i+j)/2;
                return ms(a,i,m)+ms(a,m+1,j)+merge(a,i,j,m);
        }
	else
		return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int j=0;j<t;j++)
	{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);
	printf("%ld\n",ms(arr,0,n-1));
	}
}
