#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define V 4
#define INF INT_MAX
using namespace std;
void floydWarshell (int graph[][V]){
    int dist[V][V];
    for(int i = 0;i<V;i++){
        for(int j = 0;j<V;j++){
            dist[i][j] = graph[i][j];
        }
    }
    for(int k = 0;k<V;k++){
        for(int i = 0;i<V;i++){
            for(int j = 0;j<V;j++){
                if(dist[i][j]>(dist[i][k]+dist[k][j]) and dist[i][k]!=INF and dist[k][j]!=INF){
                    dist[i][j]=(dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    for(int i = 0;i<V;i++){
        for(int j = 0;j<V;j++){
            if(dist[i][j] == INF or dist[i][j] == INT_MAX){
                cout<<"INF"<<" ";
            }else{
            cout<<dist[i][j]<<" ";
            }
        }cout<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };

    // Print the solution
    floydWarshell(graph);
    return 0;
}
