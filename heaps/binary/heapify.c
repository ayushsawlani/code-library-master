#include "heapify.h"
void top_down_heapify(int a[],int n, int i)
{
    int j=i;
    while(1)
    {   
        int l=2*j+1;
        if(l>=n)
            break;
        if(l<n-1)
            if(a[l]>a[2*j+2])
                l=2*j+2;
        if(a[j]>a[l])
        {
            int temp=a[j];
            a[j]=a[l];
            a[l]=temp;
        }
        else
        {
            break;
        }
        
        j=l;
    }
}
void bottom_up_heapify(int a[], int i)
{
    while(1)
    {
        int p=(i-1)/2;
        if(i==0)
        {
            break;
        }
        if(a[p]>a[i])
        {
            int temp=a[i];
            a[i]=a[p];
            a[p]=temp;
        }
        else
        {
            break;
        }
        i=p;
    }
}
