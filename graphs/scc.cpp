#include <bits/stdc++.h>
using namespace std;
#define ll long long
void dfsforscc(vector <vector <ll>> &G, vector <ll> &c,vector <ll> &pi, ll seed,vector <ll> &topsorted )
{
    c[seed]=1;
    for(auto i=G[seed].begin();i!=G[seed].end();i++)
    {
        if(pi[seed]!=(*i))
            pi[(*i)]=seed;
        if(!(c[(*i)]))
        {
            dfsforscc(G,c,pi,(*i),topsorted);
        }   
    }
    topsorted.push_back(seed);
}
vector <vector <ll>> scc(vector <vector <ll>> G, vector <ll> &topsorted)
{
    ll n=G.size();
    vector <vector <ll>> reverseG2;
    for(ll i=0;i<n;i++)
    {
        vector <ll> temp;
        reverseG2.push_back(temp);
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<G[i].size();j++)
        {
            reverseG2[G[i][j]].push_back(i);
        }
    }

    vector <ll> c(n, 0), pi(n, -1); 
    vector <vector <ll>> ans;
    for(ll i=0;i<n;i++)
    {
        vector <ll> temp;
        ans.push_back(temp);
    }
    for(int i=n-1;i>=0;i--)
    {
        if(c[topsorted[i]]==0)
        {
            dfsforscc(reverseG2,c,pi,topsorted[i],ans[topsorted[i]]);
        }
    } 
    return ans;
}