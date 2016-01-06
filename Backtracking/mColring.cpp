#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define V 4
using namespace std;
bool isSafe(bool graph[V][V],int colors[V],int m,int vertex){
    for(int i = 0;i<vertex;i++){
        if(graph[i][vertex] ==1){
            if(colors[i] == colors[vertex]){
                return false;
            }
        }
        if(graph[vertex][i] ==1){
            if(colors[i] == colors[vertex]){
                return false;
            }
        }
    }
    return true;
}
bool graphColoringUtil(bool graph[V][V],int colors[V],int m,int vertex, int colo){
    if(vertex<V){
        if(isSafe(graph,colors,m,vertex) == true){
            colors[vertex+1] = 1;
            return graphColoringUtil(graph,colors,m,vertex+1,0);
        }else{
            if(colo<m){
                colors[vertex]+=1;
                return graphColoringUtil(graph,colors,m,vertex,colors[vertex]);
            }else{
                if(vertex>0){
                    colors[vertex] = -1;
                    colors[vertex-1]+=1;
                    return graphColoringUtil(graph,colors,m,vertex-1,colors[vertex-1]);
                }else{
                    colors[0] = -1;
                    return false;
                }
            }
        }
    }else{
        return true;
    }
}
bool graphColoring(bool graph[V][V], int m){
    int colors[V];
    memset(colors,-1,sizeof(colors));
    // assigning colors from 1 to m
    colors[0] = 1;
    bool dummy = graphColoringUtil(graph,colors,m,0,1);
    for(int i = 0;i<V;i++){
        cout<<colors[i]<<" ";
    }cout<<endl;
    return dummy;
}
int main(){
    ios_base::sync_with_stdio(false);
    bool graph[V][V] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3; // Number of colors
    cout<<graphColoring (graph, m);
    return 0;
}
