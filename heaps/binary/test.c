#include <stdio.h>
#include <stdlib.h>
#include "heapify.h"
int main()
{
    int n,j,p;
    scanf("%d",&n);
    int *a=(int *)(malloc(n*sizeof(int)));
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    scanf("%d",&p);
    scanf("%d",&j);
    top_down_heapify(a,n,p);
    //bottom_up_heapify(a,n,j);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
