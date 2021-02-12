//Binary search tree
#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
	int key; 
	struct node *left, *right; 
}*root = NULL;

struct node *newNode(int item) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{
		inorder(root->left); 
		printf("%d \t", root->key); 
		inorder(root->right); 
	}
} 

struct node* insert(struct node* node, int key) 
{ 
	if (node == NULL) 
		return newNode(key); 
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	return node; 
} 

int search_element(struct node *root,int item, int flag)
{
   while(root!=NULL)
   {
        if(root->key==item)
            return flag=1;
        if(item<root->key)
            root=root->left;
        else
            root=root->right;
   }
   return flag;
}

int main() 
{
	int item,n,i,flag=0,ch;
	printf("BINARY SEARCH TREE\n\n");
	
	printf("Enter no. of elements: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter element %d: ",i);
		scanf("%d",&item);
		root = insert(root,item);
	}
	
	while(1)
	{
		flag=0;
        printf("\n-----Menu-----");
		printf("\n1) Search an element");
        printf("\n2) Inorder Traversal of BST");
        printf("\n3) Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter the element you want to search: ");
                	scanf("%d",&item);
                    flag=search_element(root,item,flag);
                    if(flag==0)
                        printf("\nElement is not present in the tree.\n");
                    else
                        printf("\nElement is present in the tree.\n");
                    break;
            case 2: printf("\nInorder traversal of the BST:\n");
                    inorder(root);
                    printf("\n");
                    break;
            case 3: exit(1);
					break;
            default:printf("\nYou have entered the wrong choice.\n");
		}
	}
} 
