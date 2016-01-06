#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define N 4
using namespace std;
bool isValid(int i,int j){
    if(i>=0 and j>=0 and i<N and j<N){
        return true;
    }
    return false;
}
int x[] = {1,0};
int y[] = {0,1};
bool solveMazeUtil(int maze[N][N], bool sol[N][N],int i,int j){
    if(isValid(i,j) == false){
        return false;
    }
    if(i == N-1 and j == N-1){
        return true;
    }
    for(int k = 0;k<2;k++){
        int nextx = i+x[k];
        int nexty = j+y[k];
        if(isValid(nextx,nexty) == true and maze[nextx][nexty] == 1){
            sol[nextx][nexty] =1;
            bool temp = solveMazeUtil(maze,sol,nextx,nexty);
            if(temp == true){
                return true;
            }
            sol[nextx][nexty] = 0;
        }
    }
    return false;
}
bool solveMaze(int maze[N][N]){
    bool sol[N][N];
    memset(sol,0,sizeof(sol));
    sol[0][0] = 1;
    bool dummy = solveMazeUtil(maze,sol,0,0);
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cout<<sol[i][j]<<" ";
        }cout<<endl;
    }
    return dummy;
}
int main(){
    ios_base::sync_with_stdio(false);
    int maze[N][N]  =
        { {1, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 1, 0},
        {1, 1, 1, 1}
    };

    solveMaze(maze);
    return 0;
}
