#include<bits/stdc++.h>
#define ll long long int
using namespace std;
//vector<bool> visited;
vector< vector <int> > graph;
int n;
void dfs(int u,bool *visited){
    visited[u] = true;
    cout<<u+1<<" ";
    //vector<int>:: iterator it = graph[u].begin
    for(int i = 0;i<graph[u].size();i++){
        if(visited[graph[u][i]] == false){
            dfs(graph[u][i], visited);
        }
    }
}
void dfs_util(int u){
    bool *visited1 = new bool[n];
    fill(visited1,visited1+n,false);
    dfs(u,visited1);
}
void bfs(int u){
    bool *visited1 = new bool[n];
    fill(visited1,visited1+n,false);
    list<int> queue1;
    visited1[u] = true;
    queue1.push_back(u);
    list<int> :: iterator it;
    while(queue1.empty() == false){
        u = queue1.front();
        cout<<u+1<<" ";
        queue1.pop_front();
        for(int i = 0;i<graph[u].size();i++){
            if(visited1[graph[u][i]] == false){
            queue1.push_back(graph[u][i]);
            visited1[graph[u][i]] = true;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int dummy = 1;
    while(t--){
            cout<<"graph "<<dummy<<endl;
            dummy++;
        /*int m;
        //graph = vector< vector < int > > (n);

        for(int i = 0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i = 0;i<n;i++){
            visited.push_back(false);
        }
        dfs_util(2);cout<<endl;
        bfs(3);cout<<endl;*/
        cin>>n;
        graph.erase(graph.begin(),graph.end());
        for(int i = 0;i<n;i++){
            vector<int> temp;
            temp.push_back(i);
            graph.push_back(temp);
        }
        for(int i = 0;i<n;i++){
            int start;
            cin>>start;
            start--;
            int numb;
            cin>>numb;
            for(int j = 0;j<numb;j++){
                int v;
                cin>>v;
                v--;
                graph[start].push_back(v);
            }
        }
        int start,searching;
        cin>>start>>searching;
        while(start != 0 || searching!=0){
            if(start == 0 && searching == 0){
                break;
            }
                start--;
            if(searching == 0){
                dfs_util(start);
                cout<<endl;
            }else{
                bfs(start);
                cout<<endl;
            }
            cin>>start>>searching;
        }
    }
    return 0;
}
