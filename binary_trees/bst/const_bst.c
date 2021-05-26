#include <stdio.h>
#include <stdlib.h>
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
struct node{
	int data;
	struct node *right;
	struct node *left;
	struct node *prev;
};
struct node* const_bst(int *a,int i,int j)
{
    int m=(i+j)/2;
    struct node*l;
    struct node *r;
    struct node* root=(struct node*)(malloc(sizeof(struct node)));
    if(i<=j)
    {
        l=const_bst(a,i,m-1);
        r=const_bst(a,m+1,j);
        root->data=a[m];
        root->right=r;
        root->left=l;
        if(l!=NULL)
            l->prev=root;
        if(r!=NULL)
            r->prev=root;
    }
    else
    {
        root=NULL;
    }

    return root;
}
struct node* search_x(struct node *root,int x)
{
	if(root->data==x)
		return root;
	if(root->data<x)
	{
		if(root->right!=NULL)
			return search_x(root->right,x);
		else
			return NULL;
	}
	if(root->data>x)
	{
		if(root->left!=NULL)
			return search_x(root->left,x);
		else
			return NULL;
	}
}
void add_node(struct node *root,int x)
{
	if(root->data<x)
	{
		if(root->right!=NULL)
			add_node(root->right,x);
		else
		{
			struct node*child=(struct node*)(malloc(sizeof(struct node)));
			child->data=x;
			child->left=NULL;
			child->right=NULL;
			child->prev=root;
			root->right=child;
		}
	}
	if(root->data>x)
	{
		if(root->left!=NULL)
			add_node(root->left,x);
		else
		{
			struct node*child=(struct node*)(malloc(sizeof(struct node)));
			child->data=x;
			child->left=NULL;
			child->right=NULL;
			child->prev=root;
			root->left=child;
		}
	}
}
struct node* inorder_predecessor(struct node *root,int x)
{
	if(root->data>=x)
	{
		if(root->left!=NULL)
			return inorder_predecessor(root->left,x);
		else
		{
			if(root->prev->data<x)
				return root->prev;
			else
				return root;
		}

	}
	else
	{
		if(root->right!=NULL)
			return inorder_predecessor(root->right,x);
		else
			return root;
	}
}
void delete_node_x(struct node*temp1)
{
	if(temp1->left==NULL)
	{	 if(temp1->prev!=NULL)
		{ 	if(temp1->prev->left==temp1)
				 temp1->prev->left=temp1->right;
		 	else
				 temp1->prev->right=temp1->right;
		}
		 if(temp1->right!=NULL)
		 	temp1->right->prev=temp1->prev;
		 free(temp1);
	}
	else if(temp1->right==NULL)
	{
		if(temp1->prev!=NULL)
		{
		 if(temp1->prev->left==temp1)
			 temp1->prev->left=temp1->left;
		 else
			 temp1->prev->right=temp1->left;
		}
		 if(temp1->left!=NULL)
		 	temp1->left->prev=temp1->prev;
		 free(temp1);
	}
	else
	{
		struct node*temp2=inorder_predecessor(temp1,temp1->data);
		temp1->data=temp2->data;
		delete_node_x(temp2);
	}
}
void delete_node(struct node*root,int x)
{
	struct node*temp1=search_x(root,x);
	delete_node_x(temp1);
}
	
void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        inorder(root->left);
        inorder(root->right);
    }
}
int main()
{
    int n,x,y,z;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    ms(a,0,n-1);
    struct node *root=const_bst(a,0,n-1);
    root->prev=NULL;
    inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
    	scanf("%d",&z);
	printf("%d\n",inorder_predecessor(root,z)->data);
	delete_node(root,z);
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");

}
