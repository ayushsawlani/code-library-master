#include <stdio.h>
int bs(int *a,int i,int j)
{
	if(j==i+2)
	{
		if((a[i+1]>a[i])&&(a[i+1]>a[i+2]))
			return i+1;
		else
			return -1;
	}
        if(j==i+1)
        {
                return -1;
        }
        if(j>i)
        {
                if((a[(j+i)/2]>a[(j+i)/2-1])&&(a[(j+i)/2]>a[(j+i)/2+1]))
                        return (j+i)/2;
                else if((a[(j+i)/2]<=a[(j+i)/2-1])&&(a[(j+i)/2]>=a[(j+i)/2+1]))
                        return bs(a,i,(i+j)/2);
                else if((a[(j+i)/2]>=a[(j+i)/2-1])&&(a[(j+i)/2]<=a[(j+i)/2+1]))
                        return bs(a,(i+j)/2,j);
        }
        else
        {
                return -1;
        }
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	printf("%d\n",bs(a,0,n-1));
	}
