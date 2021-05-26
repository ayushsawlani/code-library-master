#include <bits/stdc++.h>
#define ll long long
#define mod 13
ll fast_expo(ll a, ll n)
{
	int ans=1;
	while(n>0)
	{
		if(n%2==1)
			ans=(ans*a)%mod;
		a=(a*a)%mod;
		n=n/2;
	}
	return ans;
}
int main()
{
	printf("%lld\n",fast_expo(3,4));
}
