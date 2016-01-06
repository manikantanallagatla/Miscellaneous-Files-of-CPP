#include<bits/stdc++.h>
using namespace std;
int count(int array[],int m,int n){
    if(n == 0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(m<=0){
        return 0;
    }
    int dp[n+1][m];
    for(int i = 0;i<m;i++){
        dp[0][i] = 1;
    }
    for(int i = 1;i<n+1;i++){
        for(int j = 0;j<m;j++){
                int x,y;
            if(i-array[j]>=0){
                x =  dp[i-array[j]][j];
            }else{
            x=  0;
            }
            if(j>=1){
                y = dp[i][j-1];
            }else{
            y = 0;
            }
            dp[i][j] = x+y;

        }
    }
    return dp[n][m-1];
}
int main(){
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("%d ", count(arr, m, 4));
    getchar();
    return 0;
}
