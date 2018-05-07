/*
	Program Files : To Perfom Bubble Sort.
	Coded by : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV	
*/

#include<stdio.h>
#include<conio.h>

void Bubblesort(int data[],int n)
{
	int i,j,p,temp;
	int swap = 1;

	for(j=1;swap;j++)
	{
		swap = 0;
		for(i=0;i<10-j;i++)
		{
			if(data[i+1]<data[i])
			{
				temp = data[i];
				data[i] = data[i+1];
				data[i+1] = temp ;
				swap = 1;
			}
		}
		printf("\nAfter Pass[%d] : ",j);
		for(p=0;p<n;p++)
			printf("%d  ", data[p]);
	}
}

void main()
{
	int data[] = {10,9,8,7,6,5,4,32,1,0};
	int m = 0;
	system("cls");
	
	printf("\nOriginal Data : ");
	for(m=0;m<10;m++)
		printf("%d ",data[m]);

	Bubblesort(data,10);
	
	printf("\nSorted Data : ");
	for(m=0;m<10;m++)
		printf("%d ",data[m]);

	getch();
}



/*
OUTPUT : 

Original Data : 10 9 8 7 6 5 4 32 1 0
After Pass[1] : 9  8  7  6  5  4  10  1  0  32
After Pass[2] : 8  7  6  5  4  9  1  0  10  32
After Pass[3] : 7  6  5  4  8  1  0  9  10  32
After Pass[4] : 6  5  4  7  1  0  8  9  10  32
After Pass[5] : 5  4  6  1  0  7  8  9  10  32
After Pass[6] : 4  5  1  0  6  7  8  9  10  32
After Pass[7] : 4  1  0  5  6  7  8  9  10  32
After Pass[8] : 1  0  4  5  6  7  8  9  10  32
After Pass[9] : 0  1  4  5  6  7  8  9  10  32
After Pass[10] : 0  1  4  5  6  7  8  9  10  32
Sorted Data : 0 1 4 5 6 7 8 9 10 32
*/