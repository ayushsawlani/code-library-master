#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dsu_find(ll x,vector <ll> &c)
{
    return c[x];
}
//a and b are the nodes, c is the mapping of nodes to component number, s[i] gives the set of nodes in the ith component 
void dsu_union(ll a, ll b, vector <ll> &c, vector <set <ll>> &s)
{
    a=c[a];
    b=c[b];
    if(a==b)
        return;
    ll max=b;
    ll min=a;
    if(s[a].size()>s[b].size())
    {
        max=a;
        min=b;
    }
    ll size_max=s[max].size();
    ll size_min=s[min].size();
    while(size_min>0)
    {
        auto i=s[min].begin();
        ll x=(*i);
        c[x]=max;
        s[max].insert(x);
        s[min].erase(i);
        size_min--;
        size_max++;
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    vector <vector <ll>> G;
    for(ll i=0;i<n;i++)
    {
        vector <ll> temp;
        G.push_back(temp);
    }
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
}