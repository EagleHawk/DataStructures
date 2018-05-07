/*
	Program Purpose : To Perform INDEX SEQUENCIAL SEARCH 
	Coded by : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV	
*/

#include<stdio.h>
#include<conio.h>

int inseq(int data[],int index[],int no,int indexsize ,int offset)
{
	int i = 0;

	if(no>index[indexsize-1])
		return -1;
	
	if(no<index[0])
		return -1;
	
	while(index[i]<no) i++;
		if(index[i]==no)
			return i*offset;
	
	for(i=i*offset;data[i]>no;i--);
		if(data[i]==no)
			return i;
	
	return -1;
}

int indexit(int data[],int n,int offset,int index[])
{
	int i = 0,j = 0;

	for(i=0;i<n;i+=offset)
		index[j++]=data[i];
	
	if((n-1)%offset)
		index[j++]=data[n-1];
		 
	return j;
}

void main()
{
	int data[] = {0,1,2,3,4,5,6,7,8,9,10,15,23,42,54,55,60,62,78,88};
	int x,n,i,k;
	char ch = 'y';
	int index[5];
	system("cls");

	printf("Original Data : ");
	for(i=0;i<20;i++)
		printf("%d ",data[i]);
	
	n = indexit(data,20,5,index);
	
	do
	{
		printf("\nEnter element to be searched - ");
		fflush(stdin);
		scanf("%d",&k);

		x = inseq(data,index,k,n+1,5);

		if(x!=-1)
			printf("Search successfull \t Index = %d ",x+1);
		else
			printf("Search Unsuccessfull ");
		
		printf("\n want to continue (y/n) : ");
		fflush(stdin);
		scanf("%c",&ch);
	} while(ch=='y');
	
	getch();
}


/*
OUTPUT : 


Original Data : 0 1 2 3 4 5 6 7 8 9 10 15 23 42 54 55 60 62 78 88
Enter element to be searched - 7
Search successfull       Index = 8
Continue (y/n) : y

Enter element to be searched - 12
Search Unsuccessfull
Continue (y/n) :  n
*/