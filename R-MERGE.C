/*
	Program Purpose : To Perform Merge Sort Using Recursive Method.
	Programmed By   : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV	
*/

#include<stdio.h>
#include<conio.h>


void merge(int data[],int lb1,int ub1,int ub2)
{
	int i = lb1;
	int j = ub1 + 1;
	int k = 0,temp[100];
	
	while(i<=ub1 && j<=ub2)
		if (data[i]<data[j])
			temp[k++] = data[i++];
		else
			temp[k++] = data[j++];

	while(i<=ub1)
		temp[k++] = data[i++];
	
	while(j<=ub2)
		temp[k++] = data[j++];
	
	k = 0;
	for(i=lb1;i<=ub2;i++)
		data[i] = temp[k++];
}

void mergesort(int data[],int lb,int ub)
{
	int mid,p,i = 0;
	
	if (lb<ub)
	{
		mid = (lb+ub)/2;
		
		mergesort(data,lb,mid);
		mergesort(data,mid+1,ub);
		merge(data,lb,mid,ub);
		
		printf("\n\nCall %d : ",++i);
		for(p=0;p<7;p++)
			printf("%d  ", data[p]);
	}
}

void main()
{
	int data[7] = {2,4,3,1,6,7,45};
	int i,m;
	system("cls");

	printf("Original Data : ");
	for(i=0;i<7;i++)
		printf("%d ",data[i]);
	
	mergesort(data,0,7);
	printf("\n\nSorted Data : ") ;
	
	for(m=0;m<7;m++)
		printf("%d ",data[m]);

	getch();
}

/*
OUTPUT :

Original Data : 2 4 3 1 6 7 45

Call 1 : 2  4  3  1  6  7  45

Call 2 : 2  4  1  3  6  7  45

Call 3 : 1  2  3  4  6  7  45

Call 4 : 1  2  3  4  6  7  45

Call 5 : 1  2  3  4  6  7  45

Call 6 : 1  2  3  4  6  7  45

Call 7 : 1  2  3  4  6  7  45

Sorted Data : 1 2 3 4 6 7 45
*/