#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NIL 0
#define MAX_SIZE 100

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int time;


typedef struct adjNode{
	int data;
	struct adjNode *next;
}adjNode;
typedef struct adjList
{
	struct adjNode *head;
	int color;
	int p;
	int d;
	int f;
	
}adjList;

typedef struct Graph{
	int V;
	adjList *array;
}Graph;
adjNode *createNode(int node)
{
	adjNode *newNode;
	newNode=(adjNode*)malloc(sizeof(adjNode));
	newNode->data=node;
	newNode->next=NULL;
	return newNode;
}
//function to create a graph and initialize the each list to NULL
Graph *createGraph(int n)//n is number of vertices
{
	Graph* G;
	G=(Graph*)malloc(sizeof(Graph));
	G->V=n;
	G->array=(adjList*)malloc((n+1)*sizeof(adjList));
	int i;
	for(i=1;i<=n;++i)
	{
		G->array[i].head=NULL;
	}
	return G;
}
//adding edge in undirectional graph
void addEdge(Graph* G,int node1,int node2)
{
	adjNode *newNode1=createNode(node1);//adding node2 in list of node1
	newNode1->next=G->array[node2].head;
	G->array[node2].head=newNode1;
	adjNode* newNode2=createNode(node2);//adding node1 in list of node2
	newNode2->next=G->array[node1].head;
	G->array[node1].head=newNode2;


}
void DFS_visit(Graph* G, int u)
{
	adjNode* traver;
	traver=G->array[u].head;
	time= time+ 1;
	G->array[u].color=GRAY;
	G->array[u].d=time;
	
	int v;
	while(traver!=NULL)
	{
		v=traver->data;
		if(G->array[v].color==WHITE)
		{
			G->array[v].p=u;
			DFS_visit(G,v);
		}
		traver=traver->next;
	}
	G->array[u].color=BLACK;
	time= time +1;
	G->array[u].f=time;



}

void DFS(Graph *G)
{
	int i;
	for(i=1;i<=G->V;++i)
	{
		G->array[i].color=WHITE;
		G->array[i].p=NIL;
	}
	time=0;
	for(i=1;i<=G->V;++i)
	{
		if(G->array[i].color==WHITE)
			DFS_visit(G,i);
	}
}

void printGraph(Graph* G)
{
	int i;
	for(i=1;i<=G->V;++i)
	{
		printf("node: %d , start_time: %d , finish_time: %d , parent: %d , color: %d\n",i,G->array[i].d,G->array[i].f,G->array[i].p,G->array[i].color);
	}
}



int main()
{
	Graph *G;
	int V,node1,node2;
	printf("enter the number of vertices\n");
	scanf("%d",&V);
	G=createGraph(V);
	printf("enter the nodes which shares edge with each other:\n");
	printf("enter 0, 0 to end the graph\n");
	while(true)
	{
		scanf("%d%d",&node1,&node2);
		if(node1==0 || node2==0)
		{
			break;
		}
		else
			addEdge(G,node1,node2);
	}
	DFS(G);
	printGraph(G);


}

