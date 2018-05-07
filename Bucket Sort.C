/*
	Program Purpose : To Perform Bucket Sort.
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
    struct node_tag *link;
}node;

node *getnode()
{
    return (node *)malloc(sizeof(node));
}

void bucket(int data[], int n)
{
    int j,i,c = 0;
    node *ptr[10],*curr,*tra,*tra1;
    
	for(i=0;i<=9;i++)
		ptr[i] = NULL;
    
	for(i=0;i<n;i++)
    {
		curr = getnode();
		curr->data = data[i];
		curr->link = NULL;
		
		j = data[i] / 10;
		
		if(ptr[j]==NULL)
			ptr[j] = curr;
		else
		{
			tra1 = tra = ptr[j];
			while(tra->data<data[i] && tra!=NULL)
			{
				tra1 = tra;
				tra = tra->link;
			}
			
			if(tra==ptr[j])
			{
				curr->link = ptr[j];
				ptr[j] = curr;
			}
			else if(tra==NULL)
				tra1->link=curr;
			else
			{
				tra1->link = curr;
				curr->link = tra;
			}
		}
    }
    
	for(i=0;i<10;i++)
    {
		if(ptr[i]!=NULL)
		{
			tra = ptr[i];
			while(tra!=NULL && c<n)
			{
				data[c] = tra->data;
				tra = tra->link;
				c++;
			}
		}
    }
}

void main ()
{
    int data[10],i,n;
    system("cls");

    printf("Enter Total No. of elements ");
    scanf("%d",&n);

    printf("Enter elements between 0 to 99\n");
    for(i=0;i<n;i++)
    {
		printf("Enter element %d: ",i+1);
		scanf("%d",&data[i]);
    }

	bucket(data,n);

	printf("\nSorted Data : ") ;
    for(i=0;i<n;i++)
		printf("%d ",data[i]);

    printf("\nPress Any key to Continue.....");
    getch();
}

/*
OUTPUT :


Enter Total No. of elements 7
Enter elements between 0 to 99
Enter element 1: 1
Enter element 2: 4
Enter element 3: 2
Enter element 4: 3
Enter element 5: 13
Enter element 6: 3
Enter element 7: 7

Sorted Data : 1 2 3 3 4 7 13 
Press Any key to Continue....3.
*/

