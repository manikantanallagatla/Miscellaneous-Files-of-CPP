#include <iostream>
#include<list>
using namespace std;

class Graph{
    int v;
    list<int> *adj;
    public:
    Graph(int v);
    void addEdge(int u,int v);
    void DFS(int s,bool visited[]);
};

Graph::Graph(int v){
    this->v = v;
    adj = new list<int> [v];
}
void Graph::addEdge(int u,int v){
    adj[u].push_back(v);
}
void Graph::DFS(int s, bool visited[]){
    visited[s] = true;
    //stack.push_back(s);
    list<int>::iterator it; 
        cout<<s<<" ";
        for(it = adj[s].begin();it!=adj[s].end();it++){
            if(visited[*it] == false){
                DFS(*it,visited);
            }
        }
}
int main() {
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    bool visited[4];
    for(int i = 0;i<4;i++){
        visited[i] = false;
    }
    g.DFS(2,visited);
	return 0;
}

