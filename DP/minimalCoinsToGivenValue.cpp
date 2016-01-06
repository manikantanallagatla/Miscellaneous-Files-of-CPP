#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
ll minCoins(int arr[],int m,int n){
    ll table[n+1];
    fill(table,table+n+1,INT_MAX);
    table[0] = 0;
    for(int i = 1;i<=n;i++){
        ll ans = INT_MAX;
        for(int j = 0;j<m;j++){
            ll temp = i-arr[j];
            if(temp>=0){
                ll x = table[temp]+1;
                if(ans>x){
                    ans = x;
                }
            }
        }
        table[i] = ans;
    }
    return table[n];
}
int main(){
    ios_base::sync_with_stdio(false);
    int coins[] =  {9, 6, 5, 1};
    int m = sizeof(coins)/sizeof(coins[0]);
    sort(coins,coins+m);
    reverse(coins,coins+m);
    int V = 11;
    cout << "Minimum coins required is "
         << minCoins(coins, m, V);
    return 0;
}
