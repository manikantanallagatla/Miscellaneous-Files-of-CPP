#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int maxSumIS(int arr[],int n){
    int dp[n];
    for(int i = 0;i<n;i++){
        dp[i] = arr[i];
    }
    for(int i = 1;i<n;i++){
            int maximum = INT_MIN;
        for(int j = 0;j<i;j++){
            if(arr[j]<arr[i]){
                if(dp[j]>=maximum){
                    maximum = dp[j];
                }
            }
        }
        dp[i]+=maximum;
    }
    int maximum = INT_MIN;
    for(int i = 0;i<n;i++){
        if(dp[i]>=maximum){
            maximum = dp[i];
        }
    }
    return maximum;
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[] = {10, 5, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Sum of maximum sum increasing subsequence is %d\n",
           maxSumIS( arr, n ) );
    return 0;
}
