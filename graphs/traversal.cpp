#include <bits/stdc++.h>
using namespace std;
#define ll long long
void bfs(vector <vector<ll>> &g,vector <ll> &pi,vector <ll> &c,ll s )
{
    ll len_g=g.size();
    queue <ll> q;
    q.push(s);
    c[s]=1;     //it is better to declare c outside to improve efficiency if traversal is to be done a lot of times
    pi[s]=s;
    while(!(q.empty()))
    {
        ll temp=(q.front());
        q.pop();
        c[temp]=2;
        ll len_temp_adj=g[temp].size();
        for(auto i: g[temp])
        {
            if(c[i]==0)
            {
                q.push(i);
                c[i]=1;
                pi[i]=temp;
            }
        }
    }
}
void dfs(vector <vector <ll>> &G, vector <ll> &c, vector <ll> &pi, ll seed)
{
    c[seed]=1;
    for(auto i: G[seed])
    {
        if(pi[seed]!=i)
            pi[i]=seed;
        if(!(c[i]))
        {
            dfs(G,c,pi,(i));
        }   
    }
}
//add visit and finish time to the template
//set all elements' children to 1 initially