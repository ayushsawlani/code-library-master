#include <bits/stdc++.h>
using namespace std;
#define mod 13
//you'll be given multiple queries of the from n,r where n and r are less than 10^6 and m is a prime number
#define ll long long
ll fac[1000000];
long long int fast_expo(ll a, ll n)
{
	ll ans=1;
	while(n>0)
	{
		if(n%2==1)
			ans=((ans*a)%mod);
		a=((a*a)%mod);
		n=n/2;
	}
	return ans;
}
ll n_c_r_mod_m(ll n, ll r)
{
    ll ans= ((fac[n]*fast_expo(fac[r],mod-2))%mod);
    ans=((ans*fast_expo(fac[n-r],mod-2))%mod);
    return ans;
}
int main()
{
    fac[1]=1;
    for(ll i=2;i<=1000000;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
    }
    cout<<fac[4]<<endl;
    cout<<n_c_r_mod_m(10,2)<<endl;
}