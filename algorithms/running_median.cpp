#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
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
#define all(x) x.begin(), x.end()
#define fastio  {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define fr(i, a, b) for (ll i = a; i <= b; i++)
#define frn(i, a, b) for (ll i = a; i >= b; i--)
#define mk make_pair
#define ceil(x) (ll)(ceil(x))
#define endl "\n"
#define setvector(i, vname,value,size); for(ll i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
void add(multiset <ll> &s1, multiset <ll> &s2, ll ele)
{
    ll m1=-inf;
    ll m2=inf;
    if(sz(s1))
    {
        auto it=s1.end();
        it--;
        m1=(*it);
    }
    if(sz(s2))
    {
        auto it=s2.begin();
        m2=(*it);
    }
    if(ele>=m2)
    {
        s2.insert(ele);
        if(sz(s2)-1>sz(s1))
        {
            s2.erase(s2.begin());
            s1.insert(m2);
        }
    }
    else if(ele<=m1)
    {
        s1.insert(ele);
        if(sz(s1)>sz(s2))
        {
            auto it=s1.end();
            it--;
            s1.erase(it);
            s2.insert(m1);
        }
    }
    else
    {
        s2.insert(ele);
        if(sz(s2)-1>sz(s1))
        {
            s2.erase(s2.begin());
            s1.insert(ele);
        }
    }
}
void del(multiset <ll> &s1, multiset <ll> &s2, ll ele)
{
    ll m1=-inf;
    ll m2=inf;
    if(sz(s1))
    {
        auto it=s1.end();
        it--;
        m1=(*it);
    }
    if(sz(s2))
    {
        auto it=s2.begin();
        m2=(*it);
    }
    if(ele>=m2)
    {
        auto it=s2.find(ele);
        s2.erase(it);
        if(sz(s2)<sz(s1))
        {
            auto it1=s1.end();
            it1--;
            ll val=(*it);
            s1.erase(it1);
            s2.insert(val);
        }
    }
    else if(ele<=m1)
    {
        auto it=s1.find(ele);
        s1.erase(it);
        if(sz(s1)<sz(s2)-1)
        {
            ll val=(*s2.begin());
            s2.erase(s2.begin());
            s1.insert(val);
        }
    }
}
int main()
{
    fastio
}