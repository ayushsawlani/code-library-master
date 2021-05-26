#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ve vector
#define sz(a) (ll)(a.size())
ve <ll> z_array(string s)
{
    ve <ll> ans(sz(s));
    ans[0]=-1;
    ll l=0,r=0;
    for(ll i=1;i<s.size();i++)
    {
        if(i>r)
        {
            l=i;
            r=i;
            while((r<s.size())&&(s[r]==s[r-i]))
            {
                r++;
            }
            r--;
            ans[i]=r-l+1;
        }
        else
        {
            ll k=i-l;
            if(ans[k]+i<=r)
            {
                ans[i]=ans[k];
            }
            else
            {
                l=i;
                while((r<s.size())&&(s[r]==s[r-i]))
                {
                    r++;
                }
                r--;
                ans[i]=r-l+1;
            }
            
        }
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;
    ve <ll> z=z_array(s);
    for(ll i=0;i<s.size();i++)
    {
        cout<<z[i]<<" ";
    }
    cout<<endl;
}