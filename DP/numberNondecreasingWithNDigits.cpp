#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
long long int countNonDecreasing(int n){
    ll dp[10][n+1];
    memset(dp,0,sizeof(dp));
    for(int i = 0;i<10;i++){
        dp[i][1] = 1;
    }
    for(int i = 0;i<10;i++){
        for(int len = 2;len<n+1;len++){
            for(int x = 0;x<=i;x++){
                dp[i][len]+=dp[x][len-1];
            }
        }
    }
    ll count = 0;
    for(int i = 0;i<10;i++){
        count+=(dp[i][n]);
    }
    return count;
}
int main(){
    ios_base::sync_with_stdio(false);
    int n = 3;
    cout << countNonDecreasing(n);
    return 0;
}
