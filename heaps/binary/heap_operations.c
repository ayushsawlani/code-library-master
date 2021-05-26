#include <stdio.h>
#include <stdlib.h>
#include "heapify.h"
void add_node(int a[], int data,int *n)
{
a[*n]=data;
*n=(*n)+1;
bottom_up_heapify(a,*n-1);
}
void delete_min(int a[],int *n)
{
int temp=a[0];
a[0]=a[*n-1];
a[*n-1]=temp;
*n=(*n)-1;
top_down_heapify(a,*n, 0);    
}
void delete_node(int a[],int i,int *n)
{
int temp=a[i];
a[i]=a[*n-1];
a[*n-1]=temp;
if(a[i]>a[*n-1])
    top_down_heapify(a,*n-1,i);
else
{
    bottom_up_heapify(a,i);
}
*n=(*n)-1;
}
void update_key(int a[],int i, int key,int n)
{
if(a[i]>key)
{
    a[i]=key;
    bottom_up_heapify(a,i);
}
else if(a[i]<key)
{
    a[i]=key;
    top_down_heapify(a,n,i);
}
}
void build_heap(int a[],int n){
    int i;
    for(i=1;i<=n;i=2*i);
    i=i/2;
    for(int j=i-1;j>=0;j--)
    top_down_heapify(a,n,j);
}
int main()
{
int *n=(int *)(malloc(sizeof(int)));
scanf("%d",n);
//printf("%d\n",*n);
int a[*n];
for(int i=0;i<*n;i++)
    scanf("%d",&a[i]);
//int p;
//int q;
build_heap(a,*n);
//    scanf("%d",&p);
//    scanf("%d",&q);
/*add_node(a,p,n);
for(int i=0;i<*n;i++)
    printf("%d ",a[i]);
printf("\n");

delete_min(a,n);
for(int i=0;i<*n;i++)
    printf("%d ",a[i]);
printf("\n");
*/
//    delete_node(a,q,n);
for(int i=0;i<*n;i++)
    printf("%d ",a[i]);
printf("\n");
}