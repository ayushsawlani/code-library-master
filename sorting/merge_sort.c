#include <stdio.h>
#include "merge_sort.h"
void merge(int *a,int i,int j,int k)
{
	int a_i=i,b_i=k+1,c_i=0;
	int c[j-i+1];
	while((a_i<=k)&&(b_i<=j))
	{
		if(a[a_i]<a[b_i])
			c[c_i++]=a[a_i++];
		else
			c[c_i++]=a[b_i++];
	}
	while(a_i<=k)
		c[c_i++]=a[a_i++];
	while(b_i<=j)
		c[c_i++]=a[b_i++];
	for(int p=0;p<c_i;p++)
		a[i+p]=c[p];
}
void ms(int *a, int i, int j)
{
	if(j>i)
	{
		int m=(i+j)/2;
		ms(a,i,m);//leftarray
		ms(a,m+1,j);//rightarray
		merge(a,i,j,m);//merging a list with two halves
	}
}
		

