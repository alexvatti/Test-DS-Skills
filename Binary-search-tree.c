/*
binary search tree
*/

#include<stdio.h>
#include<string.h>
#include<stdarg.h>
#include<malloc.h>

struct node {
	int data;
	struct node *left,*right;
};
struct node *bst;

struct node * allocate_node(int val)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
#if 0
int insert(struct node **root, int val)
{
	if(*root==NULL)
		*root=allocate_node(val);
	else {
		if((*root)->data < val)
			insert((&(*root)->right),val);
		else if ((*root)->data > val)
			insert(&((*root)->left),val);
	}
}
#endif
struct node* insert( struct node* root, int data ) {

    if (root==NULL)
    {
        root = allocate_node(data);
    }
    else if (root->data > data)
    {
             root->left=insert(root->left, data);
    }
    else
    {
            root->right=insert(root->right, data);
    }
    return root;
	
}

int printPreorder(struct node *root)
{
	if(root==NULL) 
		return;
	printPreorder(root->left);
	printf("%d ",root->data);
	printPreorder(root->right);
}

int printPostorder(struct node *root)
{
	if(root==NULL) 
		return;
	printPostorder(root->left);
	printPostorder(root->right);
	printf("%d ",root->data);
}

int printInorder(struct node *root)
{
	if(root==NULL) 
		return;
	printf("%d ",root->data);
	printInorder(root->left);
	printInorder(root->right);
}

int minval(struct node *root)
{
	while(root->left!=NULL)
		root=root->left;
	return root->data;
}

int maxval(struct node *root)
{
	while(root->right!=NULL)
		root=root->right;
	return root->data;
}

int ISBST(struct node *root)
{
	if(root==NULL)
		return 1;
	else {
		if(root->left!=NULL && (maxval(root->left) > root->data))
		     return 0;
		else if (root->right!=NULL && (minval(root->right) < root->data))
			return 0;
		if(!ISBST(root->left) || !ISBST(root->right))
			return 0;
			
		return 1;
	}	
}

int main()
{
	int arr[]={5,6,4,2,1,8,9,10,3,7},i;
	struct node *root = NULL;
    
	for(i=0;i<=9;i++)
		root=insert(root,arr[i]);

	printf("\nPre-order----\n");
	printPreorder(root);
	printf("\n");
	
	printf("\nPost-order----\n");
	printPostorder(root);
	printf("\n");
	
	printf("\nIn-order----\n");
	printInorder(root);
	printf("\n");	

	printf("Given tree is BST=%d\n",ISBST(root));
}
