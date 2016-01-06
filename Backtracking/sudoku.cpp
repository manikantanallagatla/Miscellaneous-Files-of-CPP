#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
#define N 9
bool isSafe(int grid[N][N], int i,int j){
    for(int row = 0;row<i;row++){
        if(grid[row][j] == grid[i][j]){
            return 0;
        }
    }
    for(int col = 0;col<j;col++){
        if(grid[i][col] == grid[i][j]){
            return 0;
        }
    }
    return 1;
}
void getNextUnassigned(int grid[N][N], int i,int j,int &row,int &col){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(grid[i][j] == 0){
                row = i;
                col = j;
                return;
            }
        }
    }
}
bool SolveSudokuUtil(int grid[N][N], int i,int j){
    if(isSafe(grid,i,j) == true){
        if(i >= N-1 and j >= N-1){
            return true;
        }
        int row;
        int col;
        getNextUnassigned(grid,i,j,row,col);

                    for(int k = 1;k<=9;k++){
                        grid[row][col] = k;
                        bool dummy = SolveSudokuUtil(grid,row,col);
                        if(dummy == true){
                            return true;
                        }
                        grid[row][col] = 0;
                    }
                    grid[row][col] = 0;
                    return 0;

    }else{
        return false;
    }
}
bool SolveSudoku(int grid[N][N]){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(grid[i][j] == 0){
                for(int k = 1;k<=9;k++){
                    grid[i][j] = k;
                    bool dummy = SolveSudokuUtil(grid,i,j);
                    if(dummy == true){
                        return true;
                    }
                }
                grid[i][j] = 0;
                return false;
            }
        }
    }
}
void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
       for (int col = 0; col < N; col++)
             printf("%2d", grid[row][col]);
        printf("\n");
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int grid[N][N] = {{3, 0, 6, 5, 7, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (SolveSudoku(grid) == true)
          printGrid(grid);
    else
         printf("No solution exists");

    return 0;
}
