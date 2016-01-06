#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v,int w);
    void DFS(int s);
    void DFSUtil(int s,bool visited[]);
};
Graph:: Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}
void Graph:: addEdge(int v,int w){
    adj[v].push_back(w);
}
void Graph:: DFSUtil(int s,bool visited[]){
    visited[s] = 1;
    cout<<s<<" ";
    list<int>::iterator it;
    for(it = adj[s].begin();it!=adj[s].end();it++){
        if(visited[*it] == 0){
            DFSUtil(*it,visited);
        }
    }
}
void Graph:: DFS(int s){
    bool visited[V];
    memset(visited,0,sizeof(visited));
    DFSUtil(s,visited);
}
int main(){
    ios_base::sync_with_stdio(false);
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
    return 0;
}
