#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
ll C(ll n,ll k){
    ll ans[n+1][k+1];
    for(ll i = 0;i<n+1;i++){
        for(ll j = 0;j<k+1;j++){
            if(j==0 or j==i){
                ans[i][j] = 1;
            }
            else
            ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
        }
    }
    return ans[n][k];
}
int main(){
    ios_base::sync_with_stdio(false);
    ll n,k;
    cout<<"Enter n,k: "<<endl;
    cin>>n>>k;
    cout<<C(n,k)<<endl;
    return 0;
}
