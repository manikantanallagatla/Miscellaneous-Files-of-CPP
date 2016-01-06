#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int maxProfit(int price[], int n){
    if(n<2){
        return 0;
    }
    int dp[n][n];
    int left[n];
    int right[n];
    int max_so_far = INT_MIN;
    for(int j = 0;j<n;j++){
        for(int i = 0;i<j;i++){
            dp[i][j] = price[j]-price[i];
            if(dp[i][j]<0){
                dp[i][j] = 0;
            }
            if(max_so_far<(dp[i][j])){
                max_so_far = dp[i][j];
            }
            if(j-i == 1){
                left[j] = max_so_far;
            }
        }
    }
    max_so_far = INT_MIN;
    for(int i = n-1;i>=0;i--){
        for(int j = n-1;j>i;j--){
            if(max_so_far<(dp[i][j])){
                max_so_far = dp[i][j];
            }
            if(j-i == 1){
                right[j] = max_so_far;
            }
        }
    }
    right[0] = 0;

    int result = INT_MIN;
    for(int i = 1;i<n-2;i++){
        int x = left[i]+right[i+1];
        if(x>result){
            result = x;
        }
    }
    return result;
}
int main(){
    ios_base::sync_with_stdio(false);
    int price[] = {90, 80, 70, 60, 50};
    int n = sizeof(price)/sizeof(price[0]);
    cout << "Maximum Profit = " << maxProfit(price, n);
    return 0;
}
