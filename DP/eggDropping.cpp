#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int eggDrop(int n, int k){

    ll ans[n+1][k+1];
    for(ll i = 1;i<n+1;i++){
        ans[i][0] = 0;
        ans[i][1] = 1;
    }
    for(ll i = 1;i<k+1;i++){
        ans[1][i] = i;
        //ans[0][k] = INT_MAX;
    }
    for(ll i = 2;i<n+1;i++){
        for(ll j = 2;j<k+1;j++){
            ll minimum = INT_MAX;
            for(ll dummy = 1;dummy<=j;dummy++){
                ll x = 1+max(ans[i-1][dummy-1],ans[i][j-dummy]);
                if(minimum>x){
                    minimum = x;
                }
            }
            ans[i][j] = minimum;
        }
    }
    return ans[n][k];
}
int main(){
    ios_base::sync_with_stdio(false);
    int n = 2, k = 10;
    printf ("\nMinimum number of trials in worst case with %d eggs and "
             "%d floors is %d \n", n, k, eggDrop(n, k));
    return 0;
}
