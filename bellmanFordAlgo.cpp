#include <iostream>
#include<string>
#include<stdlib.h>
#include<limits.h>
using namespace std;
struct Edge{
    int src,dest,weight;
};
struct graph{
    int v,e;
    Edge *edges;
};
graph * createGraph(int v,int e){
    struct graph * g = (struct graph *)malloc(sizeof(struct graph));
    g->v = v;
    g->e = e;
    g->edges = (Edge *)malloc(sizeof(Edge));
    return g;
}
void printArr(int dist[], int n){
    for(int i = 0;i<n;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
}
void BellmanFord(graph * g,int src){
    int v = g->v;
    int e = g->e;
    int dist[v];
    for(int i = 0;i<v;i++){
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    for(int i = 0;i<v;i++){
        for(int j = 0;j<e;j++){
            int u = g->edges[j].src;
            int v = g->edges[j].dest;
            int weight = g->edges[j].weight;
            if(dist[u]!=INT_MAX and dist[u]+weight <dist[v]){
                dist[v] = dist[u]+weight;
            }
        }
    }
    for(int j = 0;j<e;j++){
            int u = g->edges[j].src;
            int v = g->edges[j].dest;
            int weight = g->edges[j].weight;
            if(dist[u]!=INT_MAX and dist[u]+weight <dist[v]){
                cout<<"Graph contains negative weight cycle"<<endl;
            }
        }
        printArr(dist,v);
}
int main() {
    /* Let us create the graph given in above example */
    int V = 5;  // Number of vertices in graph
    int E = 8;  // Number of edges in graph
    struct graph* graph1 = createGraph(V, E);
 
    // add edge 0-1 (or A-B in above figure)
    graph1->edges[0].src = 0;
    graph1->edges[0].dest = 1;
    graph1->edges[0].weight = -1;
 
    // add edge 0-2 (or A-C in above figure)
    graph1->edges[1].src = 0;
    graph1->edges[1].dest = 2;
    graph1->edges[1].weight = 4;
 
    // add edge 1-2 (or B-C in above figure)
    graph1->edges[2].src = 1;
    graph1->edges[2].dest = 2;
    graph1->edges[2].weight = 3;
 
    // add edge 1-3 (or B-D in above figure)
    graph1->edges[3].src = 1;
    graph1->edges[3].dest = 3;
    graph1->edges[3].weight = 2;
 
    // add edge 1-4 (or A-E in above figure)
    graph1->edges[4].src = 1;
    graph1->edges[4].dest = 4;
    graph1->edges[4].weight = 2;
 
    // add edge 3-2 (or D-C in above figure)
    graph1->edges[5].src = 3;
    graph1->edges[5].dest = 2;
    graph1->edges[5].weight = 5;
 
    // add edge 3-1 (or D-B in above figure)
    graph1->edges[6].src = 3;
    graph1->edges[6].dest = 1;
    graph1->edges[6].weight = 1;
 
    // add edge 4-3 (or E-D in above figure)
    graph1->edges[7].src = 4;
    graph1->edges[7].dest = 3;
    graph1->edges[7].weight = -3;
 
    BellmanFord(graph1, 0);
	return 0;
}

