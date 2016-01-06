#include<iostream>
using namespace std;
class AdjacencyMatrix{
	private:
		int n;
		int **adj;
		bool *visited;
	public:
		AdjacencyMatrix(int n){
			this->n = n;
			visited = new bool[n];
			adj = new int *[n];
			for(int i = 0; i<n;i++){
				adj[i] = new int[n];
				for(int j = 0;j<n;j++){
					adj[i][j] = 0;
				}
			}
		}
		void add_edge(int origin,int destination){
			if(origin>n || origin<0 destination>n || origin<0){
				cout<<"Not Possible!"<<endl;
			}
			else{
				adj[origin-1][destinatioj-1] = 1;
			}
		}
		void display(){
			for(int i = 0;i<n;i++){
				for(int j = 0; j<n;j++){
					cout<<adj[i][j]<<" ";
				}
				cout<<endl;
			}
		}
};
int main(){
	int nodes, max_edges, origin, destin;
    cout<<"Enter number of nodes: ";
    cin>>nodes;
    AdjacencyMatrix am(nodes);
    max_edges = nodes * (nodes - 1);
    for (int i = 0; i < max_edges; i++)
    {
        cout<<"Enter edge (-1 -1 to exit): ";
        cin>>origin>>destin;
        if((origin == -1) && (destin == -1))
            break;
        am.add_edge(origin, destin);
    }
    am.display();
    return 0;
}
