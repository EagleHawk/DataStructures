/*
	Program Purpose : To Perform KRUSKAL Algorithm.
	Coded by : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV	
*/

#include<stdio.h>
#include<conio.h>

#define INF 0

int weight;

void primat(int a[][10],int n,int m)
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
    int i,j,e,w;
    
	printf("\nWant to enter an edge(0:no 1:yes) ");
    scanf("%d",&e);
    
	while(e)
    {
		printf("Enter node number from & to ");
		scanf("%d%d",&i,&j);
		if(weight)
		{
			printf("Enter weight of edge ");
			scanf("%d",&w);
		}
		else 
			w=1;
		
		a[--i][--j] = w;
		a[j][i] = w;
		printf("\nWant to enter an edge(0:no 1:yes) ");
		scanf("%d",&e);
    }
}

void kruskal(int weight[][10],int n)
{
    int parent[10]={0};
    
	typedef struct {int v1,v2,wt;} edge;
    
	edge e[15] = {0},temp;
    int i,j,k,size=0,nodecount=1,swap=1;
    
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(weight[i][j]!=INF)
			{
				e[size].v1 = i;
				e[size].v2 = j;
				e[size].wt = weight[i][j];
				size++;
			}
    
	for(i=0;swap;i++)
    {
		swap = 0;
		for(j=1;j<size-i;j++)
			if(e[j].wt<e[j-1].wt)
			{
				temp = e[j];
				e[j] = e[j-1];
				e[j-1] = temp;
				swap = 1;
			}
    }
    
	for(k=0;nodecount<n && k!=size;k++)
    {
		i=e[k].v1+1;
		j=e[k].v2+1;

		while(parent[i-1]>0)
			i=parent[i-1];
			
		while(parent[j-1]>0)
			j = parent[j-1];
				
		if(i!=j)
		{
			parent[j-1]=i;
			printf("%d-%d %d\t",e[k].v1+1,e[k].v2+1,e[k].wt);
			nodecount++;
		}
    }
}

void main()
{
    int mat[10][10]={INF};
    int i,n,ch,v;
    system("cls");
 
	printf("Enter no of nodes ");
    scanf("%d",&n);
    
	printf("The graph has to be undirected\n");
    printf("Is graph weighted(0:no 1:yes) ");
    scanf("%d",&weight);
    
	admat(mat);
    
	printf("The adjacency matrix of the graph is\n");
    primat(mat,n,n);
    
	printf("The Edges with their weights are:\n");
    kruskal(mat,n);
    
	getch();
}



/*
OUTPUT :



Enter no of nodes 7
The graph has to be undirected
Is graph weighted(0:no 1:yes) 1

Want to enter an edge(0:no 1:yes) 1
Enter node number from & to 1 5
Enter weight of edge 2

Want to enter an edge(0:no 1:yes) 1
Enter node number from & to 2 6
Enter weight of edge 2

Want to enter an edge(0:no 1:yes) 1
Enter node number from & to 2 4
Enter weight of edge 12

Want to enter an edge(0:no 1:yes) 1
Enter node number from & to 2 5
Enter weight of edge 21

Want to enter an edge(0:no 1:yes) 1
Enter node number from & to 1 7
Enter weight of edge 23

Want to enter an edge(0:no 1:yes) 1
Enter node number from & to 4 2
Enter weight of edge 5

Want to enter an edge(0:no 1:yes) 0
The adjacency matrix of the graph is
        1       2       3       4       5       6       7
1       0       0       0       0       2       0       23
2       0       0       0       5       21      2       0
3       0       0       0       0       0       0       0
4       0       5       0       0       0       0       0
5       2       21      0       0       0       0       0
6       0       2       0       0       0       0       0
7       23      0       0       0       0       0       0
The Edges with their weights are:
1-5 2   2-6 2   2-4 5   2-5 21  1-7 23
*/