/* 
	Program Purpose : To Perform INTERPOLATION SEARCH 
	Coded by : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV	
*/

#include<stdio.h>
#include<conio.h>

int interpol(int a[],int n,int no)
{
	int lb=0,ub=n-1,ind;

	while(a[ind]!=no)
	{
		if(no<a[lb]||no>a[ub])
			return -1;
		
		ind=(no-a[lb])*(ub-lb)/(a[ub]-a[lb])+lb;
		
		if(a[ind]>no)
			ub = ind-1;
		else
			lb = ind + 1;
	}

	return ind;
}

void main()
{
	int data[]={0,1,2,3,4,5,7,8,9,10,15,23,67,90};

	int x,i = 0,k = 0;
	char ch = 'y';
	system("cls");

	printf("Data Available : ");
	for(i=0;i<15;i++)
		printf("%d   ",data[i]);

	do
	{
		printf("\nEnter element to be searched - ");
		fflush(stdin);
		scanf("%d",&k);

		x = interpol(data,15,k);

		if(x!=-1)
			printf("Search Successfull \t Location = %d\n ",x+1);
		else
			printf("Search Unsuccessful\n ");
			
		printf("Continue (y/n) ?: ");
		fflush(stdin);
		scanf("%c",&ch);
	} while(ch=='y');
	printf("\n");
	getch();
}


/*
OUTPUT :

Data Available : 0   1   2   3   4   5   7   8   9   10   15   23   67   90   30
979
Enter element to be searched - 9
Search Successfull       Location = 9
 Continue (y/n) ?: y

Data Available : 0   1   2   3   4   5   7   8   9   10   15   23   67   90   30
979
Enter element to be searched - 12
Search Unsuccessfull
 Continue (y/n) ?: n
 */