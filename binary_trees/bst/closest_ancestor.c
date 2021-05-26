struct node{
    int data;
    struct node*right;
    struct node*left;
};
struct node *lca( struct node *root, int v1, int v2 ) {
struct node *v1_a[30];
struct node *v2_a[30];
struct node *temp1=root;
int i=0;
while(temp1->data!=v1)
{
    v1_a[i++]=temp1;
    if(temp1->data<v1)
        temp1=temp1->right;
    else
        temp1=temp1->left;
}
v1_a[i++]=temp1;
i=0;
temp1=root;
while(temp1->data!=v2)
{
    v2_a[i++]=temp1;
    if(temp1->data<v2)
        temp1=temp1->right;
    else
        temp1=temp1->left;
}
v2_a[i++]=temp1;
int j;
for(j=0;j<i;j++)
{
    if(v1_a[j]!=v2_a[j])
        break;
}
return v1_a[j-1];
}
