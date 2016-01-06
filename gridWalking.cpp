#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
bool isValid(int x,int y,int dx,int dy){
    if(x>=0 and x<dx and y>=0 and y<dy){
        return 1;
    }
    return 0;
}
int numberWays(int x,int y,int dx,int dy,int m){
    int dp[dx][dy][m+1];
    memset(dp,0,sizeof(dp));
    for(int i = 0;i<dx;i++){
        for(int j = 0;j<dy;j++){
            dp[i][j][0] = 1;
        }
    }
    /*for(int i = 0;i<dx;i++){
        for(int j = 0;j<dy;j++){
            for(int k = 1;k<=m;k++){
                if(isValid(i-1,j,dx,dy)){
                    dp[i][j][k]+=dp[i-1][j][k-1];
                }
                if(isValid(i+1,j,dx,dy)){
                    dp[i][j][k]+=dp[i+1][j][k-1];
                }
                if(isValid(i,j-1,dx,dy)){
                    dp[i][j][k]+=dp[i][j-1][k-1];
                }
                if(isValid(i,j+1,dx,dy)){
                    dp[i][j][k]+=dp[i][j+1][k-1];
                }
            }
        }
    }*/
    for(int k = 1;k<=m;k++){
        for(int i = 0;i<dx;i++){
            for(int j = 0;j<dy;j++){
                 if(isValid(i-1,j,dx,dy)){
                    dp[i][j][k]+=dp[i-1][j][k-1];
                }
                if(isValid(i+1,j,dx,dy)){
                    dp[i][j][k]+=dp[i+1][j][k-1];
                }
                if(isValid(i,j-1,dx,dy)){
                    dp[i][j][k]+=dp[i][j-1][k-1];
                }
                if(isValid(i,j+1,dx,dy)){
                    dp[i][j][k]+=dp[i][j+1][k-1];
                }
            }
        }
    }
    /*for(int i = 0;i<dx;i++){
        for(int j = 0;j<dy;j++){
            cout<<dp[i][j][2]<<" ";// = 1;
        }cout<<endl;
    }*/
    return dp[x][y][m];
}
int main(){
    ios_base::sync_with_stdio(false);
    int m = 1;
    int x = 6;
    int y = 6;
    int dx = 12;
    int dy = 12;
    cout<<"Number of ways are: "<<numberWays(x,y,dx,dy,m)<<endl;
    return 0;
}

