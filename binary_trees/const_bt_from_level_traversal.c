node *const_bt(int a[],int n)
{
	node *arr[n];
	node *root=(node *)(malloc (sizeof(node)));
	root->prev=NULL;
	root->data=1;
	int l=0;
	int r=0;
	arr[r++]=root;
	for(int p=0;l!=r;)
	{
		if((a[p]>0)&&(a[p+1]>0))
		{
			node *m=(node *)(malloc(sizeof(node)));
			m->data=a[p];
			m->prev=arr[l];
			node *n=(node *)(malloc(sizeof(node)));
			n->data=a[p+1];
			n->prev=arr[l];
			arr[l]->lc=m;
			arr[l]->rc=n;
			arr[r++]=m;
			arr[r++]=n;
			l++;
		}
		else if(a[p]>0)
		{
			node *m=(node *)(malloc(sizeof(node)));
			m->data=a[p];
			m->prev=arr[l];
			arr[l]->lc=m;
			arr[l]->rc=NULL;
			arr[r++]=m;
			l++;
		}
		else if(a[p+1]>0)
		{
			node *m=(node *)(malloc(sizeof(node)));
			m->data=a[p+1];
			m->prev=arr[l];
			arr[l]->rc=m;
			arr[l]->lc=NULL;
			arr[r++]=m;
			l++;
		}
		else
		{
			arr[l]->lc=NULL;
			arr[l]->rc=NULL;
			l++;
		}
		if(p<n-3)
			p=p+2;
	}
	return root;
}
