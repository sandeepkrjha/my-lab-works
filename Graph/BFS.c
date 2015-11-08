#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NIL 0
#define MAX_SIZE 100
#define INFINITE 1000000

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
typedef struct Queue{
	int A[MAX_SIZE];
	int tail;
	int head;
	int length;
}Queue;

void enqueue(Queue* Q,int s)
{
	Q->A[Q->tail]=s;
	if(Q->tail==Q->length)
	{
		Q->tail=1;
	}
	else
		++Q->tail;
}
int dequeue(Queue* Q)
{
	int x=Q->A[Q->head];
	if(Q->head==Q->length)
	{
		Q->head=1;
	}
	else
		++Q->head;
	return x;
}

void BFS(Graph* G, int s)
{
	int i;
	for(i=1;i<=G->V;++i)
	{
		G->array[i].color=WHITE;
		G->array[i].p=NIL;
		G->array[i].d=INFINITE;

	}

	G->array[s].color=GRAY;
	G->array[s].d=0;
	G->array[s].p=NIL;
	Queue *Q;
	Q=(Queue*)malloc(sizeof(Queue));
	Q->length=MAX_SIZE ;
	Q->head=Q->tail=0;
	enqueue(Q,s);

	int u,v;
	while(Q->head!=Q->tail)
	{
		u=dequeue(Q);
		adjNode* traver;
		traver= G->array[u].head;
		while(traver!=NULL)
		{

			if(G->array[traver->data].color==WHITE)

			{
				v=traver->data;
				G->array[v].color=GRAY;
				G->array[v].d=G->array[u].d + 1;
				G->array[v].p=u;
				enqueue(Q,v);

			}
			traver=traver->next;

		}
		G->array[u].color=BLACK;

	}
	 

}


void printGraph(Graph* G)
{
	int i;
	

	for(i=1;i<=G->V;++i)
	{
		
		printf("node: %d , parent: %d , distance: %d , color: %d \n",i,G->array[i].p,G->array[i].d,G->array[i].color);

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
	int s;

	printf("enter the source node\n");
	scanf("%d",&s);

	BFS(G,s);
	printGraph(G);



}

