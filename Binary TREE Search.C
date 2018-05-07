/*
	Program Purpose : To Create a BinaryTree and Search the Elements in it.
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
    
	printf("Want to build a tree(y/n)? : ");
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

void main()
{
    int no,ch,opt,y;
    node *root=NULL,*z;
    system("cls");
    
    create_tree(&root);
    
    while(root!=NULL)
    {
		system("cls");
		printf("\n1:Insert\n");
		printf("2:Search\n");
		printf("3:Quit\n");
		
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
				z = search(root,no);
				if(z!=NULL)
					printf("Successful search\n");
				else
					printf("Unsuccessful search\n");
				break;

			case 3:
				exit(0);
				break;
			
			default:
				printf("Invalid choice\n");
		} //end of switch
		getch();
    } //end of while
} //end of main