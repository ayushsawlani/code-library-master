#include <stdio.h>
void selsort(int *a, int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min_i=i;
		for(int j=i+1;j<n;j++)
		{	
			if(a[min_i]>a[j])
				min_i=j;
		}
		int temp=a[min_i];
		a[min_i]=a[i];
		a[i]=temp;
	}
}

int main()
{
        int n;
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++)
                scanf("%d",a+i);
        selsort(a,n);
        for(int i=0;i<n;i++)
                printf("%d ",a[i]);
        printf("\n");
}
			
