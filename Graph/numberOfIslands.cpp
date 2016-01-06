#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define ROW 5
#define COL 5
using namespace std;
int x[] = {0,0,1,-1,1,1,-1,-1};
int y[] = {1,-1,0,0,-1,1,1,-1};
bool isValid(int i,int j){
    if(i>=0 and i<ROW and j>=0 and j<COL){
        return 1;
    }
    return 0;
}
void countIslandUtil(int M[][COL],bool visited[][COL],int i,int j){
    visited[i][j] = 1;
    for(int k = 0;k<8;k++){
        int i_new = i+x[k];
        int j_new = j+y[k];
        if(isValid(i_new,j_new) ==1 and visited[i_new][j_new] == 0 and M[i_new][j_new] ==1){
            countIslandUtil(M,visited,i_new,j_new);
        }
    }
}
int countIsland(int M[][COL]){
    int sum = 0;
    bool visited[ROW][COL];
    memset(visited,0,sizeof(visited));
    for(int i = 0;i<ROW;i++){
        for(int j = 0;j<COL;j++){
            if(visited[i][j] == 0 and M[i][j] ==1){
                sum++;
                countIslandUtil(M,visited,i,j);
            }
        }
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    int M[][COL]= {
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };

    printf("Number of islands is: %d\n", countIsland(M));

    return 0;
}

