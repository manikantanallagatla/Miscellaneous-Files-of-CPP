#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define V 5
using namespace std;
bool isSafe(bool graph[V][V], bool isVisited[V],vector<int> answer){
    if(answer.size()>=V){
        return true;
    }
    int temp = answer[answer.size()-1];
    for(int i = 0;i<answer.size()-1;i++){
        if(answer[i] == temp){
            return 0;
        }
    }
    return 1;
}
bool hamCycleUtil(bool graph[V][V],bool isVisited[V],vector<int> answer){

    if(answer.size()>=V){
            if(graph[answer[answer.size()-1]][0] ==1){
                cout<<"Printing path: "<<endl;
            for(int i = 0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }cout<<endl;
        return true;
            }
        return false;
    }
    if(isSafe(graph,isVisited,answer) == true){
        if(answer.size() == V){
            return true;
        }
        for(int k = 0;k<V;k++){
            if(graph[answer[answer.size()-1]][k] ==1 and isVisited[k] == 0){
                answer.push_back(k);
                isVisited[k] = 1;
                if(hamCycleUtil(graph,isVisited,answer) == true){
                    return true;
                }
                isVisited[k] = 0;
                answer.pop_back();
                }
        }
        return false;
    }else{
        //isVisited[answer[answer.size()-1]] = 0;
        //answer.pop_back();
        return false;
    }
}
bool hamCycle(bool graph[V][V]){
    bool isVisited[V];
    memset(isVisited,false,sizeof(isVisited));
    vector<int> answer;
    answer.push_back(0);
    isVisited[0] = 1;
    bool dummy = hamCycleUtil(graph,isVisited,answer);
    if(dummy == 0){
        cout<<"No cycle found!!"<<endl;
    }
    return dummy;
}
int main(){
    ios_base::sync_with_stdio(false);
    /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)-------(4)    */
    bool graph1[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };

    // Print the solution
    hamCycle(graph1);
    /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)       (4)    */
    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                     };

    // Print the solution
    hamCycle(graph2);

    return 0;
}
