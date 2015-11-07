#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	int a[100][100];
	int i,j,node1,node2;
	int V,E;
	printf("enter the number of vertices(nodes) and edges respectively\n");
	scanf("%d%d",&V,&E);
	//initialisations of matrix
	for(i=1;i<=V;++i)
	{
		for(j=1;j<=V;++j)
		{
			a[i][j]=0;
		}
	}
	printf("enter the vertices which share an edge with each other\n");
	printf("enter 0,0 to end the graph\n");
	while(true)
	{
		scanf("%d%d",&node1,&node2);
		if(node1==0 || node2==0)
			break;
		else
			a[node1][node2]=1;
			a[node2][node1]=1;
	}
	//printing the marix
	for(i=1;i<=V;++i)
	{
		printf(" %d",i);
	}
	printf("\n");
	for(i=1;i<=V;++i)
	{
		printf("%d ",i );

		for(j=1;j<=V;++j)
		{
			printf("%d ",a[i][j]);

		}
		printf("\n");

	}
	return 0;

}