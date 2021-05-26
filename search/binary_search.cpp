#include <stdio.h>
ll bs(pair <ll,ll> f,ll i,ll j, ll d)
{
    if(i==j)
        return i;
    else
    {
        ll m=(i+j)/2;
        if(m*f.second>f.first*d)
            return bs(f,i,m,d);
        else if(m*f.second<f.first*d)
            return bs(f,m+1,j,d);
    }
    
}
int main()
{
	int n,target;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);
	scanf("%d",&target);
	printf("%d\n",bs(arr,0,n-1,target));
}
