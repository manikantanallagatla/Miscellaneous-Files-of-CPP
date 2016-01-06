#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int getMinSquares(int n){
    int *dp = new int[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 4;i<=n;i++){
        ll ans = INT_MAX;
        for(int j = 1;j*j<=(i);j++){
            int k = i-(j*j);
            ll temp = 1+dp[k];
            if(temp<ans){
                ans = temp;
            }
        }
        dp[i] = ans;
    }
    ll ans = dp[n];
    delete []dp;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cout << getMinSquares(6);
    return 0;
    return 0;
}
