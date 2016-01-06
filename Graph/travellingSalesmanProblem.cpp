#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define V 5
using namespace std;
void swap(int *a,int *b){
    int c =*a;
    *a = *b;
    *b = c;
}
int minIndex(int i,bool visited[V],int graph[V][V]){
    int minimum = INT_MAX;
    int mIndex = -1;
    for(int j = 0;j<V;j++){
        if(visited[j] ==0){
            if(minimum>=graph[i][j]){
                minimum = graph[i][j];
                mIndex = j;
            }
        }
    }
    return mIndex;
}
int TSPUtil(int graph[V][V],int start,int i,bool visited[V]){
    //cout<<i<<" ";
    int sum = 0;
    visited[i] = 1;
        int u = minIndex(i,visited,graph);
        if(u!=-1){
            sum+=graph[i][u];
            sum+=TSPUtil(graph,start,u,visited);
        }else{
            sum+=graph[i][start];
        }
        return sum;
}
void TSP(int graph[V][V]){
    int minimumCost = INT_MAX;
    int startingVertex  = 0;
    bool visited[V];
    for(int i = 0;i<V;i++){
        for(int i = 0;i<V;i++){
            visited[i] = 0;
        }
        int dummy = TSPUtil(graph,i,i,visited);
        if(dummy<=minimumCost){
            minimumCost = dummy;
            startingVertex = i;
        }
    }
    cout<<"Start From vertex: "<<startingVertex<<endl;
    cout<<"Minimum Cost is: "<<minimumCost<<endl;

    /*for(int i = 0;i<V;i++){
            visited[i] = 0;
        }
    cout<<TSPUtil(graph,3,3,visited);*/
}
int main(){
    ios_base::sync_with_stdio(false);
    int graph[V][V] =
                    {{0,12,10,19,8},
                    {12,0,3,7,2},
                    {10,3,0,6,20},
                    {19,7,6,0,4},
                    {8,2,20,4,0},
                    };
    TSP(graph);
    return 0;
}

