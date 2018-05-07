/*
	Program Purpose : To Perform the Hashing technique in the search
			          Techniques.
	Programed By    : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV	
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define HASHVAL 23

typedef struct node
{
	struct node *link;
	int data;
}node;

node * getnode()
{
	return (node*)malloc(sizeof(node));
}

void hashing (int data_arr[],node *h[],int n)
{
	int i,v;
	node *ptr,*p;

	for (i=0;i<n;i++)
	{
		v = data_arr[i] % HASHVAL;
		p = getnode();
		p->data = data_arr[i];
		p->link = NULL;

		if(h[v]==NULL)
			h[v] = p;
		else
			ptr = h[v];

		while(ptr->link!=NULL)
			ptr = ptr->link;

		ptr->link = p;
   }
}

int hashsear (node *h[],int no)
{
	node *ptr;
	int v;
	int count = 0;

	v = no % HASHVAL;

	if(h[v]==NULL)
		return -1;

	for (ptr=h[v];ptr!=NULL;ptr=ptr->link)
	{
		count++;
		if(ptr->data==no)
			return count;
	}
	return -1;
}

void main()
{
	int data_arr[] = {0,1,2,3,4,5,6,7,8,9,10,15,23,67,90,112,122,245,687,878};
	node *h[HASHVAL] = {NULL};

	int x,n,i;
	char ch;
	int sch = 0;
	clrscr();
	n = 20;

	printf("Original Array Data : \n");
	for(i=0;i<20;i++)
		printf("%d ",data_arr[i]);

	hashing (data_arr,h,n) ;

	while(!(ch=='n'))
	{
		printf("\nEnter the Element for Search : ");
		fflush(stdin);
		scanf("%d",&sch);

		x = hashsear(h,sch);

		if(x!=-1)
			printf("Data Found. \n\n ",x);
		else
			printf("Data Not Found. ");

		printf("\nDo You want to continue (y,n)? : ");
		fflush(stdin);
		scanf("%c",&ch);
	}
	printf("\nPress Any Key to continue....");

	getch();
}


/*
OUTPUT :

Original Array Data :
0 1 2 3 4 5 6 7 8 9 10 15 23 67 90 112 122 245 687 878
Enter the Element for Search : 12
Data Not Found.
Do You want to continue (y,n)? : y

Enter the Element for Search : 112
Data Found.


Do You want to continue (y,n)? : n

Press Any Key to continue....
*/