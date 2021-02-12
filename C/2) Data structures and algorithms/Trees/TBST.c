//Insertion,Deletion,Traversal and Search in fully in-threaded BST
#include <stdio.h>
#include <stdlib.h>

typedef enum {False,True} boolean;
struct node
{
	struct node *left;
	boolean lthread;
	int info;
	boolean rthread;
	struct node *right;
};

struct node *insert(struct node *root, int ikey)
{       
	struct node *tmp,*par,*ptr;
	int found=0;
	ptr = root;
	par = NULL;
	while( ptr!=NULL )
	{
		if(ikey == ptr->info)
		{
			found =1;
			break;
		}
		par = ptr;
		if(ikey < ptr->info)
		{
			if(ptr->lthread == False)
				ptr = ptr->left;	
			else 
				break;
		}
		else 
		{
			if(ptr->rthread == False)
				ptr = ptr->right;
			else 
				break;
		}
	}
	if(found)
		printf("\nDuplicate key\n");
	else
	{
		tmp=(struct node *)malloc(sizeof(struct node));
		tmp->info=ikey;
		tmp->lthread = True;
		tmp->rthread = True;
		if(par==NULL)
		{
			root=tmp;
			tmp->left=NULL;
			tmp->right=NULL;
		}
		else if( ikey < par->info )
		{
			tmp->left=par->left;
			tmp->right=par;
			par->lthread=False;
			par->left=tmp;
		}
		else
		{
			tmp->left=par;
			tmp->right=par->right;
			par->rthread=False;
			par->right=tmp;
		}	
	}
	return root;
}

struct node *in_succ(struct node *ptr)
{
	if(ptr->rthread==True)
		return ptr->right; 
	else
	{
		ptr=ptr->right;
		while(ptr->lthread==False)
			ptr=ptr->left;
		return ptr;
	}
}

struct node *in_pred(struct node *ptr)
{
	if(ptr->lthread==True)
		return ptr->left;
	else
	{
		ptr=ptr->left;
		while(ptr->rthread==False)
			ptr=ptr->right;
		return ptr;
	}
}

struct node *case_a(struct node *root, struct node *par,struct node *ptr )
{
	if(par==NULL)
		root=NULL;
	else if(ptr==par->left)
	{
		par->lthread=True;
		par->left=ptr->left;
	}
	else
	{
		par->rthread=True;
		par->right=ptr->right;
	}
	free(ptr);
	return root;
}

struct node *case_b(struct node *root,struct node *par,struct node *ptr)
{
	struct node *child,*s,*p;
	if(ptr->lthread==False) 
		child=ptr->left;
	else               
		child=ptr->right;

	if(par==NULL )   
		root=child;
	else if( ptr==par->left)
		par->left=child;
	else                 
		par->right=child;
	
	s=in_succ(ptr);
	p=in_pred(ptr);
	if(ptr->lthread==False) 
		p->right=s;
	else if(ptr->rthread==False) 
		s->left=p;
	free(ptr);
	return root;
}

struct node *case_c(struct node *root, struct node *par,struct node *ptr)
{
	struct node *succ,*parsucc;
	parsucc = ptr;
	succ = ptr->right;
	while(succ->left!=NULL)
	{
		parsucc = succ;
		succ = succ->left;
	}
	ptr->info = succ->info;
	if(succ->lthread==True && succ->rthread==True)
		root = case_a(root, parsucc,succ);
	else	
		root = case_b(root, parsucc,succ);
	return root;
}

struct node *del(struct node *root, int dkey)
{
	struct node *par,*ptr;
	int found=0;
	ptr = root;
	par = NULL;
	while( ptr!=NULL)
	{
		if( dkey == ptr->info)
		{
			found=1;
			break;
		}
		par = ptr;
		if(dkey < ptr->info)
		{
			if(ptr->lthread == False)
				ptr = ptr->left;	
			else 
				break;
		}
		else 
		{
			if(ptr->rthread == False)
				ptr = ptr->right;
			else 
				break;
		}
	}

	if(found==0)
		printf("\nElement not present in tree\n");
	else if(ptr->lthread==False && ptr->rthread==False)
		root = case_c(root,par,ptr);	
	else if(ptr->lthread==False || ptr->rthread==False)
        root = case_b(root, par,ptr);
	else 
		root = case_a(root,par,ptr);
	return root;
}

void inorder( struct node *root)
{
	struct node *ptr;
	if(root == NULL )
	{
		printf("\nTree is empty\n");
		return;
	}
	ptr=root;
	while(ptr->lthread==False)
		ptr=ptr->left;
	
	while( ptr!=NULL )
	{
		printf("%d ",ptr->info);	
		ptr=in_succ(ptr);
	} 
	printf("\n");
}

void preorder(struct node *root )
{
	struct node *ptr;
	if(root==NULL)
	{
		printf("\nTree is empty\n");
		return;
	}
	ptr=root;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		if(ptr->lthread==False)
			ptr=ptr->left;
		else if(ptr->rthread==False)
			ptr=ptr->right;
		else
		{
			while(ptr!=NULL && ptr->rthread==True)
				ptr=ptr->right;
			if(ptr!=NULL)
				ptr=ptr->right;
		}
	}
	printf("\n");
}

void search( struct node *root,int item)
{
	struct node *ptr;
	if(root == NULL )
	{
		printf("\nTree is empty\n");
		return;
	}
	ptr=root;
	while(ptr->lthread==False)
		ptr=ptr->left;
	
	while( ptr!=NULL )
	{
		if(item==ptr->info)
		{
			printf("\nElement is present\n");
			return;	
		}	
		ptr=in_succ(ptr);
	} 
	printf("\nElement is absent\n");
}

int main( )
{
	int choice,num,item;
	struct node *root=NULL;
	printf("Fully In-Threaded BST");
	
	while(1)
	{
		printf("\n1.Insert\n");
		printf("2.Delete\n");
		printf("3.Search\n");
		printf("4.Inorder Traversal\n");
		printf("5.Preorder Traversal\n");
		printf("6.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter the number to be inserted : ");
				scanf("%d",&num);
				root = insert(root,num);
				break;
			case 2:
				printf("Enter the number to be deleted : ");
				scanf("%d",&num);
				root = del(root,num);
				break;
			case 3:
				printf("Enter the number to be searched : ");
				scanf("%d",&item);
				search(root,item);
				break;
			case 4:
				printf("\nInorder : ");
				inorder(root);
				break;
			case 5:
				printf("\nPreorder : ");
				preorder(root);
				break;
			case 6:
				exit(1);
			default:
				printf("Invalid choice\n");
		}
	}
}
