#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define V 4
using namespace std;
int countWalks(int graph[V][V],int u,int v,int k){
    if(k == 1){
        if(graph[u][v] ==1){
            return 1;
        }
        return 0;
    }
    int sum = 0;
    for(int i = 0;i<V;i++){
        if(graph[i][v] ==1){
            sum+=countWalks(graph,u,i,k-1);
        }
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    /* Let us create the graph shown in above diagram*/
     int graph[V][V] = { {0, 1, 1, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 0}
                      };
    int u = 0, v = 3, k = 2;
    cout << countWalks(graph, u, v, k);
    return 0;
}
