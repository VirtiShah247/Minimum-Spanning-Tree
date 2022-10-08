#include<stdio.h>
#include<stdlib.h>
 
#define infinity 9999
#define MAX 30
 
int G[MAX][MAX],spanning[MAX][MAX],n1;

struct edge
{
	int u,v,w;
}edge;
 
struct edgelist
{
	struct edge data[MAX];
	int n;
}edgelist;
 
struct edgelist elist;
int n;
struct edgelist spanlist;
 
int prims()
{
	int cost[MAX][MAX];
	int u,v,min_distance,distance[MAX],from[MAX];
	int visited[MAX],no_of_edges,i,min_cost,j;
	//create cost[][] matrix,spanning[][]
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n1;j++)
		{
			if(G[i][j]==0)
			{
				cost[i][j]=infinity;	
			}
			
			else
			{
				cost[i][j]=G[i][j];	
			}
			
			spanning[i][j]=0;
		}	
	}
	
	//initialise visited[],distance[] and from[]
	distance[0]=0;
	visited[0]=1;
	for(i=1;i<n1;i++)
	{
		distance[i]=cost[0][i];
		from[i]=0;
		visited[i]=0;
	}
	min_cost=0; //cost of spanning tree
	no_of_edges=n1-1; //no. of edges to be added
	while(no_of_edges>0)
	{
		//find the vertex at minimum distance from the tree
		min_distance=infinity;
		for(i=1;i<n1;i++)
		{
			if(visited[i]==0&&distance[i]<min_distance)
			{
				v=i;
				min_distance=distance[i];
			}
		}
			
		u=from[v];
		//insert the edge in spanning tree
		spanning[u][v]=distance[v];
		spanning[v][u]=distance[v];
		no_of_edges--;
		visited[v]=1;
		//updated the distance[] array
		for(i=1;i<n1;i++)
		{
			if(visited[i]==0&&cost[i][v]<distance[i])
			{
				distance[i]=cost[i][v];
				from[i]=v;
			}	
		}
		min_cost=min_cost+cost[u][v];
	}
	return(min_cost);
}
void prim_algo()
{
	int i,j,total_cost;
	printf("Enter no. of vertices:");
	scanf("%d",&n1);
	printf("\nEnter the adjacency matrix:\n");
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n1;j++)
		{
			scanf("%d",&G[i][j]);	
		}
	
	}
	
	total_cost=prims();
	printf("\nspanning tree matrix:\n");
	for(i=0;i<n1;i++)
	{
		printf("\n");
		for(j=0;j<n1;j++)
		{
			printf("%d\t",spanning[i][j]);	
		}
		
	}
	printf("\n\nTotal cost of spanning tree=%d",total_cost);

}

void sort()
{
	int i,j;
	struct edge temp;
	for(i=1;i<elist.n;i++)
	{
		for(j=0;j<elist.n-1;j++)
		{
			if(elist.data[j].w>elist.data[j+1].w)
			{
				temp=elist.data[j];
				elist.data[j]=elist.data[j+1];
				elist.data[j+1]=temp;
			}	
		}	
	}
}

int find(int belongs[],int vertexno)
{
	return(belongs[vertexno]);
}
	
void union1(int belongs[],int c1,int c2)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(belongs[i]==c2)
		{
			belongs[i]=c1;
		}
		
	}
	
}


void kruskal()
{
	int belongs[MAX],i,j,cno1,cno2;
	elist.n=0;
	 
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(G[i][j]!=0)
			{
				elist.data[elist.n].u=i;
				elist.data[elist.n].v=j;
				elist.data[elist.n].w=G[i][j];
				elist.n++;
			}
		}	
	}
	sort();
	for(i=0;i<n;i++)
	{
		belongs[i]=i;
	}
	
	spanlist.n=0;
	for(i=0;i<elist.n;i++)
	{
		cno1=find(belongs,elist.data[i].u);
		cno2=find(belongs,elist.data[i].v);
		if(cno1!=cno2)
		{
			//printf("%d\t",elist.data[i]);
			spanlist.data[spanlist.n]=elist.data[i];
			//printf("%d\n",spanlist.data[spanlist.n]);
			spanlist.n=spanlist.n+1;
			union1(belongs,cno1,cno2);
		}
	}
}



void print()
{
	int i,cost=0;
	printf("\nu\tv\tw");
	for(i=0;i<spanlist.n;i++)
	{
		printf("\n%d\t%d\t%d",spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].w);
		cost=cost+spanlist.data[i].w;
	}
	 
	printf("\n\nCost of the spanning tree=%d",cost);
}
void kruskal_algo()
{
	int i,j,total_cost;
	printf("\nEnter number of vertices:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&G[i][j]);
		}

	}

	kruskal();
	print();
}

 
int main()
{
	int ch;
	int i,j,total_cost;
	do
	{
		system("cls");
		printf("\n1.Prim's Algorithm\n2.Kruskal Algorithm\n3.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				prim_algo();
				printf("\nPlease!! press any key to continue!!");
				getch();
				break;
			case 2:
				kruskal_algo();
				printf("\nPlease!! press any key to continue!!");
				getch();
				break;
			case 3:
				exit(0);
			default:
				printf("invalid chocie");
				break;
		}
		
	}while(ch!=4);
}
	
