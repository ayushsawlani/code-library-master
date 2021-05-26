#include <stdio.h>
#include <stdlib.h>
struct node{
        char data;
        struct node *right;
        struct node *left;
        struct node *prev;
        int level;
        int height;
};
//queue
void level_traversal(struct node *a)
{
        struct node *arr[1000];
        int l=0;
        int r=1;
        arr[0]=a;
        while(1)
        {
                if(l==r)
                        break;
                if(arr[l]!=NULL)
                {
                        if(arr[l]->left!=NULL)
                                arr[r++]=arr[l]->left;
                        if(arr[l]->right!=NULL)
                                arr[r++]=arr[l]->right;
                }
                printf("%c %d %d\n",arr[l]->data,arr[l]->level,arr[l]->height);
                l++;
        }
}
void node_height(struct node *a)
{

        if(a!=NULL)
        {
                int max;
                node_height(a->left);
                node_height(a->right);
                if((a->left!=NULL)&&(a->right!=NULL))
                {
                        max=a->left->height;
                        if(max<a->right->height)
                                max=a->right->height;
                }
                else if(a->left!=NULL)
                        max=a->left->height;
                else if(a->right!=NULL)
                        max=a->right->height;
                else
                        max=-1;
                a->height=max+1;
        }
}
//queue
void level_node(struct node *a)
{
        a->level=0;
        struct node *arr[1000];
        int l=0;
        int r=1;
        arr[0]=a;
        while(1)
        {
                if(l==r)
                        break;
                if(arr[l]!=NULL)
                {
                        if(arr[l]->left!=NULL)
                        {
                                arr[r++]=arr[l]->left;
                                arr[r-1]->level=arr[l]->level+1;
                        }
                        if(arr[l]->right!=NULL)
                        {
                                arr[r++]=arr[l]->right;
                                arr[r-1]->level=arr[l]->level+1;
                        }
                }
                l++;
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
        level_node(a);
        node_height(a);
        level_traversal(a);
}
~                           
