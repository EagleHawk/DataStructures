/*
	Program Purpose : To Perform Heap Sort.
	Coded by : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV	
*/


#include<stdio.h>
#include<conio.h>
int j = 0;

void heapup(int x[],int root,int bottom)
{
	int parent,temp;
	
	if(bottom>root)
	{
		parent = (bottom - 1) / 2;
		if(x[parent]<x[bottom])
		{
			temp = x[parent];
			x[parent] = x[bottom];
			x[bottom] = temp;
			heapup(x,root,parent);
		}
	}
}

void heapdown(int x[],int root,int bottom)
{
	int lchild = 2*root+1;
	int rchild = 2*root+2;
	int maxchild,temp;
	
	if(lchild<=bottom)
	{
		if(lchild==bottom)
			maxchild = lchild;
		else if(x[lchild]>x[rchild])
				maxchild = lchild;
		else
			maxchild = rchild;
		
		if(x[root]<x[maxchild])
		{
			temp = x[root];
			x[root] = x[maxchild];
			x[maxchild] = temp;
		
			heapdown(x,maxchild,bottom);
		}
	}
}

void heapsort(int x[])
{
	int p,i,temp;
	for(i=0;i<10-1;i++)
		heapup(x,0,i+1);
	
	for(i=10-1;i>0;i--)
	{
		temp = x[0];
		x[0] = x[i];
		x[i] = temp;
		
		heapdown(x,0,i-1);
		
		printf("\n After Pass[%d] :  ",++j);
		for(p=0;p<10;p++)
			printf("%d  ", x[p]);
	}
}

void main()
{
	int data[] = {10,9,8,7,6,5,4,2,3,1};
	// 10 Elements in Total.
	int k = 0;
	system("cls");
	
	printf("Original Data : ");
	for(k=0;k<10;k++)
	{
		printf("%d ",data[k]);
	}
	
	heapsort(data);
	
	printf("\n");
	
	printf("Sorted Data : ");
	for(k=0;k<10;k++)
		printf("%d ",data[k]);
	
	getch();
}



/*
OUTPUT :


Original Data : 10 9 8 7 6 5 4 2 3 1
 After Pass[1] :  9  7  8  3  6  5  4  2  1  10
 After Pass[2] :  8  7  5  3  6  1  4  2  9  10
 After Pass[3] :  7  6  5  3  2  1  4  8  9  10
 After Pass[4] :  6  4  5  3  2  1  7  8  9  10
 After Pass[5] :  5  4  1  3  2  6  7  8  9  10
 After Pass[6] :  4  3  1  2  5  6  7  8  9  10
 After Pass[7] :  3  2  1  4  5  6  7  8  9  10
 After Pass[8] :  2  1  3  4  5  6  7  8  9  10
 After Pass[9] :  1  2  3  4  5  6  7  8  9  10
Sorted Data : 1 2 3 4 5 6 7 8 9 10
*/