#include <iostream>
#include<list>
using namespace std;

class Graph{
    int v;
    list<int> *adj;
    public:
    Graph(int v);
    void addEdge(int u,int v);
    void BFS(int s);
};

Graph::Graph(int v){
    this->v = v;
    adj = new list<int> [v];
}
void Graph::addEdge(int u,int v){
    adj[u].push_back(v);
}
void Graph::BFS(int s){
    bool *visited = new bool[v];
    for(int i = 0;i<v;i++){
        visited[i] = false;
    }
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator it;
    while(!queue.empty()){
        s = queue.front();
        queue.pop_front();
        cout<<s<<" ";
        for(it = adj[s].begin();it!=adj[s].end();it++){
            if(visited[*it] == false){
                visited[*it] = true;
                queue.push_back(*it);
            }
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
    g.BFS(2);
	return 0;
}

