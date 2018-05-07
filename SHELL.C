/*
	Program Purpose : To Perform Shell Sort.
	Coded by : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV	
*/

#include<stdio.h>
#include<conio.h>

void shell(int data[],int n)
{
	int c = 1,i,j,x,h;
	h = n/2;
	
	while(h>0)
	{
		for(i=h;i<=n-1;i++)
		{
			x = data[i];
			j = i;
			while(data[j-h]>x && j>h-1)
			{
			  data[j] = data[j-h];
			  j = j - h;
			}
			data[j] = x;
		}

		h = h / 2;

		printf("\nAfter Pass[%d] ",c++);
		for(i=0;i<n;i++)
			printf("%d  ", data[i]);
	}
}

void main()
{
	int data[100] = {10,13,23,1,2,4,3,6,5,2,1,8,90,17};
	int k = 0;
	system("cls");

	
	printf("Origianl Data : ");
	for(k=0;k<13;k++)
		printf("%d ",data[k]);
	
	shell(data,13);
	
	printf("\n\nSorted Data :");
	for(k=0;k<13;k++)
		printf("%d ",data[k]);

	getch();
}

/*
OUTPUT : 

Origianl Data : 10 13 23 1 2 4 3 6 5 2 1 8 90
After Pass[1] 3  6  5  1  1  4  10  13  23  2  2  8  90
After Pass[2] 1  1  4  2  2  5  3  6  8  10  13  23  90
After Pass[3] 1  1  2  2  3  4  5  6  8  10  13  23  90

Sorted Data :1 1 2 2 3 4 5 6 8 10 13 23 90
*/