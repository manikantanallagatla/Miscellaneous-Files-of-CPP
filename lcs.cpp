#include<bits/stdc++.h>
#include<cstring>
#include<map>
#define ll long long int
using namespace std;
ll lcs(ll array[],ll n){
    ll dp[n];
    fill(dp,dp+n,1);
    for(ll i = 1;i<n;i++){
        for(ll j = 0;j<i;j++){
            if(array[i]>array[j]){
                if(dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
        }
    }
    ll maximum = 0;
    for(ll i = 0;i<n;i++){
        if(maximum<dp[i]){
            maximum = dp[i];
        }
    }
    return maximum;
}
int main()
{
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll array[n];
    for(ll i = 0;i<n;i++){
        cin>>array[i];
    }
    cout<<lcs(array,n)<<endl;
}
