#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *right;
	struct node *left;
	struct node *prev;
};
struct node *const_pre_in(int *pre,int *in,int pre_i,int pre_j,int in_i,int in_j)
{
    int x=0;
    for(;x<=in_j-in_i;x++)
        if(pre[pre_i]==in[x+in_i])
            break;
    if(pre_i<=pre_j)
    {
        struct node*root=(struct node*)(malloc(sizeof(struct node)));
        root->data=pre[pre_i];
        root->left=const_pre_in(pre,in,pre_i+1,pre_i+x,in_i,in_i+x-1);
        root->right=const_pre_in(pre,in,pre_i+x+1,pre_j,in_i+x+1,in_j);
        if(root->left!=NULL)
            (root->left)->prev=root;
        if(root->right!=NULL)
            (root->right)->prev=root;
        return root;
    }
    else
    {
        return NULL;
    }
}
struct node *const_post_in(int *post,int *in,int post_i,int post_j,int in_i,int in_j)
{
    int x=0;
    for(;x<=in_j-in_i;x++)
        if(post[post_j]==in[in_j-x])
            break;
    if(post_i<=post_j)
    {
        struct node*root=(struct node*)(malloc(sizeof(struct node)));
        root->data=post[post_j];
        root->left=const_post_in(post,in,post_i,post_j-x-1,in_i,in_j-x-1);
        root->right=const_post_in(post,in,post_j-x,post_j-1,in_j-x+1,in_j);
        if(root->left!=NULL)
            (root->left)->prev=root;
        if(root->right!=NULL)
            (root->right)->prev=root;
        return root;

    }
    else
    {
        return NULL;
    }
    
}
void preorder(struct node *a)
{
	if(a!=NULL)
	{
		printf("%d ",a->data);
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
		printf("%d ",a->data);
	}
}
int main()
{
    int n;
    scanf("%d",&n);
    int *a=(int *)(malloc(n*sizeof(int)));
    int *b=(int *)(malloc(n*sizeof(int)));
    int *c=(int *)(malloc(n*sizeof(int)));
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<n;i++)
        scanf("%d",b+i);
    struct node*root1=const_pre_in(a,b,0,n-1,0,n-1);
    postorder(root1);
    printf("\n");
    for(int i=0;i<n;i++)
        scanf("%d",c+i);
    root1=const_post_in(c,b,0,n-1,0,n-1);
    //printf("%d\n",root1->data);
    preorder(root1);
}
