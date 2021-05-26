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
ll gcd(ll a,ll b)
{
	if(a==-1)
		return b;
	else if(b==-1)
		return a;
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
class gcdst
{
    private:
        ve <ll> input, segtree;
        ll size, ksize;
    public:
        gcdst(ve <ll> in)
        {
            input=in;
            size=(ll)sz(in);
            ksize=1;
            for(;ksize<size;ksize=ksize*2);
            segtree.resize(2*ksize-1);
            for(ll i=0;i<2*ksize-1;i++)
                segtree[i]=inf;
            for(ll i=ksize-2+size;i>=ksize-1;i--)
                segtree[i]=input[i-ksize+1];
            for(ll i=ksize-2;i>=0;i--)
            {
                ll val1=segtree[2*i+1];
                ll val2=segtree[2*i+2];
                ll ans=val1;
                if(val1==inf)
                    ans=val2;
                else if(val2==inf)
                    ans=val1;
                else
                    ans=gcd(ans, val2);
                segtree[i]=ans;
            }
        }
        ll getgcdutil(ll l, ll r, ll i, ll j, ll seed)
        {
            if((l>j)||(i>r))
            {
                return inf;
            }
            else if((i>=l)&&(j<=r))
            {
                return segtree[seed];
            }
            else
            {
                ll mid=(i+j)/2;
                ll val1=getgcdutil(l, r, i, mid, 2*seed+1);
                ll val2=getgcdutil(l, r, mid+1, j, 2*seed+2);
                ll ans=val1;
                if(val1==inf)
                    ans=val2;
                else if(val2==inf)
                    ans=val1;
                else
                    ans=gcd(ans, val2);
                return ans;
            }
        }
        ll getgcd(ll l, ll r)
        {
            return getgcdutil(l, r, 0, ksize-1, 0);
        }
        void updatetree(ll ind, ll val)
        {
            ll treeind=ind+ksize-1;
            segtree[treeind]=val;
            input[ind]=val;
            while(treeind>0)
            {
                ll pa=(treeind-1)/2;
                segtree[pa]=gcd(segtree[2*pa+1], segtree[2*pa+2]);
                treeind=pa;
            }
        }

};
int main()
{
    fastio
    ll n;
    cin>>n;
    ve <ll> in(n);
    inarr(i, in, n);
    gcdst gcdtree=(*new gcdst(in));
    ll q;
    cin>>q;
    while(q--)
    {
        ll l, r;
        cin>>l>>r;
        cout<<gcdtree.getgcd(l, r)<<endl;
    }
}