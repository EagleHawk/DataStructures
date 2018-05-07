/*
	Program Purpose : To Perform Quick Sort.
	Coded by : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV	
*/

#include<stdio.h>
#include<conio.h>
int c = 0;

int partition(int data[],int lb,int ub)
{
	int d = lb,temp,i;
	
	c++;
	for(i=lb+1;i<=ub;i++)
	{
		if(data[lb]>data[i])
		{
			d++;
			temp = data[i];
			data[i] = data[d];
			data[d] = temp;
		}
	}
	
	temp = data[lb];
	data[lb] = data[d];
	data[d] = temp;

	return d;
}

void quicksort(int data[],int lb,int ub,int n)
{
	int p,i;
	if(lb<ub)
	{
		p = partition(data,lb,ub);
		printf("\n");
		
		printf("After Pass[%d] : ",c);
		for(i=0;i<8;i++)
			printf("%d ",data[i]);
		
		quicksort(data,lb,p-1,n);
		quicksort(data,p+1,ub,n);
	}
}

void main()
{
	int data[] = {7,6,5,4,2,3,1,0};
	int i = 0;
	system("cls");

	printf("Original Array : ");
	for(i=0;i<8;i++)
		printf("%d ",data[i]);
	
	quicksort(data,0,8-1,8);

	printf("\n\nFinal Array : ");
	for(i=0;i<8;i++)
		printf("%d ",data[i]);

	getch();
}

/*
OUTPUT : 

Original Array : 7 6 5 4 2 3 1 0
After Pass[1] : 0 6 5 4 2 3 1 7
After Pass[2] : 0 6 5 4 2 3 1 7
After Pass[3] : 0 1 5 4 2 3 6 7
After Pass[4] : 0 1 5 4 2 3 6 7
After Pass[5] : 0 1 3 4 2 5 6 7
After Pass[6] : 0 1 2 3 4 5 6 7

Final Array : 0 1 2 3 4 5 6 7
*/