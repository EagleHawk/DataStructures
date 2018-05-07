/*
	Program Purpose : T Perform Topological Sort on the Graphs.
	Coded by : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV	
*/

#include<stdio.h>
#include<conio.h>
int check[10];

int count(int x[],int n)
{
	int i,c = 0;
	
	for(i=0;i<n;i++)
	   c=c+x[i];
	if(c==n)return 1;
	return 0;
}
void primat (int a[][10],int n,int m)
{
    int i,j;
    for(i=1;i<=m;i++)
		printf("\t%d",i);
    
	printf("\n");
    
	for(i=0;i<n;i++)
    {
		printf("%d",i+1);
		
		for(j=0;j<m;j++)
			printf("\t%d",a[i][j]);
		printf("\n");
    }
}
void admat(int a[][10])
{
    int i,j,e;
    printf("\nWant to enter an edge(0:no 1:yes) ");
    scanf("%d",&e);
    
	while(e)
    {
		printf("Enter node number from & to ");
		scanf("%d%d",&i,&j);

		a[--i][--j] = 1;
		
		printf("\nWant to enter an edge(0:no 1:yes) ");
		scanf("%d",&e);
    }
}
void topo(int a[][10],int n)
{
    int i,j,c = 0;
	int temp[10][10];
    
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			temp[i][j] = a[i][j];

    if(!count(check,n))
    {
		for(i=0;i<n;i++)
		{
			c = 0;
			if(check[i]!=1)
			{
			for(j=0;j<n;j++)
				c += a[j][i];
			if(c==0)
				break;
			}
		}



		if(i!=n)
		{

			printf("%d ",i+1);
			check[i] = 1;
			
			for(j=0;j<n;j++)
				temp[i][j] = 0;
			
			topo(temp,n);
		}
    }
}
void main()
{
    int mat[10][10]={0};
    int n;
    system("cls");

    printf("Enter no of nodes ");
    scanf("%d",&n);
    printf("The graph must be directed\n");

    admat(mat);

    printf("The adjacency matrix of the graph is\n");
    primat(mat,n,n);

    printf("The topological sort is ");
    topo(mat,n);
    
	getch();
}



/*
OUTPUT :



Enter no of nodes 7
The graph must be directed

Want to enter an edge(0:no 1:yes) 1
Enter node number from & to 1 3

Want to enter an edge(0:no 1:yes) 1
Enter node number from & to 2 5

Want to enter an edge(0:no 1:yes) 1
Enter node number from & to 3 7

Want to enter an edge(0:no 1:yes) 1
Enter node number from & to 1 7

Want to enter an edge(0:no 1:yes) 1
Enter node number from & to 1 5

Want to enter an edge(0:no 1:yes) 0
The adjacency matrix of the graph is
        1       2       3       4       5       6       7
1       0       0       1       0       1       0       1
2       0       0       0       0       1       0       0
3       0       0       0       0       0       0       1
4       0       0       0       0       0       0       0
5       0       0       0       0       0       0       0
6       0       0       0       0       0       0       0
7       0       0       0       0       0       0       0
The topological sort is 1 2 3 4 5 6 7
*/