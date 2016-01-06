

// Program to print Vertex Cover of a given undirected graph
#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;

// This class represents a undirected graph using adjacency list
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;  // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void printVertexCover();  // prints vertex cover
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Since the graph is undirected
}

// The function to print vertex cover
void Graph::printVertexCover()
{
    vector<int> result;
    list<int> ::iterator it;
    bool visited[V];
    memset(visited,0,sizeof(visited));
    for(int u =0;u<V;u++){
        if(visited[u] == 0){
                cout<<"Adding this as u "<<u<<endl;
                result.push_back(u);
                visited[u] = 1;
            it = adj[u].begin();bool added = 0;
            while(it!=adj[u].end()){

                if(visited[*it] == 0){
                        cout<<"Making this false! "<<*it<<endl;
                    if(added == 0){
                            cout<<"Adding to result as v "<<*it<<endl;
                        result.push_back(*it);
                        added = 1;
                        }
                        visited[*it] = 1;
                    }
                it++;
            }
        }
    }
    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<" ";
    }cout<<endl;
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.printVertexCover();

    return 0;
}
