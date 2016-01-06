#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define V 4
using namespace std;
int minimumDistance(int graph[][V],bool placed[V]){
    int dist[V];
    for(int i = 0;i<V;i++){
        int minimum = INT_MAX;
        for(int j = 0;j<V;j++){
            if(placed[j] == 1 and minimum>=graph[i][j]){
                minimum = graph[i][j];
            }
        }
        dist[i] = minimum;
    }
    cout<< " distance vector is "<<endl;
    for(int i = 0;i<V;i++){
        cout<<dist[i]<< " ";
    }cout<<endl;
    int maximum = INT_MIN;
    for(int i = 0;i<V;i++){
        if(dist[i]>=maximum){
            maximum = dist[i];
        }
    }
    return maximum;
}
int farthestCity(int graph[][V],bool placed[V]){
    int dist[V];
    for(int i = 0;i<V;i++){
        int minimum = INT_MAX;
        for(int j = 0;j<V;j++){
            if(placed[j] == 1 and minimum>=graph[i][j]){
                minimum = graph[i][j];
            }
        }
        dist[i] = minimum;
    }
    int maximum = INT_MIN;
    int maxIndex;
    for(int i = 0;i<V;i++){
        if(dist[i]>=maximum){
            maximum = dist[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}
int getAtmUtil(int graph[][V],int k,bool placed[V]){
    if(k == 0){
        int getMinimumDistance = minimumDistance(graph,placed);
        return getMinimumDistance;
    }
    int getFarthestCity = farthestCity(graph,placed);
    placed[getFarthestCity] = 1;
    return getAtmUtil(graph,k-1,placed);
}
int getAtm(int graph[][V],int k){
    int arr[k];
    bool placed[V];
    int minimum = INT_MAX;
    memset(placed,0,sizeof(placed));
    for(int i = 0;i<V;i++){
            memset(placed,0,sizeof(placed));
        placed[i] =  1;
        int dummy = getAtmUtil(graph,k-1,placed);
        cout<<"Placing first ATM at "<<i<<" and got dummy as "<<dummy<<endl;
        if(dummy<=minimum){
            minimum=  dummy;
            int index=  0;
            for(int k = 0;k<V;k++){
                if(placed[k] ==1){
                    arr[index] = k;
                    index++;
                }
            }
        }
        placed[i] = 0;
    }
    cout<<"ATMs placed at ";
    for(int i = 0;i<k;i++){
        cout<<arr[i]<< " ";
    }cout<<endl;
    return minimum;
}
int main(){
    ios_base::sync_with_stdio(false);
    int graph[V][V] = {
    {0, 10,7,6},
    {10,0,8,5},
    {7,8,0,2},
    {6,5,2,0}
    };
    int k =1;
    cout<<"Minimum Distance is "<<getAtm(graph,k)<<endl;
    return 0;
}
