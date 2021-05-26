#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <pair <ll,ll>> compress_array(vector <ll> a, ll n)
{
    vector <pair <ll,ll>> ans;
    ll i=0;
    ll c=1;
    while(i<n-1)
    {
        if(a[i]!=a[i+1])
        {
            pair <ll,ll> temp;
            temp.first=a[i];
            temp.second=c;
            ans.push_back(temp);
            c=1;
        }
        else
        {
            c++;
        }
        i++;   
    }
    if(i<n)
    {
        pair <ll,ll> temp;
        temp.first=a[i];
        temp.second=c;
        ans.push_back(temp);
        c=1;
    }
    return ans;
}