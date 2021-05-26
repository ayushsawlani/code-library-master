#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
    struct node *childlist[2];
};
int isgreater(char *a1, char *a2)
{
    for(int i=0;i<32;i++)
    {
        if(a1[i]>a2[i])
            return 1;
        if(a1[i]<a2[i])
            return 0;
    }
    return 0;   
}
void addnode(struct node*root,char *s1,int i)
{
    if(i<32)
    {    
        if(s1[i]=='1')
        {
            if((root->childlist)[1]==NULL)
            {
                struct node* child=(struct node *)(malloc(sizeof(struct node)));
                child->childlist[0]=NULL;
                child->childlist[1]=NULL;
                root->childlist[1]=child;
            }
            addnode(root->childlist[1],s1,i+1);
        }
        if(s1[i]=='0')
        {
            if((root->childlist)[0]==NULL)
            {
                struct node* child=(struct node *)(malloc(sizeof(struct node)));
                child->childlist[0]=NULL;
                child->childlist[1]=NULL;
                root->childlist[0]=child;
            }
            addnode(root->childlist[0],s1,i+1);
        }
    }
}
void delete_string(struct node*root,char*s,int i)
{
	if(i<32)
	{
	delete_string(root->childlist[(int)s[i]-48],s,i+1);
	int flag=0;
	for(int j=0;j<2;j++)
	{
		if(root->childlist[j]!=NULL)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		free(root);
	}
	}
}
int main()
{
    int n;
    scanf("%d",&n);
    struct node*root=(struct node *)(malloc(sizeof(struct node)));
    root->childlist[0]=NULL;
    root->childlist[1]=NULL;
    char*s1=(char *)(malloc(33*sizeof(char)));
    char*s2=(char *)(malloc(33*sizeof(char)));
    char*max=(char *)(malloc(33*sizeof(char)));
    for(int i=0;i<32;i++)
    {
        max[i]='0';
    }
    s1[32]='\0';
    max[32]='\0';
    s2[32]='\0';
    for(int i=0;i<n;i++)
    {
        scanf("%s",s2);
        int len_s2=strlen(s2);
        for(int j=32-len_s2;j<32;j++)
            s1[j]=s2[j-32+len_s2];
        for(int j=0;j<32-len_s2;j++)
            s1[j]='0';
        struct node*temp;
        temp=root;
        for(int j=0;j<32;j++)
        {
            s2[j]='0';
        }
        for(int j=0;j<32;j++)
        {
            if((s1[j]=='1'))
            {
                if(temp->childlist[0]!=NULL)
                {
                    s2[j]='1';
                    temp=temp->childlist[0];   
                }
                else if(temp->childlist[1]!=NULL)
                {
                    s2[j]='0';
                    temp=temp->childlist[1];
                }
            }
            if((s1[j]=='0'))
            {
                if(temp->childlist[1]!=NULL)
                {
                    s2[j]='1';
                    temp=temp->childlist[1];   
                }
                else if(temp->childlist[0]!=NULL)
                {
                    s2[j]='0';
                    temp=temp->childlist[0];
                }
            }
            
        }
        if(isgreater(s2,max))
        {
            for(int j=0;j<32;j++)
                max[j]=s2[j];
        }
        printf("%s\n",max);
        addnode(root,s1,0);
    }
    delete_string(root,s1,0);
    printf("%s\n",max);

}
