#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void printNGE(int arr[],int n){
    int dp[n];
    dp[n-1] = -1;
    for(int i = n-2;i>=0;i--){
        if(arr[i]>dp[i+1] and arr[i]>arr[i+1]){
            dp[i] = -1;
        }else{
            if(arr[i]<dp[i+1] and arr[i]>arr[i+1]){
                dp[i] = dp[i+1];
            }else{
                if(arr[i]>dp[i+1] and arr[i]<arr[i+1]){
                dp[i] = arr[i+1];
            }else{
                int l1 = arr[i+1]-arr[i];
                int l2 = dp[i+1]-arr[i];
                if(l1<l2){
                    dp[i] = arr[i+1];
                }else{
                    dp[i] = dp[i+1];
                }
            }
            }
        }
    }
    for(int i = 0;i<n;i++){
        cout<<dp[i]<<" ";
    }cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[]= {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}
