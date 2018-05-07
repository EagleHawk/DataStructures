/*
	Program Purpose : To Create a BinaryTree and Perform Sort on it.
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

	void inorder(node *tra)
	{
		if(tra!=NULL)
		{
			inorder(tra->left);
			printf("%d ",tra->data);
			inorder(tra->right);
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

	void main()
	{
		int no,ch,opt,y;
		node *root=NULL,*z;
		system("cls");
    
		create_tree(&root);
    
		printf("\nSorted Data : ");
		inorder(root);
		
	} //end of main


	
	OUTPUT :

	Want to build a tree(y/n) y
	Enter data value 1
	Continue Addition ?(y/n) : y
	Enter data value 34
	Continue Addition ?(y/n) : y
	Enter data value 13
	Continue Addition ?(y/n) : y
	Enter data value 17
	Continue Addition ?(y/n) : y
	Enter data value 29
	Continue Addition ?(y/n) : y
	Enter data value 100
	Continue Addition ?(y/n) : y
	Enter data value 7
	Continue Addition ?(y/n) : y
	Enter data value 19
	Continue Addition ?(y/n) : y
	Enter data value 1000
	Continue Addition ?(y/n) : y
	Enter data value 91
	Continue Addition ?(y/n) : n

	Sorted Data : 1 7 13 17 19 29 34 91 100 1000 
	Press any key to continue
	