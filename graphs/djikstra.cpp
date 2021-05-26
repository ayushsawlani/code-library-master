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
void djikstra(vector <vector <ll>> &G, ve <ll>&c,ve <ll> &pi,ve <ll> &priority,map <pair <ll,ll>,ll> &wt,ll seed)
{
    ll n=G.size();
    set <pair <ll,ll>> pq;
    c[seed]=1;
    pi[seed]=-1;
    priority[seed]=0;
    pq.insert(mk(0, seed));
    while(!(pq.empty()))
    {
        pair <ll,ll>visited=(*(pq.begin()));
        pq.erase(pq.begin());
        c[visited.second]=2;
        for(auto i: G[visited.second])
        {
            pair <ll,ll> current;
            current.first=visited.second;
            current.second=(i);
            ll newprio=wt[current]+visited.fi;
            if(c[(i)]==1)
            {
                if(newprio<priority[i])
                {
                    pair <ll,ll> tobeerased=mk(priority[i], i);
                    auto er=pq.find(tobeerased);
                    pq.erase(er);
                    c[i]=0;
                }
            }
            if(c[(i)]==0)
            {
                priority[(i)]=newprio;
                pair <ll,ll> tobepushed=mk(priority[i], i);
                pq.insert(tobepushed);
                pi[i]=visited.second;
                c[i]=1;
            }
        }
    }
}