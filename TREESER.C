/*
	Program Purpose : To Create a BinaryTree and Perform 
					  Operation on it.
	Coded by : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV					  
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node_tag
{
    int data;
    struct node_tag *left,*right;
}node;

node *getnode()
{
    return (node *)malloc(sizeof(node));
}

node* search(node *root,int no)
{
    node *p = root;
    if(p==NULL)
		return p;
    
	if(p->data==no)
		return p;
    
	if(p->data>no)
		return  search(p->left,no);
    
	return  search(p->right,no);
}

void inorder(node *tra)
{
    if(tra!=NULL)
    {
		inorder(tra->left);
		printf("%d ",tra->data);
		inorder(tra->right);
    }
}
void preorder(node *root)
{
    node *tra=root;
    if(tra!=NULL)
    {
		printf("%d ",tra->data);
		preorder(tra->left);
		preorder(tra->right);
    }
}
void postorder(node *root)
{
    node *tra=root;
    if(tra!=NULL)
    {
		postorder(tra->left);
		postorder(tra->right);
		printf("%d ",tra->data);
    }
}

int insert(node **rootptr, int no)
{
    node *p = *rootptr,*nptr;
    
	if(p==NULL)	//check for empty tree
    {
		nptr = getnode();		//fill a node
		nptr->data = no;
		nptr->left = nptr->right = NULL;
		*rootptr = nptr;
		return 1;
    }

    if(p->data==no)
		return 0;
    
	if(p->data>no)
		return insert(&p->left,no);
    else
		return insert(&p->right,no);
}

void create_tree(node **root)
{
    char ch;
    int no;
    
	printf("Want to build a tree(y/n) ");
    scanf("%c",&ch);
    
	while((ch=='Y') || (ch=='y'))
    {
		printf("Enter data value ");
		scanf("%d",&no);

		insert(root,no);
		
		printf("Continue Addition ?(y/n) : ");
		fflush(stdin);
		scanf("%c",&ch);
    }
}

int deletion(node **rootptr,int no)
{
    node *p = *rootptr;
    
	if(p==NULL)
		return 0;
    
	if(p->data>no)
		return deletion(&p->left,no);
    
	if(p->data<no)
		return deletion(&p->right,no);

    if(p->right==NULL)
    {
		*rootptr = p->left;
		free(p);
		return 1;
    }
    
	if(p->left==NULL)
    {
		*rootptr = p->right;
		free(p);
		return 1;
    }

    p = p->right;
    while(p->left)
		p = p->left;
    
	(*rootptr)->data = p->data;
    
	deletion(&((*rootptr)->right),p->data);
	return 1;
}

void main()
{
    int no,ch,opt,y;
    node *root=NULL,*z;
    system("cls");
    
	create_tree(&root);
    
	while(root!=NULL)
    {
		//system("cls");
		printf("\n1:Insert\n");
		printf("2:Search\n");
		printf("3:Traverse\n");
		printf("4:Delete\n");
		printf("5:Quit\n");
		
		printf("Enter your choice ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("Enter data value ");
				scanf("%d",&no);
				y=insert(&root,no);
				if(y)
					printf("Element inserted successfully\n");
				else
					printf("Element already exixts\n");
				break;
	
			case 2:
				printf("Enter data value ");
				scanf("%d",&no);
				if(root==NULL)
				{
					printf("Tree is empty\n");
					break;
				}
				z=search(root,no);
				if(z!=NULL)
					printf("Successful search\n");
				else
					printf("Unsuccessful search\n");
				break;

			case 3:
				printf("How to traverse\n");
				printf("1:Inorder\n");
				printf("2:Preorder\n");
				printf("3:Postorder\n");
				printf("Enter your choice ");
				fflush(stdin);
				scanf("%d",&opt);
				switch(opt)
				{
					case 1:
					printf("Inorder traversal : ");
					inorder(root);
					break;
					case 2:
					printf("Preorder traversal : ");
					preorder(root);
					break;
					case 3:
					printf("Postorder traversal : ");
					postorder(root);
					break;
					default:
					printf("Invalid choice\n");
				}
				break;

			case 4:
				printf("Enter data value ");
				scanf("%d",&no);
				if(root==NULL)
				{
					printf("Tree is empty\n");
					break;
				}
				y = deletion(&root,no);
				if(y==1)
					printf("Successful deletion\n");
				else
					printf("Unsuccessful deletion\n");
				break;

			case 5:
				exit(0);
				break;
			
			default:
				printf("Invalid choice\n");
		} //end of switch
	
		getch();
    } //end of while
} //end of main


/*
OUTPUT :



Want to build a tree(y/n) y
Enter data value 1
Continue Addition ?(y/n) : y
Enter data value 2
Continue Addition ?(y/n) : y
Enter data value 3
Continue Addition ?(y/n) : y
Enter data value 10
Continue Addition ?(y/n) : y
Enter data value 34
Continue Addition ?(y/n) : y
Enter data value 12
Continue Addition ?(y/n) : y
Enter data value 13
Continue Addition ?(y/n) : y
Enter data value 17
Continue Addition ?(y/n) : y
Enter data value 100
Continue Addition ?(y/n) : n

1:Insert
2:Search
3:Traverse
4:Delete
5:Quit
Enter your choice 1
Enter data value 101
Element inserted successfully

1:Insert
2:Search
3:Traverse
4:Delete
5:Quit
Enter your choice 2
Enter data value 101
Successful search

1:Insert
2:Search
3:Traverse
4:Delete
5:Quit
Enter your choice 3
How to traverse
1:Inorder
2:Preorder
3:Postorder
Enter your choice 1
Inorder traversal : 1 2 3 10 12 13 17 34 100 101 

1:Insert
2:Search
3:Traverse
4:Delete
5:Quit
Enter your choice 3
How to traverse
1:Inorder
2:Preorder
3:Postorder
Enter your choice 3
Postorder traversal : 17 13 12 101 100 34 10 3 2 1 

1:Insert
2:Search
3:Traverse
4:Delete
5:Quit
Enter your choice 4
Enter data value 13
Successful deletion

1:Insert
2:Search
3:Traverse
4:Delete
5:Quit
Enter your choice 5
Press any key to continue
*/