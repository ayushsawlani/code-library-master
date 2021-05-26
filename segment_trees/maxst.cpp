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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision. 
class maxst
{
    private:
        ve <ll> input, segtree;
        ll size, ksize;
    public:
        maxst(ve <ll> in)
        {
            input=in;
            size=(ll)sz(in);
            ksize=1;
            for(;ksize<size;ksize=ksize*2);
            segtree.resize(2*ksize-1);
            for(ll i=0;i<2*ksize-1;i++)
                segtree[i]=-inf;
            for(ll i=ksize-2+size;i>=ksize-1;i--)
                segtree[i]=input[i-ksize+1];
            for(ll i=ksize-2;i>=0;i--)
                segtree[i]=max(segtree[2*i+1], segtree[2*i+2]);
        }
        ll getmaxutil(ll l, ll r, ll i, ll j, ll seed)
        {
            if((l>j)||(i>r))
            {
                return -inf;
            }
            else if((i>=l)&&(j<=r))
            {
                return segtree[seed];
            }
            else
            {
                ll mid=(i+j)/2;
                return max(getmaxutil(l, r, i, mid, 2*seed+1),getmaxutil(l, r, mid+1, j, 2*seed+2));
            }
        }
        ll getmax(ll l, ll r)
        {
            return getmaxutil(l, r, 0, ksize-1, 0);
        }
        void updatetree(ll ind, ll val)
        {
            ll treeind=ind+ksize-1;
            segtree[treeind]=val;
            input[ind]=val;
            while(treeind>0)
            {
                ll pa=(treeind-1)/2;
                segtree[pa]=max(segtree[2*pa+1], segtree[2*pa+2]);
                treeind=pa;
            }
        }

};
int main()
{
    //fastio
    ll n;
    cin>>n;
    ve <ll> in(n);
    inarr(i, in, n);
    maxst maxtree=(*new maxst(in));
    ll q;
    cin>>q;
    while(q--)
    {
        ll l, r;
        cin>>l>>r;
        cout<<maxtree.getmax(l, r);
    }
}