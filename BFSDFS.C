/*
	Program Purpose : To Perform BFS and DFS on the Graphs. 
	Coded by : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV	
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int weight,direct;
int check[10];
int queue[10],rear = -1;

int count(int x[],int n)
{
	int i,c=0;
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
void admat (int a[][10])
{
    int i,j,e,w;
    printf("\nWant to enter an edge(0:no;1:yes) : ");
    scanf("%d",&e);

    while(e)
    {
		printf("Enter node number from & to : ");
		scanf("%d%d",&i,&j);
		
		if(weight)
		{
			printf("Enter weight of edge : ");
			scanf("%d",&w);
		}
		else w=1;
			a[--i][--j] = w;
		
		if(!direct)
			a[j][i]=w;
		printf("\nWant to enter an edge(0:no;1:yes) : ");
		scanf("%d",&e);
    }
}

void dfs(int a[][10],int n,int v)
{
    int i;
    printf("%d-",v+1);
    check[v] = 1;
    
	for(i=0;i<n;i++)
    {
		if(a[v][i]!=0 && check[i]!=1)
			dfs(a,n,i);
    }
}

void bfs(int a[][10],int n,int v)
{
    int i,j;
    if(!count(check,10))
    {
		for(i=0;i<n;i++)
			if(a[v][i]!=0 && check[i]!=1)
			{
				printf("%d-",i+1);
				check[i]=1;
				queue[++rear]=i;
			}
		j = queue[0];
	
		for(i=0;i<rear;i++)
			queue[i]=queue[i+1];
	
		queue[rear] = 0;
		rear = rear - 1;
		bfs(a,n,j);
    }
}

void main()
{
    int mat[10][10] = {0};
    int i,n,ch,v;
    system("cls");

    printf("Enter no of nodes\n");
    scanf("%d",&n);

    printf("Is Graph directed ? (0:no/1:yes) : ");
    scanf("%d",&direct);
    printf("Is Graph weighted ? (0:no/1:yes) : ");
    scanf("%d",&weight);
    
	admat(mat);
    
	printf("The adjacency matrix of the graph : \n");
    primat(mat,n,n);
	
	while(1)
    {
		printf("Transitive closure\n");

		printf("\n1: Depth First Search\n");
		printf("2: Breadth First Search\n");
		printf("3: Exit\n");
		printf("Enter your choice ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				for(i=0;i<n;i++)
					check[i]=0;
				printf("Enter starting node : ");
				scanf("%d",&v);
				dfs(mat,n,v-1) ;
				break;

			case 2:
				for(i=0;i<n;i++)
					check[i]=0;
				printf("Enter starting node : ");
				scanf("%d",&v);
				printf("%d-",v);
				check[v-1]=1;
				bfs(mat,n,v-1) ;
				break;

			case 3:
				exit(0);
				break;
			
			default:
				printf("Invalid choice\n");
		}
	
		getch();
	}
}


/*
Enter no of nodes : 4
Is Graph directed ? (0:no/1:yes) : 0
Is Graph weighted ? (0:no/1:yes) : 0

Want to enter an edge(0:no;1:yes) : 1
Enter node number from & to : 1 3

Want to enter an edge(0:no;1:yes) : 1
Enter node number from & to : 1 2

Want to enter an edge(0:no;1:yes) : 1
Enter node number from & to : 3 4

Want to enter an edge(0:no;1:yes) : 1
Enter node number from & to : 2 4

Want to enter an edge(0:no;1:yes) : 0
The adjacency matrix of the graph :
        1       2       3       4
1       0       1       1       0
2       1       0       0       1
3       1       0       0       1
4       0       1       1       0
Transitive closure

1: Depth First Search
2: Breadth First Search
3: Exit
Enter your choice 1
Enter starting node : 2
2-1-3-4-Transitive closure

1: Depth First Search
2: Breadth First Search
3: Exit
Enter your choice 2
Enter starting node : 3
3-1-4-2-3
Press any key to continue
*/