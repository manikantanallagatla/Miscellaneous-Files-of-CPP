#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
class Graph{
    int V;
    list<int> *adj;
    void topologicalSortUtil(int v,bool visited[],stack<int> &Stack);
public:
    Graph(int V);
    void addEdge(int v,int w);
    void topologicalSort();

};
Graph:: Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}
void Graph:: addEdge(int v,int w){
    adj[v].push_back(w);
}
void Graph::topologicalSortUtil(int v,bool visited[],stack<int> &Stack){
    visited[v] = 1;
    list<int>::iterator it;
    for(it = adj[v].begin();it!=adj[v].end();it++){
        if(visited[*it] == false){
            topologicalSortUtil(*it,visited,Stack);
        }
    }
    Stack.push(v);
}
void Graph:: topologicalSort(){
    stack<int> Stack;
    bool visited[V];
    memset(visited,0,sizeof(visited));
    for(int i = 0;i<V;i++){
        if(visited[i] == 0){
            topologicalSortUtil(i,visited,Stack);
        }
    }
    while(Stack.empty() == false){
        cout<<Stack.top()<<" ";
        Stack.pop();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();
    return 0;
}
