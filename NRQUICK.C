/*
	Program Purpose : To Perform Quick Sort Using Non-Recursive Method.
	Coded by : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV	
*/

#include <stdio.h>
#include <conio.h>
int c,n;

int partition(int x[], int lb, int ub)
{
	int pos = lb, i, temp;
	
	for(i = lb + 1;i <= ub; i++)
		if(x[i] < x[lb])
		{
			pos++;
			temp = x[i];
			x[i] = x[pos];
			x[pos] = temp;
		}
	
	temp = x[pos];
	x[pos] = x[lb];
	x[lb] = temp;
	
	return pos;
}

void quicksort(int data[], int lb, int ub)
{
	struct datas
	{
		int l,u;
	};
	struct datas stack[100];
	
	int top = 0, i;

	stack[top].l = lb;
	stack[top].u = ub;

	while(top >= 0)
	{
		lb = stack[top].l;
		ub = stack[top].u;
		top--;

		while(lb < ub)
		{
			i = partition(data,lb,ub);
			top++;
			stack[top].l = i + 1;
			stack[top].u = ub;
			ub = i - 1;
		}
			
		printf("\n");
		printf("  At Pass[%d] :",++c);
		for(i=0;i<13;i++)
			printf("%d ",data[i]);
	}
}

void main()
{
	int data[] = {7,6,5,4,2,3,1,0,12,13,17,22,45};
	int i = 0;
	system("cls");
	
	printf("Original Data : ");
	for(i = 0;i < 13;i++)
		printf("%d ",data[i]);
	
	quicksort(data,0,13-1);
	
	printf("\n\nSorted Data : ");
	for(i = 0;i<13;i++)
		printf("%d ",data[i]);
	
	getch();
}


/*
OUTPUT :


Original Data : 7 6 5 4 2 3 1 0 12 13 17 22 45
  At Pass[1] :0 6 5 4 2 3 1 7 12 13 17 22 45
  At Pass[2] :0 1 5 4 2 3 6 7 12 13 17 22 45
  At Pass[3] :0 1 2 3 4 5 6 7 12 13 17 22 45
  At Pass[4] :0 1 2 3 4 5 6 7 12 13 17 22 45
  At Pass[5] :0 1 2 3 4 5 6 7 12 13 17 22 45
  At Pass[6] :0 1 2 3 4 5 6 7 12 13 17 22 45
  At Pass[7] :0 1 2 3 4 5 6 7 12 13 17 22 45
  At Pass[8] :0 1 2 3 4 5 6 7 12 13 17 22 45
  At Pass[9] :0 1 2 3 4 5 6 7 12 13 17 22 45
  At Pass[10] :0 1 2 3 4 5 6 7 12 13 17 22 45
  At Pass[11] :0 1 2 3 4 5 6 7 12 13 17 22 45

Sorted Data : 0 1 2 3 4 5 6 7 12 13 17 22 45
*/