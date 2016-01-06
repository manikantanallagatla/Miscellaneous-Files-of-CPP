#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define isBC isConnected
using namespace std;
class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v,int w);
    void DFS(int s);
    int DFSUtil(int s,bool visited[]);
    bool isConnected();
};
Graph:: Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}
void Graph:: addEdge(int v,int w){
    adj[v].push_back(w);
}
int sum;
int Graph:: DFSUtil(int s,bool visited[]){
    sum++;
    visited[s] = 1;
    cout<<s<<" ";
    list<int>::iterator it;
    for(it = adj[s].begin();it!=adj[s].end();it++){
        if(visited[*it] == 0){
            DFSUtil(*it,visited);
        }
    }
    return sum;
}
void Graph:: DFS(int s){
    bool visited[V];
    memset(visited,0,sizeof(visited));
    DFSUtil(s,visited);
}
bool Graph::isConnected(){
    sum = 0;
    bool visited[V];
    memset(visited,0,sizeof(visited));
    if(DFSUtil(0,visited) == V){
        return 1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    // Create graphs given in above diagrams
    Graph g1(2);
    g1.addEdge(0, 1);
    g1.isBC()? cout << "Yes\n" : cout << "No\n";

    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(2, 4);
    g2.isBC()? cout << "Yes\n" : cout << "No\n";

    Graph g3(3);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.isBC()? cout << "Yes\n" : cout << "No\n";

    Graph g4(5);
    g4.addEdge(1, 0);
    g4.addEdge(0, 2);
    g4.addEdge(2, 1);
    g4.addEdge(0, 3);
    g4.addEdge(3, 4);
    g4.isBC()? cout << "Yes\n" : cout << "No\n";

    Graph g5(3);
    g5.addEdge(0, 1);
    g5.addEdge(1, 2);
    g5.addEdge(2, 0);
    g5.isBC()? cout << "Yes\n" : cout << "No\n";

    return 0;
}
