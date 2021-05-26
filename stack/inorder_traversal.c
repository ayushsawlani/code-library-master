#include <stdio.h>
#include <stdlib.h>
struct node{
        char data;
        struct node *right;
        struct node *left;
        struct node *prev;
	int flag;
};
void defaul(struct node *a)
{
	if(a!=NULL)
	{
		defaul(a->left);
		defaul(a->right);
		a->flag=0;
	}
}
void inorder(struct node *a)
{
	defaul(a);
	struct node *stack[1000];
	int st=0;
	stack[st++]=a;
	while(1)
	{
		if(st==0)
			break;
		if(stack[st-1]->flag==1)
		{
			printf("%c ",stack[st-1]->data);
			st--;
		}
		else
		{
			struct node*temp=stack[st-1];
			st--;
			if(temp->right!=NULL)
				stack[st++]=temp->right;
			stack[st++]=temp;
			stack[st-1]->flag=1;
			if(temp->left!=NULL)
				stack[st++]=temp->left;
		}
	}
}

int main()
{
        struct node *a=malloc(sizeof(struct node));
        struct node *b=malloc(sizeof(struct node));
        struct node *c=malloc(sizeof(struct node));
        struct node *d=malloc(sizeof(struct node));
        struct node *e=malloc(sizeof(struct node));
        struct node *f=malloc(sizeof(struct node));
        struct node *g=malloc(sizeof(struct node));
        struct node *h=malloc(sizeof(struct node));
        struct node *i=malloc(sizeof(struct node));
        a->data='a';
        b->data='b';
        c->data='c';
        e->data='e';
        f->data='f';
        g->data='g';
        h->data='h';
        i->data='i';
        d->data='d';
        a->prev=NULL;
        a->left=b;
        a->right=c;
        b->prev=a;
        b->left=NULL;
        b->right=d;
        d->prev=b;
        d->left=f;
        d->right=g;
        g->prev=d;
        g->left=NULL;
        g->right=NULL;
        f->prev=d;
        f->left=NULL;
        f->right=i;
        i->prev=f;
        i->left=NULL;
        i->right=NULL;
        c->prev=a;
        c->right=NULL;
        c->left=e;
        e->prev=c;
        e->left=NULL;
        e->right=h;
        h->prev=e;
        h->right=NULL;
        h->left=NULL;
        inorder(a);
        printf("\n");
 //       preorder(a);
   //     printf("\n");
     //   postorder(a);
       // printf("\n");
}

