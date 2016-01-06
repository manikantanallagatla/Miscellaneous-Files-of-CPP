#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;

ll getLcs(string a,string b,ll m,ll n){
    ll lcs[m+1][n+1];
    string ans[m+1][n+1];
    for(ll i = 0;i<m+1;i++){
        for(ll j =0;j<n+1;j++){
            ans[i][j] = "";
        }
    }
    for(ll i = 0;i<m+1;i++){
        lcs[i][0] = 0;
    }
    for(ll i = 0;i<n+1;i++){
        lcs[0][i] = 0;
    }
    for(ll i = 1;i<m+1;i++){
        for(ll j = 1;j<n+1;j++){
            if(a[i-1] == b[j-1]){
                lcs[i][j] = 1+(lcs[i-1][j-1]);

                ans[i][j] = ans[i-1][j-1]+" "+a[i-1];
            }else{
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
                if(lcs[i-1][j]>lcs[i][j-1]){
                    ans[i][j] = ans[i][j]+" "+ans[i-1][j];
                }else{
                    ans[i][j] = ans[i][j]+" "+ans[i][j-1];
                }
            }
        }
    }
    //cout<<"LCS is "<<ans[m][n]<<endl;
    return lcs[m][n];
    }
int main(){
    ios_base::sync_with_stdio(false);
    string a,b;
    cout<<"Enter the strings:"<<endl;
    cin>>a>>b;
    //cout<<"LCS is "<<getLcs(a,b,a.size(),b.size())<<endl;
    ll x;
    if(a.size()>b.size()){
        x = a.size()-b.size();
    }else{
        x = b.size()-a.size();
    }
    cout<<"Number of operations is "<<(a.size()-getLcs(a,b,a.size(),b.size()))+x<<endl;
    return 0;
}
