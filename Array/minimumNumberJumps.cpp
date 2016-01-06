#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int minJumps(int arr[],int n){
    int dp[n];
    if(arr[n-1]>0){
        dp[n-1] = 1;
    }else{
        dp[n-1] = INT_MAX;
    }
    for(int i = n-2;i>=0;i--){
        if(arr[i]>=(n-i)){
            dp[i] = 1;
        }else{
            int minimum = INT_MAX;
            for(int j = 1;j<=arr[i];j++){
                int dummy = i+j;
                if(dp[dummy]<=minimum){
                    minimum = dp[dummy];
                }
            }
            if(minimum!=INT_MAX){
            dp[i] = 1+minimum;
            }else{
                dp[i] = minimum;
            }
        }
    }
    for(int i =0 ;i<n;i++){
        cout<<dp[i]<<" ";
    }cout<<endl;
    return dp[0];
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[] = {1, 3, 6, 1, 0, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Minimum number of jumps to reach end is %d ", minJumps(arr, n));
    return 0;
}

