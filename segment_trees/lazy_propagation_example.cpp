// we have to maintain running average for 3 tyoes of queries
// 1 a x: adding x to the first a elements;
// 2 k append k to the array
// 3 remove the last element from the array
// initially the array is just {0}
// https://codeforces.com/problemset/problem/283/A link of problem
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> buildst(vector <ll> a,ll n)
{
    ll k=stk(n);
    vector <ll> ans(2*k-1);
    for(ll i=0;i<2*k-1;i++)
        ans[i]=0;
    for(ll i=k-2+n;i>=k-1;i--)
        ans[i]=a[i-k+1];
    return ans;
}
ll stk(ll n)
{
    ll k=1;
    for(;k<n;k=k*2);
    return k;
}
void addx(vector <ll> st,ll x, ll l, ll r, ll i, ll j, ll p)
{
    if((j<=r)&&(i>=l))
    {
        st[p]+=x;
    }
    else if((l>j)||(i>r));
    else
    {
        ll m=(i+j)/2;
        addx(st,x,l,r,i,m,2*p+1);
        addx(st,x,l,r,m+1,j,2*p+2);
    }
}
ll getelement(vector <ll> st, ll i, ll n)
{
    ll sum=0;
    i=i+stk(n)-1;
    while(i>0)
    {
        sum+=st[i];
        i=((i-1)/2);
    }
    sum+=st[0];
    return sum;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll q;
    cin>>q;
    vector <ll> a(q,0);
    vector <ll> st=buildst(a,q);
    ll n=1;
    double sum=0;
 /*   for(ll i=0;i<2*stk(q)-1;i++)
        {
            cout<<st[i]<<endl;
        }
        cout<<endl;
   */
    for(ll t=0;t<q;t++)
    {
        ll query;
        cin>>query;
        ll r=stk(q);
        if(query==1)
        {
            ll a,x;
            cin>>a>>x;
            addx(st,x,0,a-1,0,r-1,0);
            sum+=a*x;
        }
        else if(query==2)
        {
            ll k;
            cin>>k;
            addx(st,k,n,n,0,r-1,0);
            n++;
            sum+=k;   
        }
        else
        {
            ll d=getelement(st,n-1,q);
            addx(st,(-1)*d,n-1,n-1,0,r-1,0);   
            sum-=d;
            n--;
        }
        /*for(ll i=0;i<2*r-1;i++)
        {
            cout<<st[i]<<endl;
        }
        cout<<endl;
        */
        //cout<<sum<<" "<<n<<endl;
        printf("%lf\n",sum/n);

    }
}