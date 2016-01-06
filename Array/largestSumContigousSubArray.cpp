#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int maxSubArraySum(int a[],int n){
    int dp[n][n];
    int maximum= INT_MIN;
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            if(i == j){
                dp[i][j] = a[i];
            }else{
                dp[i][j] = dp[i][j-1]+a[j];
            }
                    if(maximum<=dp[i][j]){
                        maximum = dp[i][j];
                    }
        }
    }
    return maximum;
}
int main(){
    ios_base::sync_with_stdio(false);
    int a[] = {-2, -3, -4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is \n" << max_sum;
    return 0;
}
