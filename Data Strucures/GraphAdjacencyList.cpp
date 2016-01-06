#include<iostream>
using namespace std;
struct AdjListNode{
	int dest;
	AdjListNode * next;
};
struct AdjList{
	AdjListNode *head;
};
class graph{
	private:
		int v;
		AdjList *array;
	public:
		graph(int v){
			this->v = v;
			array = new AdjList[v];
			for(int i =0 ;i<v;i++){
				array[i].head = NULL;
			}
		}
		AdjListNode *newAdjListNode(int dest){
			AdjListNode *newNode = new AdjListNode;
			newNode->dest = dest;
			newNode->next = NULL;
			return newNode;
		}
		void addEdge(int src,int dest){
			AdjListNode *newNode = newAdjListNode(dest);
			newNode->next = array[src].head;
			array[src].head = newNode;
			newNode = newAdjListNode(src);
			newNode->next = array[dest].head;
			array[dest].head = newNode;
		}
		void printGraph(){
			for(int i = 0;i<v;i++){
				AdjListNode *temp = array[i].head;
				cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
				while(temp){
					cout<<"->"<<temp->dest;
					temp = temp->next;
				}
				cout<<endl;
			}
		}
};
int main(){
	graph gh(5);
    gh.addEdge(0, 1);
    gh.addEdge(0, 4);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
    gh.addEdge(1, 4);
    gh.addEdge(2, 3);
    gh.addEdge(3, 4);
 
    // print the adjacency list representation of the above graph
    gh.printGraph();
 
    return 0;
}
