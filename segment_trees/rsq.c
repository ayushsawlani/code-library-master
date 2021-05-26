#include <stdio.h>
void update_key(int *a,int *st,int a_count,int i,int ans)
{
    a[i]=ans;
    int j=i+a_count-1;
    int temp=st[j];
    st[j]=ans;
    while(j>0)
    {
        int k=(j-1)/2;
        st[k]=st[k]+ans-temp;
        j=k;
    }
}
int rsq(int *a,int *st,int i,int j,int l,int r,int k)
{
    if((l>=i)&&(r<=j))
        return st[k];
    else if((r<i)||(l>j))
        return 0;
    else
    {
        int mid=(l+r)/2;
        int p1=rsq(a,st,i,j,l,mid,2*k+1);
        int p2=rsq(a,st,i,j,mid+1,r,2*k+2);
        return p1+p2;
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
        a[i]=0;
    n=k;
 //   printf("%d %d\n",n,k);
    int st[2*n-1];
    for(int i=n-1;i<2*n-1;i++)
        st[i]=a[i-n+1];
    for(int i=n-2;i>=0;i--)
    {
        st[i]=st[2*i+1]+st[2*i+2];
    }
    for(int i=0;i<2*n-1;i++)
        printf("%d ",st[i]);
    printf("\n");

    int i,j,p,ans;
    scanf("%d",&i);
    scanf("%d",&j);
    printf("%d",rsq(a,st,i,j,0,n-1,0));
    scanf("%d",&p);
    scanf("%d",&ans);
    update_key(a,st,n,p,ans);
    printf("%d",rsq(a,st,i,j,0,n-1,0));
    /*for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    for(int i=0;i<2*n-1;i++)
        printf("%d ",st[i]);
    printf("\n");
    */
    
}