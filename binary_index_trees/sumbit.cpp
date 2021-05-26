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
class sumbitree
{
    private:
        ve <ll> tree;
        ll n;
    public:
        ll getsum(ll index)
        {
            ll sum = 0; // Iniialize result 
        
            // index in BITree[] is 1 more than the index in arr[] 
            index = index + 1; 
        
            // Traverse ancestors of BITree[index] 
            while (index>0) 
            { 
                // Add current element of BITree to sum 
                sum += tree[index]; 
        
                // Move index to parent node in getSum View 
                index -= index & (-index); 
            } 
            return sum; 
        }
        void updateBIT(int index, int val) 
        {
            // index in BITree[] is 1 more than the index in arr[] 
            index = index + 1; 
        
            // Traverse all ancestors and add 'val' 
            while (index <= n) 
            { 
                // Add 'val' to current node of BI Tree 
                tree[index] += val; 

                // Update index to that of parent in update View 
                index += index & (-index); 
            } 
        } 
        sumbitree(ve <ll> arr)
        { 
            n=sz(arr);
            tree.resize(n+1);
            // Create and initialize BITree[] as 0 
            for (int i=1; i<=n; i++) 
                tree[i] = 0; 
            // Store the actual values in BITree[] using update() 
            for (int i=0; i<n; i++) 
                updateBIT(i, arr[i]); 
        
            // Uncomment below lines to see contents of BITree[] 
            //for (int i=1; i<=n; i++) 
            //     cout << BITree[i] << " "; 
        
        } 
};
int main()
{
    //fastio
}