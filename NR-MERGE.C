/*
	Program Purpose : To Perform Mrege Sort By Non-Recursive Method.
	Coded by : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV	
*/

#include<stdio.h>
#include<conio.h>

void MergeSort(int x[],int n)
{
	int i,lb1,j,lb2,ub1,ub2,k,temp[100],size=1,l,c=0;

	while(size<n)
	{
		c++;
		lb1 = 0;
		k = 0;
		while((lb1+size)<n)
		{
			lb2 = lb1+size;

			ub1 = lb2-1;
			ub2 = ((ub1+size)<n)?ub1+size:n-1;

			i = lb1;
			j = lb2;

			while(i<=ub1 && j<=ub2)
				if(x[i]<x[j])
					temp[k++] = x[i++];
				else
					temp[k++] = x[j++];

			while(i<=ub1)
				temp[k++] = x[i++];

			while(j<=ub2)
				temp[k++] = x[j++];

			lb1 = ub2+1;
		}

		for(i=0;i<=ub2;i++)
			x[i] = temp[i];

		size *= 2;

		printf("\n");

		printf("After Pass[%d] : ",c);
		for(l=0;l<n;l++)
			printf("%d ",x[l]);
	}
}

void main()
{
	int a[20],n,k;
	system("cls");

	printf("Enter total No. Of Elements : ");
	scanf("%d",&n);
	printf("\nEnter the Numbers : ");
	for(k=0;k<n;k++)
	{
		scanf("%d",&a[k]);
	}

	MergeSort(a,n);

	getch();
}

/*
OUTPUT :

Enter total No. Of Elements : 12

Enter the Numbers : 32 21 12 22 1 2 4 3 6 100 12 45

After Pass[1] : 21 32 12 22 1 2 3 4 6 100 12 45
After Pass[2] : 12 21 22 32 1 2 3 4 6 12 45 100
After Pass[3] : 1 2 3 4 12 21 22 32 6 12 45 100
After Pass[4] : 1 2 3 4 6 12 12 21 22 32 45 100

*/