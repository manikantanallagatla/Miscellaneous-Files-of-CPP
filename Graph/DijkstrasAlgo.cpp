#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
#define V 9
int minDistance(int dist[],bool sptSet[]){
    int minimum = INT_MAX;
    int minIndex;
    for(int i = 0;i<V;i++){
        if(sptSet[i] == 0 and minimum>=dist[i]){
            minimum = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}
int printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}
void dijkstra(int graph[V][V],int src){
    int dist[V];
    bool sptset[V];
    for(int i= 0;i<V;i++){
        dist[i] = INT_MAX;
        sptset[i] = 0;
    }
    dist[src] = 0;
    //sptset[src] = 1;
    for(int i = 0;i<V-1;i++){
        int u = minDistance(dist,sptset);
        cout<<u<<endl;
        sptset[u] = 1;
        for(int j = 0;j<V;j++){
            if(sptset[j] ==0 and graph[u][j]!=0 and dist[u]!=INT_MAX and dist[u]+graph[u][j]<dist[j]){
                dist[j] = dist[u]+graph[u][j];
            }
        }
    }
    printSolution(dist,V);
}
int main(){
    ios_base::sync_with_stdio(false);
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    dijkstra(graph, 0);
    return 0;
}

