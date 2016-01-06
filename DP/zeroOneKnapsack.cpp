#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int knapSack(int W, int wt[], int val[], int n){
    ll ans[n+1][W+1];
    for(ll i = 0;i<n+1;i++){
        ans[i][0] = 0;
    }
    for(ll i = 0;i<W+1;i++){
        ans[0][i] = 0;
    }
    for(ll i =1;i<n+1;i++){
        for(ll j = 1;j<W+1;j++){

            ll maximum = 0;
            if(wt[i-1]<=j){
                maximum = ans[i-1][j];
            if((j-wt[i-1])>=0){
                if(maximum<(ans[i-1][j-wt[i-1]]+val[i-1])){
                    maximum = (ans[i-1][j-wt[i-1]] + val[i-1]);
                }
            }}else{
                maximum = ans[i-1][j];
            }
            ans[i][j] = maximum;
        }
    }
    return ans[n][W];
}
int main(){
    ios_base::sync_with_stdio(false);
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}
