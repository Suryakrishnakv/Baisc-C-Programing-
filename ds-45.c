#include <stdio.h>
#define V 4
void printGraph(int graph[V][V]) 
{ 
	int i, j;
	for (i = 0; i < V; i++) 
	{ 
		for (j = 0; j < V; j++) 
		{ 
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}
void addEdge(int graph[V][V], int u, int v) 
{ 
	graph[u][v] = 1;
	graph[v][u] = 1;
}
int main() 
{
	int graph[V][V] = {0};
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 3);
	addEdge(graph, 1, 2);
	addEdge(graph, 2, 3);
	printf("Adjacency Matrix of the Graph:\n"); 
	printGraph(graph);
	return 0;
}

