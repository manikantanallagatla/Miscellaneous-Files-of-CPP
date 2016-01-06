#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
class Graph{
    int V;
    list<int> *adj;
    bool isCycleUtil(int v, bool visited[],bool *rs);
public:
    Graph(int V);
    void addEdge(int v, int w);   // to add an edge to graph
    bool isCycle();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v);
}
bool Graph::isCycleUtil(int v,bool visited[],bool recStack[]){
    if(visited[v] == false){
        visited[v] = true;
        recStack[v] = true;
        list<int>::iterator it;
        for(it = adj[v].begin();it!=adj[v].end();it++){
            if(visited[*it] == false and isCycleUtil(*it,visited,recStack) == true){
                return true;
            }else{
                if(recStack[*it] == true){
                    return true;
                }
            }
        }
    }
    recStack[v] = false;
    return false;
}
bool Graph::isCycle(){
    bool visited[V];
    memset(visited,0,sizeof(visited));
    bool recStack[V];
    memset(recStack,0,sizeof(recStack));
    for(int i = 0;i<V;i++){
        if(isCycleUtil(i,visited,recStack)){
            return true;
        }
    }
    return false;
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

    if(g.isCycle())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
