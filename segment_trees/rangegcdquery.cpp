#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define pb push_back
#define mod 1000000007
#define inarr(i,arr,n); for(ll i=0;i<n;i++) cin >> arr[i];
#define outarr(i,arr,n); for(ll i=0;i<n;i++) cout<<arr[i]<<' ';
#define swap(a,b,t) {t=a;a=b;b=t;}
#define ve vector
#define sz(a) (int)((a).size())
#define fi first
#define se second
#define pa pair
#define fastio  {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define ll long long int
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
ll gcd(ll a,ll b)
{
	if(a==-1)
		return b;
	else if(b==-1)
		return a;
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
ll stk(ll n)
{
    ll k=1;
    for(;k<n;k=k*2);
    return k;
}
vector <ll> buildst(vector <ll> a,ll n)
{
    ll k=stk(n);
    vector <ll> ans(2*k-1);
    for(ll i=0;i<2*k-1;i++)
        ans[i]=-1;
    for(ll i=k-2+n;i>=k-1;i--)
        ans[i]=a[i-k+1];
    return ans;
}

ll getgcd(ve <ll> &gcdtree, ll i, ll j, ll l, ll r,ll k)
{
	if((j<l)||(r<i))
		return -1;
	else if((i>=l)&&(j<=r))
		return gcdtree[k];
	else
	{
		ll m=(i+j)/2;
		return gcd(getgcd(gcdtree, i, m, l, r, 2*k+1  ),getgcd(gcdtree, m+1, j, l, r, 2*k+2  ));
	}
}