#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void printMaxOfMin(int arr[],int n){
    int dp[n][n];
    int maximum = INT_MIN;
    memset(dp,0,sizeof(dp));
    for(int i = 0;i<n;i++){
        if(arr[i]>maximum){
            maximum = arr[i];
        }
        dp[i][i] = arr[i];
    }
    cout<<maximum<<" ";
    for(int k = 1;k<n;k++){
            maximum = INT_MIN;
        for(int i = 0;i<n-k;i++){
            int j = i+k;
            dp[i][j] = min(dp[i][j-1],arr[j]);
            if(dp[i][j]>maximum){
                maximum = dp[i][j];
            }
        }
        cout<<maximum<<" ";
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[] = {10, 20, 30, 50, 10, 70, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    printMaxOfMin(arr, n);
    return 0;
}

