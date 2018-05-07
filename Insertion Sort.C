/*
	Program Purpose : To Perform Insertion sort.
	Coded by : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV	
*/

#include<stdio.h>
#include<conio.h>

void Insertionsort (int x[],int n)
{
	int p,i,j,no;

	for(i=1;i<n;i++)
	{
		no = x[i];
		for (j=i-1;j>=0;j--)
			if(x[j]>no)
				x[j+1] = x[j];
			else
				break;
		
		x[j+1] = no;
		printf("\n After Pass[%d] : ",i);
		for(p=0;p<n;p++)
			printf("%d  ", x[p]);

	}
}

void main()
{
	int x[] = {10,8,7,6,5,45,3,2,1,0};
	int i = 0;
	system("cls");

	printf("Original Data : ");
	for(i=0;i<10;i++)
		printf("%d ",x[i]);
	
	Insertionsort(x,10);
	
	printf("\nSorted Data : ") ;
	for(i=0;i<10;i++)
		printf("%d ",x[i]);
	
	getch();
}


/*
OUTPUT : 


Original Data : 10 8 7 6 5 45 3 2 1 0
 After Pass[1] : 8  10  7  6  5  45  3  2  1  0
 After Pass[2] : 7  8  10  6  5  45  3  2  1  0
 After Pass[3] : 6  7  8  10  5  45  3  2  1  0
 After Pass[4] : 5  6  7  8  10  45  3  2  1  0
 After Pass[5] : 5  6  7  8  10  45  3  2  1  0
 After Pass[6] : 3  5  6  7  8  10  45  2  1  0
 After Pass[7] : 2  3  5  6  7  8  10  45  1  0
 After Pass[8] : 1  2  3  5  6  7  8  10  45  0
 After Pass[9] : 0  1  2  3  5  6  7  8  10  45
Sorted Data : 0 1 2 3 5 6 7 8 10 45
*/