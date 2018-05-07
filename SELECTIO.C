/*
	Program Purpose : To Perform Selection Sort.
	Coded by : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV	
*/

#include<stdio.h>
#include<conio.h>

void selection(int data[],int n)
{
	int i,j,min,max,minp,maxp,p;
	
	for (j=0;j<n/2;j++)
	{
		min = max = data[j];
		minp = maxp = j;
		for (i=j+1;i<n-j;i++)
		{
			if (data[i]<min)
			{
				min = data[i];
				minp = i;
			}
			else if(data[i]>max)
			{
				max = data[i];
				maxp = i;
			}
		}

		data[maxp] = data[n-j-1];
		data[n-j-1] = max;
		
		if(data[maxp]==min)
			minp=maxp;
		
		data[minp] = data[j];
		data[j] = min;
		
		printf("\nAfter Pass%d] : ",j+1);
		for(p=0;p<n;p++)
			printf("%d  ", data[p]);
	}
}

void main()
{
	int data[] = {10,9,8,7,6,5,4,2,3,1};
	int i = 0;
	system("cls");

	printf("Origianl Data : " );
	
	for(i=0;i<10;i++)
		printf("%d ",data[i]);
	
	selection(data,10);
	
	printf("\nSorted Data : ") ;
	for(i=0;i<10;i++)
		printf("%d ",data[i]);
	
	getch();
}


/*
OUTPUT :

Origianl Data : 10 9 8 7 6 5 4 2 3 1
After Pass1] : 1  9  8  7  6  5  4  2  3  10
After Pass2] : 1  2  8  7  6  5  4  3  9  10
After Pass3] : 1  2  3  7  6  5  4  8  9  10
After Pass4] : 1  2  3  4  6  5  7  8  9  10
After Pass5] : 1  2  3  4  5  6  7  8  9  10
Sorted Data : 1 2 3 4 5 6 7 8 9 10
*/