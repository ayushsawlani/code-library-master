#include <stdio.h>
#define ll long long
void range_update(ll *a,ll *st,ll a_count,ll i,ll ans)
{
    a[i]=ans;
    int j=i+a_count-1;
    while(j>0)
    {
        j=(j-1)/2;
        int l=2*j+1;
        if(a[st[l]]>a[st[l+1]])
            l=l+1;
        st[j]=st[l];
    }
}
int rmq(int *a,int *st,int i,int j,int l,int r,int k)
{
    if((l>=i)&&(r<=j))
        return st[k];
    else if((r<i)||(l>j))
        return -1;
    else
    {
        int mid=(l+r)/2;
        int p1=rmq(a,st,i,j,l,mid,2*k+1);
        int p2=rmq(a,st,i,j,mid+1,r,2*k+2);
        if(p1==-1)
            return p2;
        else if(p2==-1)
            return p1;
        else
        {
            int min=p1;
            if(a[p1]>a[p2])
                min=p2;
            return min;
        }
        
    }
    
}
int main()
{
    int n;
    scanf("%d",&n);
    int k;
    for(k=1;k<n;k=2*k);
    int a[k];
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=n;i<k;i++)
        a[i]=100000;
    n=k;
    printf("%d %d\n",n,k);
    int st[2*n-1];
    for(int i=n-1;i<2*n-1;i++)
        st[i]=i-n+1;
    for(int i=n-2;i>=0;i--)
    {
        if(a[st[2*i+1]]<a[st[2*i+2]])
            st[i]=st[2*i+1];
        else
        {
            st[i]=st[2*i+2];
        }
    }
    int i,j,p,ans;
    scanf("%d",&i);
    scanf("%d",&j);
    printf("%d",rmq(a,st,i,j,0,n-1,0));
    scanf("%d",&p);
    scanf("%d",&ans);
    update_key(a,st,n,p,ans);
    printf("%d",rmq(a,st,i,j,0,n-1,0));
    /*for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    for(int i=0;i<2*n-1;i++)
        printf("%d ",st[i]);
    printf("\n");
    */
}