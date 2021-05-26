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
//usually we have a larger range to search. and we are supposed to compare f(i) with the value x

ll func(ll x) //func is monotonic
{
    //compute something
    return 0;
}


//smallest element >=x
ll bin1(ll x, ll start, ll end){
    ll i=start;//starting range
    ll j=end;//ending range
    while(i<j)//not i==j , i==j pe break because range me single element
    {
        ll mid=(i+j)/2;
        ll val=func(mid);
        if(val>=x)
            j=mid;
        else
        {
            i=mid+1;   
        }
    }
    if(func(j)<x)
        return -1;//element does not exist
    return j;
}


//largest element <=x
ll bin2(ll x, ll start, ll end){
    ll i=start;//starting range
    ll j=end;//ending range
    while(i<j)//not i==j , i==j pe break because range me single element
    {
        ll mid=(i+j+1)/2;
        if(func(mid)>x)
            j=mid-1;
        else
        {
            i=mid;   
        }
    }
    if(func(j)>x)
        return -1;//element does not exist
    return j;
}