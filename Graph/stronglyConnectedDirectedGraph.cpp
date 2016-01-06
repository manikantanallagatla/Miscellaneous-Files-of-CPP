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
    int DFSUtil(int s,bool visited[]);
    bool isSC();
    Graph *reverse();
};
Graph:: Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}
void Graph:: addEdge(int v,int w){
    adj[v].push_back(w);
}
int sum = 0;
int Graph:: DFSUtil(int s,bool visited[]){
    visited[s] = 1;
    sum++;
    cout<<s<<" ";
    list<int>::iterator it;
    for(it = adj[s].begin();it!=adj[s].end();it++){
        if(visited[*it] == 0){
            DFSUtil(*it,visited);
        }
    }
    return sum;
}
Graph *Graph::reverse(){
    Graph g2(this->V);
    list<int>::iterator it;
    for(int i = 0;i<V;i++){
        for(it = adj[i].begin();it!=adj[i].end();it++){
            g2.addEdge(*it,i);
        }
    }
    return &g2;
}
void Graph:: DFS(int s){
    bool visited[V];
    memset(visited,0,sizeof(visited));
    DFSUtil(s,visited);
}
bool Graph::isSC(){
    bool visited[V];
    memset(visited,0,sizeof(visited));
    sum = 0;
    if(DFSUtil(0,visited) == V){

        Graph *g2 = reverse();//reverseGraph();
        memset(visited,0,sizeof(visited));
        sum = 0;
        if(g2->DFSUtil(0,visited) == V){
            return 1;
        }
        return 0;
    }else{
        return 0;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    // Create graphs given in the above diagrams
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 0);
    g1.addEdge(2, 4);
    g1.addEdge(4, 2);
    g1.isSC()? cout << "Yes\n" : cout << "No\n";

    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.isSC()? cout << "Yes\n" : cout << "No\n";
    return 0;
}

