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
    void BFS(int s);
};
Graph:: Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}
void Graph:: addEdge(int v,int w){
    adj[v].push_back(w);
}
void Graph:: BFS(int s){
    bool visited[V];
    memset(visited,0,sizeof(visited));
    list<int> queue;
    visited[s] = 1;
    queue.push_back(s);
    list<int> ::iterator it;
    while(queue.empty() == false){
        int x = queue.front();
        cout<<x<<" ";
        queue.pop_front();
        for(it = adj[x].begin();it!=adj[x].end();it++){
            if(visited[*it] == false){
                visited[*it] = true;
                queue.push_back(*it);
            }
        }
    }
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
    g.BFS(2);
    return 0;
}
