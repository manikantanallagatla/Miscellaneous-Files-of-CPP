#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
struct adjListNode{
    int dest;
    struct adjListNode *next;
};
struct adjList{
    adjListNode *head;
};
struct Graph{
    int V;
    adjList *array;
};
adjListNode *newAdjListNode(int dest){
    adjListNode *temp = new adjListNode;
    temp->dest = dest;
    temp->next = NULL;
    return temp;
}
Graph *creategraph(int V){
    Graph *graph = new Graph;
    graph->V = V;
    graph->array = new adjList[V];
    for(int i = 0;i<V;i++){
        graph->array[i].head = NULL;
    }
    return graph;
}
void addEdge(Graph *graph,int src,int dest){
    adjListNode *newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
void printGraph(Graph *graph){
    for(int v = 0;v<graph->V;v++){
        adjListNode *crawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while(crawl){
            printf("-> %d", crawl->dest);
            crawl = crawl->next;
        }
        printf("\n");
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int V = 5;
    struct Graph* graph = creategraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // print the adjacency list representation of the above graph
    printGraph(graph);
    return 0;
}
