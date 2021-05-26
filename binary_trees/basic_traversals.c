#include <stdio.h>
#include <stdlib.h>
struct node{
	char data;
	struct node *right;
	struct node *left;
	struct node *prev;
};
void inorder(struct node *a)
{
	if(a!=NULL)
	{
		inorder(a->left);
		printf("%c ",a->data);
		inorder(a->right);
	}
}
void preorder(struct node *a)
{
	if(a!=NULL)
	{
		printf("%c ",a->data);
		preorder(a->left);
		preorder(a->right);
	}
}
void postorder(struct node *a)
{
	if(a!=NULL)
	{
		postorder(a->left);
		postorder(a->right);
		printf("%c ",a->data);
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
	preorder(a);
	printf("\n");
	postorder(a);
	printf("\n");
}
