#include <stdio.h>
#include <stdlib.h>
struct node1 {
	int data;
	struct node1 *next;
};
#define node struct node1
void prilinlist(node *head)
{
	while(head!=NULL)
	{
		printf("%d\n",head->data);
		head=head->next;
	}
}
void deleteNode(node **head,int p)
{
	if(p==0)
	{
		node *temp=*head;
		(*head)=(*head)->next;
		free(temp);
	}
	else
	{
		node *temp=*head;
		for(int i=0;i<p-1;i++)
		{
			temp=temp->next;
		}
		node *temp2=temp->next;
		temp->next=temp->next->next;
		free(temp2);
	}
}
void insertNode(node **head,int data, int p)
{
	if(p==0)
	{
		node *temp=(node *)(malloc(sizeof(node)));
		temp->data=data;
		temp->next=*head;
		*head=temp;
	}
	else
	{
		node *temp;
		temp=*head;
		for(int i=0;i<p-1;i++)
		{
			temp=temp->next;
		}
		node *temp2=(node *)(malloc(sizeof(int)));
		temp2->data=data;
		temp2->next=temp->next;
		temp->next=temp2;
	}
}


int main()
{
	node *head=(node *)(malloc(sizeof(node)));
	node *second=(node *)(malloc(sizeof(node)));
	node *third=(node *)(malloc(sizeof(node)));
	node *first=(node *)(malloc(sizeof(node)));
	head->data=0;
	head->next=first;
	first->data=1;
	first->next=second;
	second->data=2;
	second->next=third;
	third->next=NULL;
	third->data=3;
	node *temp=head;
/*	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
*/
	prilinlist(head);
	deleteNode(&head,3);
	prilinlist(head);
	insertNode(&head,5,1);
	prilinlist(head);
}

