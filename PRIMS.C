/*
	Program Purpose : To Perform Prim's Algorithm for the minimum cost in 
					  the Graph Path
	Coded by : Devendra Walanj
	Subject : Analysis of Algorithms
	Semister : IV					  
*/

#include<stdio.h>
#include<conio.h>
int check[10];

void admat (int a[][10])
{
    int i,j,e,w;
    printf("Want to enter an edge (0:no;1:yes) : ");
    scanf("%d",&e);
    
	while(e)
    {
		printf("Enter node number from & to : ");
		scanf("%d%d",&i,&j);
		
		printf("Enter weight of edge : ");
		scanf("%d",&w);
		
		a[i][j] = w;
		a[j][i] = w;
		
		printf("\nWant to enter an edge (0:no;1:yes) : ");
		scanf("%d",&e);
    }
}

void primat (int a[][10],int n)
{
    int i,j;
    
	for(i=1;i<=n;i++)
		printf("\t%d",i);
    
	printf("\n");

    for(i=1;i<=n;i++)
    {
		printf("%d",i+1);
		for(j=1;j<=n;j++)
			printf("\t%d",a[i][j]);
		printf("\n");
    }
}

void prims(int a[][10],int v)
{
	int d[10],p[10]={0},visit[10]={0};
	int curr,sum = 0,k,n,i,min;
	curr = 1;
	
	for(i=0;i<10;i++)
		d[i] = 32767;
	
	d[curr] = 0;
	
	visit[curr] = 1;
	n = 1;
	
	while(n!=v)
	{
		for(k=1;k<=v;k++)
		{
			if(a[curr][k]!=0 && visit[k]==0)
				if(a[curr][k]<d[k])
				{
					d[k] = a[curr][k];
					p[k] = curr;
				}
		}

		min = 32767;
		
		for(i=1;i<=v;i++)
		{
			if(visit[i]==0)
			if(d[i]<min)
			{
				min = d[i];
				curr = i;
			}
		}
		
		n = n + 1;
		visit[curr] = 1;
	}

	printf("Minimum cost is : ");
	for(i=1;i<=v;i++)
		sum = sum + d[i];
	printf("%d\n",sum);
}

void main()
{
    int mat[10][10]={0};
    int i,n,ch,v,m;
	system("cls");
    
	printf("Enter total No of Nodes : ");
    scanf("%d",&n);
    
	admat(mat);
    prims(mat,n);
    
	getch();
}


/*
OUTPUT : 

Enter total No of Nodes : 4
Want to enter an edge (0:no;1:yes) : 1
Enter node number from & to : 2 4
Enter weight of edge : 2

Want to enter an edge (0:no;1:yes) : 1
Enter node number from & to : 1 3
Enter weight of edge : 5

Want to enter an edge (0:no;1:yes) : 1
Enter node number from & to : 4 3
Enter weight of edge : 6

Want to enter an edge (0:no;1:yes) : 0
Minimum cost is : 13
Press any key to continue
*/