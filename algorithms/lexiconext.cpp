#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
string next(string s)
{
    ll m1=0;
    for(ll i=s.size()-1;i>=0;i--)
    {
        for(ll j=i-1;j>=0;j--)
        {
            if(s[i]>s[j])
            {
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                sort(s.begin()+j+1,s.end());
                break;
            }
        }
    }
    return s;
}
int main()
{
 cin.tie(0);
ios::sync_with_stdio(0);
}
