#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define R 5
#define C 4
using namespace std;
int x[] = {1,1,1};
int y[] = {-1,0,1};
bool isValid(int i,int j){
    if(i<R and i>=0 and j<C and j>=0){
        return true;
    }
    return false;
}
int dp[R][C];
int getPointsUtil(int arr[R][C],int i,int j){
    if(isValid(i,j) == false){
        return INT_MIN;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = INT_MIN;
    for(int k = 0;k<3;k++){
        ans = max(ans,arr[i][j]+getPointsUtil(arr,i+x[k],j+y[k]));
    }
    dp[i][j] = ans;
    return ans;
}
ll getPoints(int arr[R][C]){
    memset(dp,-1,sizeof(dp));
    for(int i = 0;i<R;i++){
        for(int j = i+1;j<C;j++){
            dp[i][j] = INT_MIN;
        }
    }
    dp[R-1][0] = arr[R-1][0];
    for(int i = 0;i<R;i++){
        for(int j = 0;j<=i;j++){
            dp[i][j] = getPointsUtil(arr,i,j);
        }
    }
    return dp[0][0];
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[R][C] = {{3, 6, 8, 2},
                     {5, 2, 4, 3},
                     {1, 1, 20, 10},
                     {1, 1, 20, 10},
                     {1, 1, 20, 10},
                    };
    cout<<getPoints(arr)<<endl;
    return 0;
}
