/* 
	Program Purpose : To Perform RADIX SORT 
	Coded by : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV	
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define m 3

struct node
{
	int data;
	struct node * next;
}node;

void radix(int data[],int n)
{
	struct node * front[10],* rear[10];
	struct node *start,*prev,*p;
	
	int i,j,y,l,k,p1,exp;
	start = NULL;
	
	for(i=0;i<=n-1;i++)
	{
		p = (struct node *)malloc(sizeof(node));
		p->data = data[i];
		p->next = NULL;
		
		if(start==NULL)
			start = p;
		else
			prev->next=p;
		
		prev = p;
	}
	
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=9;j++)
		    front[j]=rear[j]=NULL;
	  
		exp = 1;
		
		for(k=1;k<=i-1;k++)
			exp = exp * 10;
	  
		p = start;
	  
		while(p!=NULL)
		{
			l = p->data;
			y = (l/exp)%10;
			
			if(front[y]==NULL)
				front[y]=p;
			else
				rear[y]->next=p;
			
			rear[y] = p;
			p = p->next;
		}
	  
		start = NULL;
	  
	  	for(k=0;k<=9;k++)
		{
			if(front[k]!=NULL)
			{
				if(start==NULL)
					start = front[k];
				else
					rear[p1]->next = front[k];
			  
				p1 = k;
			}
		}
		
		rear[p1]->next = NULL;

//		printf("After Pass : ");
//		for(i=0;i<n;i++)
//			printf("%d ",a[i]);
	}
	
	p = start;
	for(i=0;i<=n-1;i++)
	{
	  data[i] = p->data;
	  p = p->next;
	}
}

void main()
{
	int data[100],n,k;
	system("cls");

	printf("Enter Total No. Of Elements : ");
	scanf("%d",&n);
	
	for(k=0;k<n;k++)
	{
		printf("Enter element %d : ",k+1);
		scanf("%d",&data[k]);
	}
	
	radix(data,n);
	
	printf("\nThe sorted output is\n");
	for(k=0;k<n;k++)
		printf("%d ",data[k]);

	getch();
}


/*
OUTPUT :



Enter Total No. Of Elements : 13
Enter element 1 : 2
Enter element 2 : 3
Enter element 3 : 5
Enter element 4 : 2
Enter element 5 : 13
Enter element 6 : 5
Enter element 7 : 7
Enter element 8 : 56
Enter element 9 : 17
Enter element 10 : 43
Enter element 11 : 4
Enter element 12 : 3
Enter element 13 : 6

The sorted output is
2 2 3 3 4 5 5 6 7 13 17 43 56
*/