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
ll diameter(ve <ve <ll>> &G)
{
    ll n=sz(G);
    ve <ll> c(n, 0), dist(n, 0);
    dfs_for_diameter(G, c, dist, 0);
    ll seed=0;
    for(int i=0;i<n;i++)
    {
        if(dist[seed]<dist[i])
            seed=i;
    }
    for(int i=0;i<n;i++)
    {
        c[i]=0;
        dist[i]=0;
    }
    dfs_for_diameter(G, c, dist, seed);
    ll dia=0;
    for(int i=0;i<n;i++)
    {
        dia=max(dia, dist[i]);
    }
    return dia;
}
void dfs_for_diameter(ve <ve <ll>> &G, ve <ll> &c, ve <ll> &dist, ll seed)
{
    c[seed]=1;
    for(auto chi:G[seed])
    {
        if(c[chi]==0)
        {
            dist[chi]=dist[seed]+1;
            dfs_for_diameter(G, c, dist, chi);
        }
    }
}
int main()
{
    //fastio
}