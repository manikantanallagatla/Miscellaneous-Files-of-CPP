#include<bits/stdc++.h>
#include<cstring>
#include<cmath>
#include<map>
#define ll long long int
#define ld long double
using namespace std;
void knapSack(int weights[],int values[],int n,int wt){
    int dp[n+1][wt+1];
    for(int i = 0;i<n+1;i++){
        for(int j = 0;j<wt+1;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }else{
                if(weights[i-1]<=j){
                    dp[i][j] = max(dp[i-1][j],values[i-1]+dp[i-1][j - weights[i-1]]);

                }else{
                    dp[i][j] = dp[i-1][j];
                    }
            }
        }
    }
    cout<<"Hey stupid robber, you can get "<<dp[n][wt]<<"."<<endl;

}


int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int wt,n;
    while(t--){
    cin>>wt>>n;
    int weights[n];
    int values[n];
    for(int i = 0;i<n;i++){
        cin>>weights[i]>>values[i];
    }
    knapSack(weights,values,n,wt);
    }
}
