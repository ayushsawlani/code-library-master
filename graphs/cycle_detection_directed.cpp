#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
bool cycle_detection(vector <vector <ll>> &G, ll seed, vector <ll> &c, vector <ll> &cutil)//c and cutil initially 0,seed is any vertex in graph
{
    c[seed]=1;
    cutil[seed]=1;
    for(auto it=G[seed].begin();it!=G[seed].end();it++)
    {
        if(c[*it])
        {
            if(cutil[*it])
                return true;
        }
        else
        {
            if(cycle_detection(G,(*it),c,cutil))
                return true;   
        }
    }
    cutil[seed]=0;
    return false;
}
int main()
{
 cin.tie(0);
ios::sync_with_stdio(0);
}