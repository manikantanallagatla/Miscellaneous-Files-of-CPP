#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define INF INT_MAX
#define N 4
using namespace std;
bool isValid(int i,int j){
    if(i<N and i>=0 and j<N and j>=0){
        return true;
    }
    return false;
}
int minCostUtil(int cost[][N],int dp[][N],int i,int j){
    if(isValid(i,j) == false){
        return INT_MAX;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j] = cost[i][j];
    for(int k = i+1;k<j;k++){
        if(dp[i][j]>(minCostUtil(cost,dp,i,k)+minCostUtil(cost,dp,k,j))){
            dp[i][j]=(dp[i][k]+dp[k][j]);
        }
    }
    return dp[i][j];
}
int minCost(int cost[][N]){
    int dp[N][N];
    memset(dp,-1,sizeof(dp));
    for(int i = 0;i<N-1;i++){
        dp[i][i+1] = cost[i][i+1];
    }

    return minCostUtil(cost,dp,0,N-1);
}
int main(){
    ios_base::sync_with_stdio(false);
    int cost[N][N] = { {0, 15, 80, 90},
                      {INF, 0, 40, 50},
                      {INF, INF, 0, 70},
                      {INF, INF, INF, 0}
                    };
    cout << "The Minimum cost to reach station "
          << N << " is " << minCost(cost);
    return 0;
}
