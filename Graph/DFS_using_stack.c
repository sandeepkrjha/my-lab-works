#define MAX_SIZE 100
#define NIL 0

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
	int visited;
	int DFN;
	int p;
	
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

typedef struct stack{
	int A[MAX_SIZE];
	int top;

}stack;

void push(stack *s,int a)
{
	s->top=s->top + 1;
	s->A[s->top]=a;

}

int pop(stack *s)
{
	if(s->top==(-1))
		printf("error: Underflow\n");
	else
		s->top=s->top-1;
	return s->A[s->top+1];


}

void DFS(Graph* G)
{
	stack* s;
	s=(stack*)malloc(sizeof(stack));
	s->top= -1;
	int d;
	int i;
	for(i=1;i<=G->V;++i)
	{
		G->array[i].visited=0;
		G->array[i].DFN=0;
		G->array[i].p=NIL;
	}
	d=1;
	push(s,1);
	G->array[1].visited=1;
	G->array[1].DFN=d++;
	G->array[i].p=NIL;
	int u,v;
	adjNode* traver;
	while(s->top!=-1)
	{
		u=pop(s);
		traver=G->array[u].head;
		while(traver!=NULL)
		{
			v=traver->data;
			if(G->array[traver->data].visited==0)
			{
				G->array[v].visited=1;
				G->array[v].DFN=d++;
				G->array[v].p=u;
				push(s,v);

			}

			traver=traver->next;

		}

	}

}





void printGraph(Graph* G)
{
	int i;
	for(i=1;i<=G->V;++i)
	{
		printf("node: %d ,visited: %d, p: %d , DFN: %d\n",i,G->array[i].visited,G->array[i].p,G->array[i].DFN);

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

