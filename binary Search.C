/*
	Program Purpose : To Perform Binary Search
	Coded by : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV
*/

#include<stdio.h>
#include<conio.h>

int BinarySrec(int data[],int limit,int srec)
{
	int left = 0;
	int right = limit - 1;
	int mid = 0;

	while (left<=right)
	{
		mid = (left + right) /2;

		if(data[mid]==srec)
			return 1;
		else if(data[mid]<srec)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return 0;
}


void main()
{
	int data[] = {1,2,3,4,5,7,12,13,14,15,17,21,23};
	int srec = 0;
	int i = 0;
	char ch = 'y';
	system("cls");

	printf("Present Data : ");
	for(i=0;i<13;i++)
		printf("%d ",data[i]);

	while(ch=='y')
	{
		printf("\nEnter the Element to be Searched : ");
		scanf("%d",&srec);

		if(BinarySrec(data,13,srec)==1)
			printf("Element Found");
		else
			printf("Element Not Found");

		printf("\n\nDo you Wanna to Continue [y\\n] ? : ");
		scanf("%c",&ch);
	}

	getch();
}


OUTPUT :

Present Data : 1 2 3 4 5 7 12 13 14 15 17 21 23
Enter the Element to be Searched : 23
Element Found

Do you Wanna to Continue [y\n] ? : y
Enter the Element to be Searched : 10
Element Not Found

Do you Wanna to Continue [y\n] ? : n