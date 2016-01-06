// Program for Floyd Warshall Algorithm
#include<stdio.h>
 
// Number of vertices in the graph
#define V 4
 
/* Define Infinite as a large enough value. This value will be used
  for vertices not connected to each other */
#define INF 99999
 #include<iostream>
using namespace std;
void printSolution(int dist[][V]){
	for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
void floydWarshell(int graph[][V]){
	int dist[V][V];int i,j,k;
	for(int i = 0;i<V;i++){
		for(int j = 0;j<V;j++){
			dist[i][j] = graph[i][j];
		}
	}
	for(int k = 0;k<V;k++){
		for(int i = 0;i<V;i++){
			for(int j = 0;j<V;j++){
				if(dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j] = dist[i][k]+dist[k][j];
				}
			}
		}
	}
	printSolution(dist);
}
int main(){
	int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
 
    // Print the solution
    floydWarshell(graph);
    return 0;
}
