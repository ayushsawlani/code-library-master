#include <stdio.h>
void enqueue(int *stack1,int *top1,int ele)
{
	*(stack1+*top1)=ele;
	*top1=(*top1)++;
}
void dequeue(int *stack1,int *stack2,int *top1, int *top2)
{
	if((*(top2))==0)
	{
		int temp=*top1;
		for(int i=0;i<temp;i++)
		{
			stack2[i]=stack2[temp-i-1];
			(*top2)++;
		}
		*top1=0;
	}
	*top2=(*top2)-1;
}
int main()
{
	
