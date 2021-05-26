#include <stdio.h>
#include <stdlib.h>
struct node{
	int key;
	int ht;
	int number;
	struct node*left;
	struct node*right;
};
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int height(struct node *x)
{
	if(x==NULL)
		return -1;
	else
		return x->ht;
}
int number(struct node*root)
{
	if(root==NULL)
		return 0;
	else
		return root->number;
}
void number_update(struct node*root)
{
	if(root!=NULL)
	{
		number_update(root->left);
		number_update(root->right);
		root->number=number(root->left)+number(root->right)+1;
	}
}
int rank(struct node*root,int Key)
{
	if(root!=NULL)
	{
	if(root->key==Key)
		return number(root->right)+1;
	else if(root->key>Key)
		return number(root)-number(root->left)+rank(root->left,Key);
	else
		return rank(root->right,Key);
	}
	else
		return 0;
}
struct node* leftrotate(struct node*x)
{
	//rotation
	struct node*y=x->right;
	struct node*t=y->left;
	y->left=x;
	x->right=t;
	//height updation
	x->ht=max(height(x->left),height(x->right))+1;
	y->ht=max(height(y->left),height(y->right))+1;
	return y;
}
struct node* rightrotate(struct node*x)
{
	//rotation
	struct node*y=x->left;
	struct node*t=y->right;
	y->right=x;
	x->left=t;
	//height updation
	x->ht=max(height(x->left),height(x->right))+1;
	y->ht=max(height(y->left),height(y->right))+1;
	return y;
}
int ht_difference(struct node*x)
{
	if(x!=NULL)
		return height(x->left)-height(x->right);
	return 0;
}
struct node* insert(struct node* root, int Key)
{
	//basic insert
	if(root==NULL)
	{
		struct node*new=(struct node*)(malloc(sizeof(struct node)));
		new->key=Key;
		new->left=NULL;
		new->right=NULL;
		new->ht=0;
		return new;
	}
	else if(Key<root->key)
	{
		root->left=insert(root->left,Key);
	}
	else
	{
		root->right=insert(root->right,Key);
	}

	//ht updation
	root->ht=max(height(root->left),height(root->right))+1;
		// balancing
	
	int difference=ht_difference(root);
	if((difference>1)&&(root->left->key>Key))//leftleft
		return rightrotate(root);
	else if((difference<-1)&&(root->right->key<Key))//rightright
		return leftrotate(root);
	else if((difference>1)&&(root->left->key<Key))//leftright
	{
		root->left=leftrotate(root->left);
		return rightrotate(root);
	}
	else if((difference<-1)&&(root->right->key>Key))
	{
		root->right=rightrotate(root->right);
		return leftrotate(root);
	}
	return root;
}
/* Given a non-empty binary search tree, return the
   node with minimum key value found in that tree.
   Note that the entire tree does not need to be
   searched. */
struct node * minValuenode(struct node* root)
{
    struct node* current = root;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Recursive function to delete a node with given key
// from subtree with given root. It returns root of
// the modified subtree.
struct node* deletenode(struct node* root, int key)
{
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if ( key < root->key )
        root->left = deletenode(root->left, key);

    // If the key to be deleted is greater than the
    // root's key, then it lies in right subtree
    else if( key > root->key )
        root->right = deletenode(root->right, key);

    // if key is same as root's key, then This is
    // the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct node *temp = root->left ? root->left :
                                             root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of
                            // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            struct node* temp = minValuenode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deletenode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->ht = 1 + max(height(root->left),
                           height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = ht_difference(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && ht_difference(root->left) >= 0)
        return rightrotate(root);

    // Left Right Case
    if (balance > 1 && ht_difference(root->left) < 0)
    {
        root->left =  leftrotate(root->left);
        return rightrotate(root);
    }

    // Right Right Case
    if (balance < -1 && ht_difference(root->right) <= 0)
        return leftrotate(root);

    // Right Left Case
    if (balance < -1 && ht_difference(root->right) > 0)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}
void preorder(struct node*root)
{
if(root!=NULL)
{
	printf("%d ",root->key);
	preorder(root->left);
	preorder(root->right);
}
}
void inorder(struct node*root)
{
if(root!=NULL)
{
	inorder(root->left);
	printf("%d ",root->key);
	inorder(root->right);
}
}

int main()
{
	struct node *root=NULL;
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,30);
	root=insert(root,40);
	root=insert(root,50);
	root=insert(root,60);
	root=insert(root,70);
	root=insert(root,80);
	root=insert(root,90);
	root=deletenode(root,80);
	preorder(root);
	number_update(root);
	printf("%d\n",rank(root,30));
	printf("\n");
	inorder(root);
	printf("\n");
}
