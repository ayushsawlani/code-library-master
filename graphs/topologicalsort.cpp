#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ceil (ll)ceil
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
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
void dfsforTS(vector <vector <ll>> &G, vector <ll> &c, ll seed,vector <ll> &topsorted )
{
    c[seed]=1;
    for(auto i=G[seed].begin();i!=G[seed].end();i++)
    {
        if(!(c[(*i)]))
        {
            dfsforTS(G,c,(*i),topsorted);
        }   
    }
    topsorted.push_back(seed);
}
vector <ll> gettopsort(vector <vector <ll>> &G)
{
    ll n=(ll)G.size();
    vector <ll> c(n, 0), ans;
    for(int i=0;i<n;i++)
    {
        if(c[i]==0)
        {
            dfsforTS(G, c, i, ans);
        }
    }
    for(int i=0;i<n/2;i++)
    {
        ll t=ans[i];
        ans[i]=ans[n-i-1];
        ans[n-i-1]=t;
    }
    return ans;
}