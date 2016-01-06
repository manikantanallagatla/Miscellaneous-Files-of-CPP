#include <iostream>
#include<stack>
#include<list>
using namespace std;

class Graph{
    int v;
    list<int> *adj;
    public:
    Graph(int v);
    void addEdge(int u,int v);
    void DFS(int s,bool visited[]);
    void topologicalUtil(int i,bool visited[],stack<int> &Stack);
    void topologicalSort();
};

Graph::Graph(int v){
    this->v = v;
    adj = new list<int> [v];
}
void Graph::addEdge(int u,int v){
    adj[u].push_back(v);
}
void Graph::topologicalUtil(int i,bool visited[],stack<int> &Stack){
	visited[i]  =true;
	list<int>::iterator it;
	for(it = adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it]){
			topologicalUtil(*it,visited,Stack);
		}
	}
	Stack.push(i);
}
void Graph::topologicalSort(){
    //stack.push_back(s);
    stack<int> Stack;
    bool visited[v];
    for(int i = 0;i<v;i++){
    	visited[i] = false;
    }
    for(int i = 0;i<v;i++){
    	if(visited[i] == false){
    		topologicalUtil(i,visited,Stack);
    	}
    }
    cout<<Stack.size()<<endl;
    while(Stack.empty() == false){
    	cout<<Stack.top()<<" ";
    	Stack.pop();
    }
}
int main() {
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

