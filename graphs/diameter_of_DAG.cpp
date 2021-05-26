#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
ll diameter_util(vector <vector <ll>> &G, ll seed, ll *c, ll *leftover)//call this one first after setting c to 0, and leftover to 0
{
    c[seed]=1;
    ll ans=1;
    for(auto it=G[seed].begin();it!=G[seed].end();it++)
    {
        if(c[*it])
        {
            ans=max(ans,1+leftover[*it]);
        }
        else
        {
            ans=max(ans,1+diameter_util(G,(*it),c,leftover));
        }
    }
    leftover[seed]=ans;
    return ans;
}
//get the max of leftovers after calling dfs from every vertex
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
}