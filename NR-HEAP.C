/* 
	Program Purpose :NON RECURSIVE HEAP SORT 
	Coded by : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV	
*/

#include<stdio.h>
#include<conio.h>

void adjust(int data[],int n,int i)
{
	int j,x;

	j = i * 2;
	x = data[i];
	
	while(j<=n)
	{
		if(j<n && data[j]<data[j+1])
			j++;
		
		if(data[j]<x)
			break;
		
		data[j/2] = data[j];
		j = j * 2;
	}

	data[j/2] = x;

	printf("\n After Pass : ");
	for(i=1;i<=13;i++)
		printf("%d ",data[i]);
}
void main()
{
	int data[] = {10,13,23,1,2,4,3,6,5,2,1,8,90,17};
	int i = 0,t = 0;
	system("cls");

	printf("Origianl Data : ");
	for(i=1;i<=13;i++)
		printf("%d ",data[i]);

	for(i=13/2;i>=1;i--)
		adjust(data,13,i);

	for(i=13;i>=2;i--)
	{
		t = data[1];
		data[1] = data[i];
		data[i] = t;
		adjust(data,i-1,1);
	}
	printf("\n");
	
	printf("\nSorted Data :");
	for(i=1;i<=13;i++)
		printf("%d ",data[i]);
	getch();
}

/*
OUTPUT :

Origianl Data : 13 23 1 2 4 3 6 5 2 1 8 90 17
 After Pass : 13 23 1 2 4 90 6 5 2 1 8 3 17
 After Pass : 13 23 1 2 8 90 6 5 2 1 4 3 17
 After Pass : 13 23 1 5 8 90 6 2 2 1 4 3 17
 After Pass : 13 23 90 5 8 17 6 2 2 1 4 3 1
 After Pass : 13 23 90 5 8 17 6 2 2 1 4 3 1
 After Pass : 90 23 17 5 8 13 6 2 2 1 4 3 1
 After Pass : 23 8 17 5 4 13 6 2 2 1 1 3 90
 After Pass : 17 8 13 5 4 3 6 2 2 1 1 23 90
 After Pass : 13 8 6 5 4 3 1 2 2 1 17 23 90
 After Pass : 8 5 6 2 4 3 1 1 2 13 17 23 90
 After Pass : 6 5 3 2 4 2 1 1 8 13 17 23 90
 After Pass : 5 4 3 2 1 2 1 6 8 13 17 23 90
 After Pass : 4 2 3 1 1 2 5 6 8 13 17 23 90
 After Pass : 3 2 2 1 1 4 5 6 8 13 17 23 90
 After Pass : 2 1 2 1 3 4 5 6 8 13 17 23 90
 After Pass : 2 1 1 2 3 4 5 6 8 13 17 23 90
 After Pass : 1 1 2 2 3 4 5 6 8 13 17 23 90
 After Pass : 1 1 2 2 3 4 5 6 8 13 17 23 90

Sorted Data :1 1 2 2 3 4 5 6 8 13 17 23 90
*/