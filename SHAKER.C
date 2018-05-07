/*
	Program Purpose : To Perform Shaker Sort
	Coded by : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV	
*/


#include<stdio.h>
#include<conio.h>

void Shaker(int x[],int n)
{
	int i,j,temp;
	int swap = 1;
	
	for(j=1;swap;j++)
	{
		swap = 0;
		if(j%2==1)
			for(i=j/2;i<=n-2-j/2;i++)
			{		
				if(x[i+1]<x[i])
				{
					temp = x[i];
					x[i] = x[i+1];
					x[i+1] = temp ;
					swap = 1;
				}
			}
		else
			for(i=n-1-j/2;i>=j/2;i--)
				if(x[i-1]>x[i])
				{
					temp = x[i];
					x[i] = x[i-1];
					x[i-1] = temp ;
					swap = 1;
				}
				
		printf("\nAfter Pass[%d] : ",j);
		for(i=0;i<n;i++)
			printf("%d  ", x[i]);

	}
}
void main()
{
	int x[] = {10,13,23,1,2,4,3,6,5,2,1,8,90,17};
	int i = 0;
	System("cls");

	printf("Original Data : ");
	for(i=0;i<13;i++)
		printf("%d ",x[i]);
	
	Shaker(x,13);
	printf("\n\nSorted Data : ") ;
	for(i=0;i<13;i++)
		printf("%d ",x[i]);
	
	getch();
}


/*
OUTPUT : 


Original Data : 10 13 23 1 2 4 3 6 5 2 1 8 90
After Pass[1] : 10  13  1  2  4  3  6  5  2  1  8  23  90
After Pass[2] : 1  10  13  1  2  4  3  6  5  2  8  23  90
After Pass[3] : 1  10  1  2  4  3  6  5  2  8  13  23  90
After Pass[4] : 1  1  10  2  2  4  3  6  5  8  13  23  90
After Pass[5] : 1  1  2  2  4  3  6  5  8  10  13  23  90
After Pass[6] : 1  1  2  2  3  4  5  6  8  10  13  23  90
After Pass[7] : 1  1  2  2  3  4  5  6  8  10  13  23  90

Sorted Data : 1 1 2 2 3 4 5 6 8 10 13 23 90
*/